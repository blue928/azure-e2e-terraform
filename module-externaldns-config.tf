module "external_dns" {
  depends_on = [
    module.azure-rg,
    module.aks-cluster,
    module.aks-cluster-required-config,
    module.azure-dns,
  ]
  source              = "git::git@github.com:blue928/terraform-azurerm-externaldns-module.git"
  resource_group_name = module.azure-rg.resource_group_name
  # TODO Create a Service Principal module that can feed this data in automatically. 
  #azure_client_secret   = var.azure_client_secret
  #azure_client_id       = var.azure_client_id
  #azure_tenant_id       = var.azure_tenant_id
  #azure_subscription_id = var.azure_subscription_id
  externaldns_namespace = var.externaldns_namespace
  externaldns_domain    = var.externaldns_domain

  # tags = var.tags
}
