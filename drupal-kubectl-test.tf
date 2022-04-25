locals {
  image_registry = "teststihlcustomacr.azurecr.io"
  image = "stihl7"
  image_tag = "284"
  server_name = "stihltest.bluepresley.com" # This is also the drupal hostname. NO trailing slash.

}
# pvc
resource "kubectl_manifest" "app_pvc" {
  yaml_body = <<YAML
apiVersion: v1
kind: PersistentVolumeClaim
metadata:
  name: stihl9-pvc
spec:
  accessModes:
    - ReadWriteMany
  #storageClassName: aks-file-share-custom-sc-csi
  storageClassName: azurefile-csi
  resources:
    requests:
      storage: 10Gi
YAML
}

# deployment
resource "kubectl_manifest" "test_drupal" {
  depends_on = [
    kubectl_manifest.drupal_secret,
    module.aks-cluster,
    module.aks-cluster-required-config,
  ]
  yaml_body = <<YAML
apiVersion: apps/v1
kind: Deployment
metadata:
  name: stihl9
spec:
  selector:
    matchLabels:
      app: stihl9
  template:
    metadata:
      labels:
        app: stihl9 
    spec:
      containers:
      - image: ${local.image_registry}/${local.image}:${local.image_tag}
        name: stihl9
        imagePullPolicy: Always
      #- image: drupal:7.89-php7.4-apache-buster
        env:
          # Use secret in real usage
        - name: MYSQL_USER
          valueFrom:
            secretKeyRef:
              name: drupalsecrets
              key: username
        - name: MYSQL_PASSWORD
          valueFrom:
            secretKeyRef:
              name: drupalsecrets
              key: password
        - name: MYSQL_DATABASE
          valueFrom:
            secretKeyRef:
              name: drupalsecrets
              key: database
        - name: DATABASE_HOST
          #value: mariadb
          valueFrom:
            secretKeyRef:
              name: drupalsecrets
              key: host
        - name: DRUPAL_HOSTNAME
          value: https://${local.server_name}
        ports:
        - containerPort: 80
        volumeMounts:
        - name: stihl9-pvc
          mountPath: /web-assets
      volumes:
        - name: stihl9-pvc
          persistentVolumeClaim:
            claimName: stihl9-pvc
YAML
}


#ingress
resource "kubectl_manifest" "test_drupal_ingress" {
  yaml_body = <<YAML
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: stihl9-ingress
  annotations: 
    cert-manager.io/cluster-issuer: letsencrypt-prod 
spec:
  tls:
    - hosts:
      - ${local.server_name}
      # This assumes tls-secret exists and the SSL
      # certificate contains a CN for foo.bar.com
      secretName: stihl9-secret
  ingressClassName: nginx
  rules:
    - host: ${local.server_name}
      http:
        paths:
        - path: /
          pathType: Prefix
          backend:
            # This assumes http-svc exists and routes to healthy endpoints
            service:
              name: stihl9
              port:
                number: 80
  YAML
}


#svc
resource "kubectl_manifest" "test_drupal_svc" {
  yaml_body = <<YAML
apiVersion: v1
kind: Service
metadata:
  name: stihl9
spec:
  ports:
  - port: 80
    protocol: TCP
    targetPort: 80
  selector:
    app: stihl9
  type: ClusterIP
  #type: LoadBalancer
  YAML
}

# secret (credentials for drupal)
resource "kubectl_manifest" "drupal_secret" {
  yaml_body = <<YAML
apiVersion: v1
kind: Secret
metadata:
  name: drupalsecrets
type: kubernetes.io/basic-auth
stringData:
  #username: drupalUser
  username: testadmin
  #password: drupalPass
  password: T3stpwd@12E
  #database: drupal7
  database: ${var.project_name}productiondb
  host: ${module.mysql-flexible-server.fs_db_server_fqdn}
YAML
}

resource "kubectl_manifest" "test_drupal_memcache_deployment" {
  yaml_body = <<YAML
apiVersion: apps/v1
kind: Deployment
metadata:
  name: drupal-memcached-deployment
spec:
  selector:
    matchLabels:
      app: drupal-memcached
  template:
    metadata:
      labels:
        app: drupal-memcached
    spec:
      containers:
      - name: drupal-memcached
        image: memcached
        resources:
          requests:
            memory: "64Mi"
            cpu: "100m"
          limits:
            memory: "128Mi"
            cpu: "500m"
        ports:
        - containerPort: 11211
YAML
}

resource "kubectl_manifest" "test_drupal_memcache_svc" {
  yaml_body = <<YAML
apiVersion: v1
kind: Service
metadata:
  name: drupal-memcached
spec:
  selector:
    app: drupal-memcached
    #app: stihl8
  ports:
  - port: 11211
    targetPort: 11211
  clusterIP: None
YAML
}

# turn off HSTS which conflicts
resource "kubectl_manifest" "hsts_off" {
  yaml_body = <<YAML
apiVersion: v1
data:
  hsts: "false"
kind: ConfigMap
metadata:
  name: ingress-nginx-controller
YAML
}

# TODO docker login secret
# https://registry.terraform.io/providers/hashicorp/kubernetes/latest/docs/resources/secret#username-and-password
/**/