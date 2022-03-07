variable "azure_dns_zone" {
  type        = string
  description = "The domain name whose DNS zone this architecture will interact with."
}

variable "resource_group_name" {
  type = string
}