# ---------------------------------------------------------------------------------------------------------------------
# REQUIRED VERSIONS AND PROVIDERS
# ---------------------------------------------------------------------------------------------------------------------

# Module inherits provider configuration from parent.
# Uncomment and configure for greater specificity.
# terraform {
#  required_providers {
#    source = hashicorp/azurerm
#  }
#}

# ---------------------------------------------------------------------------------------------------------------------
# CREATE AN AZURE CONTAINER REGISTRY FOR IMAGES
# ---------------------------------------------------------------------------------------------------------------------
# The Azure Container Registry
# https://docs.microsoft.com/en-us/cli/azure/acr?view=azure-cli-latest
# https://registry.terraform.io/providers/hashicorp/azurerm/latest/docs/resources/container_registry

resource "azurerm_container_registry" "k8s_acr" {
  name                = var.acr_name
  resource_group_name = var.resource_group_name
  location            = var.location
  sku                 = var.acr_sku
  admin_enabled       = var.acr_admin_enabled

  tags = {
    #environment = var.environment
  }
}

# add the role to the identity the kubernetes cluster was assigned
#resource "azurerm_role_assignment" "cluster_to_acr_permissions" {
#  scope                = azurerm_container_registry.k8s_acr.id
#  role_definition_name = "AcrPull"
#  principal_id         = var.cluster_to_acr_principal_id

#depends_on = [
#  azurerm_container_registry.k8s_acr
#]
#}