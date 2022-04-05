resource "helm_release" "cert-manager" {
  name       = "cert-manager"
  repository = "https://charts.jetstack.io"
  chart      = "cert-manager"
  version    = "1.7.2"

  namespace        = "cert-manager"
  create_namespace = true

  #values = [file("cert-manager-values.yaml")]

  set {
    name  = "installCRDs"
    value = "true"
  }

  depends_on = [
    module.aks-cluster,
    module.aks-cluster-required-config,
  ]

}