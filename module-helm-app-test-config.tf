module "helm-app-module" {
  depends_on = [
    module.aks-cluster,
    module.aks-cluster-required-config,
    module.mysql-flexible-server,
  ]
  source                    = "github.com/blue928/helm-app-terraform-module"
  externalDatabase_host     = module.mysql-flexible-server.fs_db_server_fqdn
  externalDatabase_database = "${var.project_name}productiondb"
  externalDatabase_user     = "testadmin"
  externalDatabase_password = "T3stpwd@12E"
  helm_app_name             = var.project_name
  cluster_namespace         = "${var.project_name}-ns"
}