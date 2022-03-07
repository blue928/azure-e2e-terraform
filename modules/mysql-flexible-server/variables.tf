#################################################
# Azure MySQL Flexible Server
#
#################################################
variable "resource_group_name" {
  type = string
}
variable "location" {
  type = string
}

variable "fs_db_server_name" {
  type = string
}

variable "fs_db_server_sku_name" {
  type = string
}

variable "require_secure_transport" {
  type        = string
  description = "Whether client connections to the server are required to use some form of secure transport. When this variable is enabled, the server permits only TCP/IP connections that use SSL, or connections that use a socket file (on Unix) or shared memory (on Windows)."
}

# Database access firewall rules:
# For PRODUCTION, start_ip_address and end_ip_address should
# both be 0.0.0.0 
#
# For TESTING that the terraform scripts work, use a service
# like "What's My IP" to get the publicly accessible IP address
# of your computer. Use that value for both. 
variable "fs_fw_start_ip_address" {
  type = string
}

variable "fs_fw_end_ip_address" {
  type = string
}

variable "fs_db_server_administrator_login" {
  type = string
}

variable "fs_db_server_administrator_password" {
  type = string
}

variable "fs_db_server_backup_retention_days" {
  type = number
}

# Database names
variable "fs_db_server_prod_db_name" {
  type = string
}

## staging and dev dbs are no longer necessary, but adding
## in case there may be a use case I haven't figured out.
variable "fs_db_server_staging_db_name" {
  type    = string
  default = "teststagingdb"
}

variable "fs_db_server_dev_db_name" {
  type    = string
  default = "testdevdb"
}