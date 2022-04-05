module "helm-app-module" {
  depends_on = [
    module.aks-cluster,
    module.aks-cluster-required-config,
    module.mysql-flexible-server,
  ]
  source                    = "github.com/blue928/helm-app-terraform-module"
  externalDatabase_host     = module.mysql-flexible-server.fs_db_server_fqdn
  externalDatabase_database = "stihlclonetestproductiondb"
  externalDatabase_user     = "testadmin"
  externalDatabase_password = "T3stpwd@12E"
  helm_app_name             = "stihlclonetest"
  cluster_namespace         = "stihlclonetest-ns"
}