# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AZURE CONTAINER REGISTRY FOR THE CONTAINER IMAGES
# ---------------------------------------------------------------------------------------------------------------------
locals {
  # Name must be unique across all of Azure
  acr_name          = "${var.project_name}acr"
  acr_sku           = "Standard"
  acr_admin_enabled = true
}

module "azure-container-registry" {
  source              = "git::git@github.com:blue928/terraform-azurerm-container-registry-module.git"
  resource_group_name = module.azure-rg.resource_group_name
  location            = module.azure-rg.resource_group_location
  acr_name            = local.acr_name
  acr_sku             = local.acr_sku
  acr_admin_enabled   = local.acr_admin_enabled

  # todo add service principals later
  #cluster_to_acr_principal_id = data.azurerm_kubernetes_cluster.modulebase.kubelet_identity[0].object_id
}
