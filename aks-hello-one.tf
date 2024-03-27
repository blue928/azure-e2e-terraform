locals {
  server_name = "bluepresley.com"
}

resource "kubernetes_manifest" "one" {
  depends_on = [module.aks-cluster]
  for_each   = fileset("${path.module}/aks1", "*.yaml")
  manifest   = yamldecode(file("${path.module}/aks1/${each.value}"))
}


resource "kubernetes_manifest" "one_ingress" {
  depends_on = [module.aks-cluster]
  manifest = yamldecode(<<YAML
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: aks-one-ingress
  namespace: default
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
              name: aks-helloworld-one
              port:
                number: 80
YAML
  )
}
