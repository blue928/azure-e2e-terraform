# Default resource group for all new resources created by Terraform.
# A resource group can be created and managed by Terraform, or if
# a resource group already exists use "data" instead of "resource"
# to let Terraform reference it but not manage its lifecycle. 

resource "azurerm_resource_group" "rg" {
  name     = local.default_resource_group_name
  location = var.location
}