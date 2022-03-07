output "log_analytics_workspace_id" {
    value = "${azurerm_log_analytics_workspace.container_insights.id}"
    description = "Container Insights workspace id to connect products to for monitoring."
}