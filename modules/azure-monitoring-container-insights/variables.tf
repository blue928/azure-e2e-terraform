# Container insights
variable "log_analytics_workspace_name" {
  type    = string
}

# reference https://azure.microsoft.com/global-infrastructure/services/?products=monitor for log analytics available regions
variable "log_analytics_workspace_location" {
  type    = string
}

# refer https://azure.microsoft.com/pricing/details/monitor/ for log analytics pricing 
variable "log_analytics_workspace_sku" {
  type    = string
  default = "PerGB2018"
}

variable "resource_group_name" {
  type = string
}