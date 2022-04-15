module "cert_manager" {
  depends_on = [
    module.aks-cluster,
    module.aks-cluster-required-config,
  ]  
  source             = "github.com/blue928/terraform-kubernetes-cert-manager"
  cert_manager_email = var.cert_manager_email
  namespace          = "cert-manager"

}