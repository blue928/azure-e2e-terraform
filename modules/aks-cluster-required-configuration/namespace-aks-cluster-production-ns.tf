resource "kubernetes_namespace" "production_ns" {
  metadata {
    annotations = {}
    labels      = {}
    name        = var.cluster_production_ns
  }
}