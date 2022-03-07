# Container Insights AKS Cluster Monitoring monitoring

resource "random_id" "log_analytics_workspace_name_suffix" {
  byte_length = 8
}

resource "azurerm_log_analytics_workspace" "container_insights" {
  # The WorkSpace name has to be unique across the whole of azure, not just the current subscription/tenant.
  name = var.log_analytics_workspace_name
  #name                = "${var.log_analytics_workspace_name}-${random_id.log_analytics_workspace_name_suffix.dec}"
  location            = var.log_analytics_workspace_location
  resource_group_name = var.resource_group_name
  sku                 = var.log_analytics_workspace_sku

  tags = {
    #environment = var.environment
  }
}

resource "azurerm_log_analytics_solution" "container_insights" {
  solution_name       = "ContainerInsights"
  location            = azurerm_log_analytics_workspace.container_insights.location
  resource_group_name = azurerm_log_analytics_workspace.container_insights.resource_group_name
  workspace_resource_id = azurerm_log_analytics_workspace.container_insights.id
  workspace_name        = azurerm_log_analytics_workspace.container_insights.name

  plan {
    publisher = "Microsoft"
    product   = "OMSGallery/ContainerInsights"
  }

  tags = {
    #environment = var.environment
  }
}