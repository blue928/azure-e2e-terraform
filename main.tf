terraform {
  required_providers {
    azurerm = {
      source = "hashicorp/azurerm"
    }
  }
  backend "azurerm" {
    resource_group_name  = "terraform-global-state-files"
    storage_account_name = "tfglobalstatefilessa"
    container_name       = "tfstatefilescontainername"
    key                  = "aksclustermoduleci.tfstate"
  }
}

provider "azurerm" {
  features {}
}

# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AZURE MONITORING CONTAINER INSIGHTS SOLUTION
# ---------------------------------------------------------------------------------------------------------------------
locals {
  # This name must be unique across all of Azure, not just this subscription/tenant
  log_analytics_workspace_name = "${var.project_name}-log-analytics-workspace"
}
module "azure-monitoring-container-insights" {
  source = "./modules/azure-monitoring-container-insights"
  resource_group_name = local.default_resource_group_name
  log_analytics_workspace_location = var.location
  log_analytics_workspace_name = local.log_analytics_workspace_name
}


# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AKS KUBERNETES PRODUCTION CLUSTER
# ---------------------------------------------------------------------------------------------------------------------
#locals {
#  log_analytics_workspace_id = data.existing workspace solution
#}

module "aks-cluster" {
  depends_on = [
    module.azure-monitoring-container-insights,
  ]
  source                           = "./modules/aks-cluster"
  cluster_name                     = local.cluster_name
  cluster_resource_group_name      = local.default_resource_group_name
  cluster_node_resource_group_name = local.cluster_node_resource_group_name
  cluster_dns_prefix               = local.cluster_dns_prefix
  cluster_location                 = var.location

  cluster_default_node_pool_vm_size         = "Standard_B2s"
  cluster_default_node_pool_os_disk_size_gb = 32
  cluster_default_node_pool_min_count       = 1
  cluster_default_node_pool_max_count       = 3

  cluster_rbac_enabled = false
  log_analytics_workspace_id = module.azure-monitoring-container-insights.log_analytics_workspace_id
}

# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AKS KUBERNETES PRODUCTION CLUSTER REQUIRED CONFIGURATION
# ---------------------------------------------------------------------------------------------------------------------
module "aks-cluster-required-configuration" {
  source = "./modules/aks-cluster-required-configuration"
  storage_class_cluster_location = var.location # Must be the same for the cluster module. 
}

# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AZURE CONTAINER REGISTRY FOR THE CONTAINER IMAGES
# ---------------------------------------------------------------------------------------------------------------------

locals {
  # Name must be unique across all of Azure
  acr_name          = "${var.project_name}acr"
  acr_sku           = "Basic"
  acr_admin_enabled = false
}

module "azure-container-registry" {
  source              = "./modules/azure-container-registry"
  resource_group_name = local.default_resource_group_name
  location            = var.location
  acr_name            = local.acr_name
  acr_sku             = local.acr_sku
  acr_admin_enabled   = local.acr_admin_enabled

  # todo add service principals later
  # cluster_to_acr_principal_id = data.azurerm_kubernetes_cluster.modulebase.kubelet_identity[0].object_id
}

# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE MYSQL FLEXIBLE SERVER AND PRODUCTION DATABASE
# ---------------------------------------------------------------------------------------------------------------------
module "mysql-flexible-server" {
  source                   = "./modules/mysql-flexible-server"
  resource_group_name      = local.default_resource_group_name
  location                 = var.location
  fs_db_server_name        = local.fs_db_server_name
  fs_db_server_sku_name    = local.fs_db_server_sku_name
  require_secure_transport = local.require_secure_transport

  # Server Administrator Credentials
  # Leave blank for production. They will be auto generated
  # Note: still have to use mysql admin to create individual db users. 
  #  See docs: <todo add docs link>
  fs_db_server_administrator_login    = "testadmin"
  fs_db_server_administrator_password = "T3stpwd@12E"

  # Production database name
  fs_db_server_prod_db_name = local.fs_db_server_prod_db_name

  # Firewall access
  fs_fw_start_ip_address = "0.0.0.0"
  fs_fw_end_ip_address   = "0.0.0.0"

  # Default number of days to store backups.
  # 
  # Note: These are snapshots, not like normal backups. See
  # documentation for details.
  fs_db_server_backup_retention_days = 7
}

# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AZURE PUBLIC DNS ZONE
# ---------------------------------------------------------------------------------------------------------------------
locals {
  azure_dns_zone = "bluepresley.com"
}

module "azure-dns" {
  source              = "./modules/azure-dns"
  azure_dns_zone      = local.azure_dns_zone
  resource_group_name = local.default_resource_group_name
}