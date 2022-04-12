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

# After Cert Manager is installed, then install the ClusterIssuer. 
# https://cert-manager.io/docs/configuration/acme/

# TODO - add this to its own file?
resource "kubernetes_manifest" "clusterissuer_letsencrypt_prod" {
  manifest = {
    "apiVersion" = "cert-manager.io/v1"
    "kind"       = "ClusterIssuer"
    "metadata" = {
      "name" = "letsencrypt-prod"
    }
    "spec" = {
      "acme" = {
        # TODO change this email address to a variable
        "email" = "bpresley@theimaginegroup.com"
        "privateKeySecretRef" = {
          "name" = "letsencrypt-prod"
        }
        # TODO change this to a variable, enum between production and staging certificates
        "server" = "https://acme-v02.api.letsencrypt.org/directory"
        "solvers" = [
          {
            "http01" = {
              "ingress" = {
                "class" = "nginx"
              }
            }
          },
        ]
      }
    }
  }
  depends_on = [
    helm_release.cert-manager,
    module.aks-cluster,
  ]
}