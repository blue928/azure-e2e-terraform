# pvc
/*resource "kubectl_manifest" "namespace_pvc" {
  yaml_body = <<YAML
apiVersion: v1
kind: PersistentVolumeClaim
metadata:
  name: stihl7-pvc
spec:
  accessModes:
    - ReadWriteMany
  storageClassName: aks-file-share-custom-sc-csi
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
  name: stihl7
spec:
  selector:
    matchLabels:
      app: stihl7
  template:
    metadata:
      labels:
        app: stihl7 
    spec:
      containers:
      - image: teststihlcustomacr.azurecr.io/stihl7:264
      #- image: drupal:7.89-php7.4-apache-buster
        name: stihl7
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
        ports:
        - containerPort: 80
        volumeMounts:
        - name: stihl7-pvc
          mountPath: /web-assets
      volumes:
        - name: stihl7-pvc
          persistentVolumeClaim:
            claimName: stihl7-pvc
YAML
}


#ingress
resource "kubectl_manifest" "test_drupal_ingress" {
  yaml_body = <<YAML
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: stihl7-ingress
  annotations: 
    cert-manager.io/cluster-issuer: letsencrypt-prod 
spec:
  tls:
    - hosts:
      - test3.bluepresley.com
      # This assumes tls-secret exists and the SSL
      # certificate contains a CN for foo.bar.com
      secretName: test3-secret
  ingressClassName: nginx
  rules:
    - host: test3.bluepresley.com
      http:
        paths:
        - path: /
          pathType: Prefix
          backend:
            # This assumes http-svc exists and routes to healthy endpoints
            service:
              name: stihl7
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
  name: stihl7
spec:
  ports:
  - port: 80
    protocol: TCP
    targetPort: 80
  selector:
    app: stihl7
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
}*/

