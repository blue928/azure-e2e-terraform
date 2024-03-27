resource "kubernetes_manifest" "two" {
  depends_on = [module.aks-cluster]
  for_each   = fileset("${path.module}/aks2", "*.yaml")
  manifest   = yamldecode(file("${path.module}/aks2/${each.value}"))
}
