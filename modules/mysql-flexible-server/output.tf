
output "fs_db_server_name" {
  value = azurerm_mysql_flexible_server.fs_db.name
}

output "fs_db_server_fqdn" {
  value = azurerm_mysql_flexible_server.fs_db.fqdn
}