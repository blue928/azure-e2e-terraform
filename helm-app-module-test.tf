module "helm-app-module" {
  source                  = "github.com/blue928/helm-app-terraform-module"
  externaldb_fqdn         = module.mysql-flexible-server.fs_db_server_fqdn
  externaldbprod_database = "production-ns"
  externaldbprod_user     = "testadmin"
  externaldbprod_password = "T3stpwd@12E"


}