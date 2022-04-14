output "az_credentials" {
  value = module.aks-cluster.az_aks_get_credentials
}

output "externalDatabase_host" {
  value = module.mysql-flexible-server.fs_db_server_fqdn
}
  
