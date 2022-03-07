# ---------------------------------------------------------------------------------------------------------------------
# REQUIRED VERSIONS AND PROVIDERS
# ---------------------------------------------------------------------------------------------------------------------

# Module inherits provider configuration from parent.
# Uncomment and configure for greater specificity.
# terraform {
#  required_providers {
#    source = hashicorp/azurerm
#  }
#}

# ---------------------------------------------------------------------------------------------------------------------
# AKS CLUSTER REQUIRED CONFIGURATION
# After the AKS Cluster is created this default configuration must be applied.
# The resources that are created are:
#  - Storage:
#    - storage-aks-azure-file-share-storage-class.tf 
#  - Namespace
#    - namespace-aks-cluster-production-ns.tf 
# ---------------------------------------------------------------------------------------------------------------------
