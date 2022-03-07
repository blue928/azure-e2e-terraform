# By default, Azure AKS StorageClasses have ReclaimPolicy set to delete,
# which is not what we want. We have to define a custom StorageClass
# and set it to Retain for extra assurance that this file share volume
# cannot be accidentally deleted. 
#
# Because this is a permanent part of the infrastructure, defining this
# Kubernetes resource in Terraform makes more sense. To even further protect
# the files, we'll set the Terraform lifecycle argument to "do not destroy". 
#
# This will automatically create the storage account name and container. 
#
#
# Production Azure File Share storage solution
# References:
#    https://docs.microsoft.com/en-us/azure/storage/files/storage-files-introduction
#    https://docs.microsoft.com/en-us/azure/storage/files/storage-files-faq#general
#    https://docs.microsoft.com/en-us/azure/aks/azure-files-dynamic-pv
#    https://docs.microsoft.com/en-us/azure/aks/csi-storage-drivers

resource "kubernetes_storage_class_v1" "aks_file_share_custom_sc" {
  metadata {
    name = "aks-file-share-custom-sc-csi"
  }

  storage_provisioner = "file.csi.azure.com"
  reclaim_policy      = "Retain"
  volume_binding_mode = "WaitForFirstConsumer"
  parameters = {
    skuName  = "Standard_LRS"
    location = var.storage_class_cluster_location
  }

  allow_volume_expansion = true
  #lifecycle {
  #prevent_destroy = true
  #}

}



# 
/*
kind: StorageClass
apiVersion: storage.k8s.io/v1
metadata:
  name: my-azurefile
provisioner: file.csi.azure.com # replace with "kubernetes.io/azure-file" if aks version is less than 1.21
mountOptions:
  - dir_mode=0777
  - file_mode=0777
  - uid=0
  - gid=0
  - mfsymlinks
  - cache=strict
  - actimeo=30
parameters:
  skuName: Standard_LRS
  */