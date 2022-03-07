# ---------------------------------------------------------------------------------------------------------------------
# REQUIRED VERSIONS AND PROVIDERS
# ---------------------------------------------------------------------------------------------------------------------

# Module inherits provider configuration from parent.
# terraform {
#  required_providers {
#    source = hashicorp/azurerm
#  }
#}

# ---------------------------------------------------------------------------------------------------------------------
# CREATE A PRODUCTION-GRADE, AUTO-SCALING AKS KUBERNETES CLUSTER
# ---------------------------------------------------------------------------------------------------------------------

resource "azurerm_kubernetes_cluster" "k8s" {
  name                = var.cluster_name
  location            = var.cluster_location
  resource_group_name = var.cluster_resource_group_name
  node_resource_group = var.cluster_node_resource_group_name
  dns_prefix          = var.cluster_dns_prefix

  default_node_pool {
    name = "agentpool"
    # node_count      = var.agent_count

    # Let Azure manage the API version automatically
    # orchestrator_version = data.azurerm_kubernetes_service_versions.current.latest_version
    vm_size             = var.cluster_default_node_pool_vm_size
    availability_zones  = [1, 2, 3]
    type                = "VirtualMachineScaleSets"
    enable_auto_scaling = true
    max_count           = var.cluster_default_node_pool_max_count
    min_count           = var.cluster_default_node_pool_min_count
    os_disk_size_gb     = var.cluster_default_node_pool_os_disk_size_gb

    node_taints = []
    tags        = {}
  }

  identity {
    type = "SystemAssigned"
  }

  role_based_access_control {
    enabled = false
  }

  oms_agent {
  log_analytics_workspace_id = var.log_analytics_workspace_id
  }

  network_profile {
    load_balancer_sku = "Standard"
    network_plugin    = "kubenet"
  }

  tags = {
    #environment = var.environment
  }
}