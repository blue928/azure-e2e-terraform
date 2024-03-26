module "container-insights" {
  source                           = "github.com/blue928/azure-container-insights-terraform-module"
  resource_group_name              = module.azure-rg.resource_group_name
  log_analytics_workspace_location = module.azure-rg.resource_group_location
  log_analytics_workspace_name     = "${var.project_name}-log-analytics-workspace"
}