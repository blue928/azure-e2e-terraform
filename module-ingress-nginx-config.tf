# https://docs.microsoft.com/en-us/azure/aks/ingress-static-ip?tabs=azure-cli#ip-and-dns-label

module "ingress-nginx" {
    depends_on = [
        module.azure-rg,
        module.aks-cluster,
        module.aks-cluster-required-config,
        module.azure-dns,
    ]
  source = "github.com/blue928/terraform-azurerm-ingress-nginx-module"
  chart_version = "4.0.19"  
}