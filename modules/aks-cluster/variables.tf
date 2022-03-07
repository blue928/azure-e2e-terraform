variable "cluster_name" {
  type = string
}

variable "cluster_location" {
  type = string
}

variable "cluster_resource_group_name" {
  type = string
}

variable "cluster_node_resource_group_name" {
  type = string
}

variable "cluster_dns_prefix" {
  type = string
}

variable "cluster_default_node_pool_vm_size" {
  type        = string
  description = "The virtual machine SKU AKS uses when creating node pools"
}

variable "cluster_default_node_pool_os_disk_size_gb" {
  type        = number
  description = "The disk space size of the default node pool. Cannot be less than 32."
}
variable "cluster_default_node_pool_min_count" {
  default     = 1
  type        = number
  description = "Minimum number of agents in the default node pool"
}
variable "cluster_default_node_pool_max_count" {
  type        = number
  description = "Maximum number of agents in the default node pool"
}

variable "cluster_rbac_enabled" {
  type        = bool
  description = "Whether or not RBAC is enabled"
  #default = false
}

#variable "cluster_oms_agent_log_analytics_workspace_id" {
#  type = string
#  description = "Microsoft enables monitoring by default. Choose an associated ID or one will be created automatically."
#}

# Container insights
variable "log_analytics_workspace_id" {
  type    = string
  description = "ID of the log analytics workspace to connect to for monitoring."
}



### 11-static-ip-address-for-load-balancer.tf 
variable "lb_public_ip_name" {
  default     = "lbPublicIp"
  type        = string
  description = "This is the resource name of the static, public IP address for the Loadbalancer"
}

variable "lb_public_ip_allocation_type" {
  type    = string
  default = "Static"
}

variable "lb_public_ip_sku" {
  type    = string
  default = "Standard"
}