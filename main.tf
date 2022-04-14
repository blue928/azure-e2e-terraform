terraform {
  required_providers {
    azurerm = {
      source = "hashicorp/azurerm"
    }
    kubernetes = {
      source = "hashicorp/kubernetes"
    }
    helm = {
      source = "hashicorp/helm"
    }

    kubectl = {
      source  = "gavinbunney/kubectl"
      #version = ">= 1.7.0"
    }
  }

  #backend "azurerm" {
  #  resource_group_name  = "terraform-storage-rg"
  #  storage_account_name = "terraformstateimagine"
  #  container_name       = "terraformstatefiles"
  #  key                  = "stihlclonetest.tfstate"
  #}
}

# https://registry.terraform.io/providers/hashicorp/azurerm/latest/docs
provider "azurerm" {
  #skip_provider_registration = true

  # https://registry.terraform.io/providers/hashicorp/azurerm/latest/docs#features
  features {
    resource_group {
      # For added security, the Production value for this should be set to true. 
      # Note: From version 3.0 this will be true by default. 
      # https://registry.terraform.io/providers/hashicorp/azurerm/latest/docs#prevent_deletion_if_contains_resources
      # prevent_deletion_if_contains_resources = true

      prevent_deletion_if_contains_resources = false
    }
  }
}

# The configuration for kubernetes and helm require the cluster to be created first
# and the providers to be enabled after.
# See this issue: https://github.com/hashicorp/terraform-provider-kubernetes/blob/main/_examples/aks/README.md#aks-azure-kubernetes-service
data "azurerm_kubernetes_cluster" "default" {
  depends_on          = [module.aks-cluster] # refresh cluster state before reading
  name                = "${var.project_name}-cluster"
  resource_group_name = module.azure-rg.resource_group_name
}

provider "kubernetes" {
  host                   = data.azurerm_kubernetes_cluster.default.kube_config.0.host
  client_certificate     = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.client_certificate)
  client_key             = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.client_key)
  cluster_ca_certificate = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.cluster_ca_certificate)
}

provider "kubectl" {
  host                   = data.azurerm_kubernetes_cluster.default.kube_config.0.host
  client_certificate     = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.client_certificate)
  client_key             = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.client_key)
  cluster_ca_certificate = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.cluster_ca_certificate)
}

provider "helm" {
  kubernetes {
    host                   = data.azurerm_kubernetes_cluster.default.kube_config.0.host
    client_certificate     = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.client_certificate)
    client_key             = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.client_key)
    cluster_ca_certificate = base64decode(data.azurerm_kubernetes_cluster.default.kube_config.0.cluster_ca_certificate)
  }
}