# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AKS KUBERNETES PRODUCTION CLUSTER REQUIRED CONFIGURATION
# ---------------------------------------------------------------------------------------------------------------------
module "aks-cluster-required-config" {
  depends_on = [
    #data.azurerm_kubernetes_cluster.default,
    module.aks-cluster,
  ]
  source                         = "github.com/blue928/aks-cluster-required-configuration-terraform-module"
  storage_class_cluster_location = module.azure-rg.resource_group_location # Must be the same for the cluster module. 
  #lets encrypt
  #ingress class
}