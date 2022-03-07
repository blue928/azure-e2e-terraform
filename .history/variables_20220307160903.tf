# The project_name variable is the only one that needs to be set. 
# All outher default resource names are auto-generated in the
# locals {} block below. 
variable "project_name" {
  type    = string
  default = "e2etest1"
}

# Default location of all resources created by Terraform. Choose
# a different location if it makes more sense for the project. 
variable "location" {
  type    = string
  default = "eastus"
}

locals {
  default_resource_group_name = "${var.project_name}-rg"
}

# AKS Cluster Module Configuration
locals {
  cluster_name                     = "${var.project_name}-cluster"
  cluster_node_resource_group_name = "${var.project_name}-cluster-nrg"
  cluster_dns_prefix               = "${var.project_name}-cluster-dns-prefix"
}

# Mysql Flexible Server and Database Configuration
locals {
  fs_db_server_sku_name     = "GP_Standard_D2ds_v4"        #"B_Standard_B1s" # see this issue: https://github.com/hashicorp/terraform-provider-azurerm/issues/15538
  fs_db_server_name         = "${var.project_name}-flexible-server"
  fs_db_server_prod_db_name = "${var.project_name}productiondb"
  require_secure_transport  = "OFF"

}