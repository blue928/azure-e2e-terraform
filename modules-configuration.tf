module "default-rg" {
  source                  = "github.com/blue928/azure-rg-terraform-module"
  resource_group_name     = "${var.project_name}-rg"
  resource_group_location = var.location
}

module "container-insights" {
  source                           = "github.com/blue928/azure-container-insights-terraform-module"
  resource_group_name              = module.default-rg.resource_group_name
  log_analytics_workspace_location = module.default-rg.resource_group_location
  log_analytics_workspace_name     = "${var.project_name}-log-analytics-workspace"
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
  source = "github.com/blue928/azure-container-registry-terraform-module"
  resource_group_name = module.default-rg.resource_group_name
  location            = module.default-rg.resource_group_location
  acr_name            = local.acr_name
  acr_sku             = local.acr_sku
  acr_admin_enabled   = local.acr_admin_enabled

  # todo add service principals later
  # cluster_to_acr_principal_id = data.azurerm_kubernetes_cluster.modulebase.kubelet_identity[0].object_id
}

# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AKS KUBERNETES PRODUCTION CLUSTER
# ---------------------------------------------------------------------------------------------------------------------
module "aks-cluster" {

  source = "github.com/blue928/azure-aks-terraform-module"

  resource_group_name = module.default-rg.resource_group_name
  location            = module.default-rg.resource_group_location
  cluster_name        = "${var.project_name}-cluster"

  #todo update places where default is null
  agents_max_count = 3
  agents_min_count = 1


  #role_based_access_control = false
  log_analytics_workspace_id = module.container-insights.log_analytics_workspace_id
}

# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE AZURE PUBLIC DNS ZONE
# ---------------------------------------------------------------------------------------------------------------------
locals {
  azure_dns_zone = "bluepresley.com"
}

module "azure-dns" {
  source              = "github.com/blue928/azure-dns-terraform-module"
  azure_dns_zone      = local.azure_dns_zone
  resource_group_name = module.default-rg.resource_group_name
}

# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE MYSQL FLEXIBLE SERVER AND PRODUCTION DATABASE
# ---------------------------------------------------------------------------------------------------------------------
locals {
  fs_db_server_sku_name     = "GP_Standard_D2ds_v4" #"B_Standard_B1s" # see this issue: https://github.com/hashicorp/terraform-provider-azurerm/issues/15538
  fs_db_server_name         = "${var.project_name}-flexible-server"
  fs_db_server_prod_db_name = "${var.project_name}productiondb"
  require_secure_transport  = "OFF"
}

module "mysql-flexible-server" {
  source                   = "github.com/blue928/azure-mysql-flexible-server-terraform-module"
  resource_group_name      = module.default-rg.resource_group_name
  location                 = module.default-rg.resource_group_location
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
# DEPLOY THE AKS KUBERNETES PRODUCTION CLUSTER REQUIRED CONFIGURATION
# ---------------------------------------------------------------------------------------------------------------------
module "aks-cluster-required-configuration" {
  source                         = "github.com/blue928/aks-cluster-required-configuration-terraform-module"
  storage_class_cluster_location = module.default-rg.resource_group_location # Must be the same for the cluster module. 
  #lets encrypt
  #ingress class
}