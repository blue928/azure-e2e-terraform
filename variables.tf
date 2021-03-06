# The project_name variable is the only one that needs to be set. 
# All outher default resource names are auto-generated in the
# locals {} block below. 
variable "project_name" {
  type    = string
  default = "teststihlcustom"
}

# Default location of all resources created by Terraform. Choose
# a different location if it makes more sense for the project. 
variable "location" {
  type    = string
  default = "eastus"
}


# Variables for module arguments
# module-externaldns-config.tf 
variable "externaldns_namespace" {
  type    = string
  default = "externaldns"
}

variable "externaldns_domain" {
  type    = string
  default = "bluepresley.com"
}

variable "cert_manager_email" {
  type    = string
  default = "bluepresley@gastonia.com"
}