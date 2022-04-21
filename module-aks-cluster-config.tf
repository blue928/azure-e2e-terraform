# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AKS KUBERNETES PRODUCTION CLUSTER
# ---------------------------------------------------------------------------------------------------------------------
module "aks-cluster" {
  # TODO clean this up. current config requires DNS server to be deployed first
  depends_on = [
    module.azure-dns,
  ]

  source = "github.com/blue928/terraform-azurerm-aks-cluster-module"

  resource_group_name = module.azure-rg.resource_group_name
  location            = module.azure-rg.resource_group_location
  cluster_name        = "${var.project_name}-cluster"

  #todo update places where default is null
  agents_max_count = 3
  agents_min_count = 1


  #role_based_access_control = false
  log_analytics_workspace_id = module.container-insights.log_analytics_workspace_id

  #attach to acr
  azurerm_container_registry_id = module.azure-container-registry.container_registry_id
}