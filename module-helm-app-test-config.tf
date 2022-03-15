module "helm-app-module" {
  depends_on = [
    module.aks-cluster,
    module.aks-cluster-required-config,
    module.mysql-flexible-server,
  ]
  source          = "github.com/blue928/helm-app-terraform-module"
  #externalDatabase_host = "existing-flexible-server.mysql.database.azure.com"
  externalDatabase_host         = module.mysql-flexible-server.fs_db_server_fqdn
  #externaldbprod_database = "${module.mysql-flexible-server.production_db_name}"
  externalDatabase_database = "existingproductiondb"
  externalDatabase_user     = "testadmin"
  externalDatabase_password = "T3stpwd@12E"
  helm_app_name = "existing"
  cluster_namespace = "existing-ns"
}