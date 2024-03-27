# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AZURE PUBLIC DNS ZONE
# ---------------------------------------------------------------------------------------------------------------------
locals {
  azure_dns_zone = "bluepresley.com"
}

module "azure-dns" {
  source              = "git::git@github.com:blue928/terraform-azurerm-dns-module.git"
  azure_dns_zone      = local.azure_dns_zone
  resource_group_name = module.azure-rg.resource_group_name
}
