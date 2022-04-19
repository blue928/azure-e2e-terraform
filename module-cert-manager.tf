module "cert_manager" {
  depends_on = [
    module.aks-cluster,
    module.aks-cluster-required-config,
    module.external_dns,
  ]
  source                 = "github.com/blue928/terraform-kubernetes-cert-manager"
  cert_manager_email     = var.cert_manager_email
  cert_manager_namespace = "cert-manager"

}