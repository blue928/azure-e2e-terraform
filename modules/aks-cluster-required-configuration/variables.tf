variable "cluster_production_ns" {
  type = string
  default = "production-ns"
  # todo refactor this out as a local after testing
}

variable "storage_class_cluster_location" {
  type = string
  description = "The cluster's geolocation"
}