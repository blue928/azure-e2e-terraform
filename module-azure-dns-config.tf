# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AZURE PUBLIC DNS ZONE
# ---------------------------------------------------------------------------------------------------------------------
locals {
  azure_dns_zone = "bluepresley.com"
}

module "azure-dns" {
  source              = "github.com/blue928/azure-dns-terraform-module"
  azure_dns_zone      = local.azure_dns_zone
  resource_group_name = module.azure-rg.resource_group_name
}