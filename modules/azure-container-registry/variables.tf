variable "acr_name" {
  type        = string
  description = "The name of the ACR registry. Note: This MUST be unique across the whole of Azure"
}

variable "acr_sku" {
  type = string
}

variable "acr_admin_enabled" {
  type = bool
}

variable "location" {
  type = string
}

variable "resource_group_name" {
  type = string
}

#variable "cluster_to_acr_principal_id" {
#  type = string
#}