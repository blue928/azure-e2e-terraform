module "azure-rg" {
  source                  = "github.com/blue928/azure-rg-terraform-module"
  #resource_group_name     = "${var.project_name}-rg"
  resource_group_name = "existing-rg"
  resource_group_location = var.location
}