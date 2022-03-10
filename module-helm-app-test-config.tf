module "helm-app-module" {
  depends_on = [
    module.aks-cluster,
    module.aks-cluster-required-config,
    module.mysql-flexible-server,
  ]
  source          = "github.com/blue928/helm-app-terraform-module"
  #externaldb_fqdn = "tenfortyone-flexible-server.mysql.database.azure.com"
  externaldb_fqdn         = module.mysql-flexible-server.fs_db_server_fqdn
  #externaldbprod_database = "${module.mysql-flexible-server.production_db_name}"
  production_db_name = "tenfortyoneproductiondb"
  externaldbprod_user     = "testadmin"
  externaldbprod_password = "T3stpwd@12E"
}