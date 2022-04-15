# ---------------------------------------------------------------------------------------------------------------------
# DEPLOY THE MYSQL FLEXIBLE SERVER AND PRODUCTION DATABASE
# ---------------------------------------------------------------------------------------------------------------------
locals {
  #fs_db_server_sku_name     = "GP_Standard_D2ds_v4" #"B_Standard_B1s" # see this issue: https://github.com/hashicorp/terraform-provider-azurerm/issues/15538
  fs_db_server_sku_name     = "B_Standard_B1s"
  fs_db_server_name         = "${var.project_name}-flexible-server"
  fs_db_server_prod_db_name = "${var.project_name}productiondb"
  require_secure_transport  = "OFF"
}

module "mysql-flexible-server" {
  source                   = "github.com/blue928/azure-mysql-flexible-server-terraform-module"
  resource_group_name      = module.azure-rg.resource_group_name
  location                 = module.azure-rg.resource_group_location
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
  fs_db_server_prod_db_name = "${var.project_name}productiondb"

  # Firewall access
  #fs_fw_start_ip_address = "98.24.104.193"
  #fs_fw_end_ip_address   = "98.24.104.193"
   fs_fw_start_ip_address = "0.0.0.0"
  fs_fw_end_ip_address   = "0.0.0.0"

  # Default number of days to store backups.
  # 
  # Note: These are snapshots, not like normal backups. See
  # documentation for details.
  fs_db_server_backup_retention_days = 7
}