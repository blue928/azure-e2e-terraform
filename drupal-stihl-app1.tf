module "drupal-stihl-app1" {
  depends_on = [
    module.aks-cluster,
    module.aks-cluster-required-config,
    module.mysql-flexible-server,
  ]
  source                    = "github.com/blue928/helm-app-terraform-module"
  externalDatabase_host     = module.mysql-flexible-server.fs_db_server_fqdn
  #externalDatabase_database = "${var.project_name}productiondb"
  externalDatabase_database = "drupal-stihl-app1-productiondb"
  externalDatabase_user     = "testadmin"
  externalDatabase_password = "T3stpwd@12E"
  helm_app_name             = var.project_name
  #helm_app_name = "drupal-stihl-app1"
  cluster_namespace         = "${var.project_name}-ns"
  #cluster_namespace = "drupal-stihl-app1-ns"

  # Custom image registry config
  image_registry = "${var.project_name}acr.azurecr.io"
  image_repository = "stihl7"
  image_tag = "238"
}