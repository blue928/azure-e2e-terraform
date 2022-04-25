1 create a new branch features/stihlclonetest or something

1 change local state file name in main.tf to stihlclonetest.tfstate
2 change pipeline state file name in the devops portal to stihlclonetest.tfstate to match
3 change project name to stihlclonetest to match in variables.tf

1) Run terraform init -upgrade && terraform validate && terraform plan && terraform apply -auto-approve

2) When the deploy is finished, you'll see an output variable called 'az_credentials.' Copy and paste that command into the terminal. Once executed, this gives you access to the cluster via 'kubectl'.

3)

3) In the file 'drupal-kubectl-test.tf' uncomment everything, and make sure the locals variables reflect your configuration

## Pre-flight

- pull down branch <https://github.com/blue928/keyvatech-terraform/tree/keyvarefactored>

- create another branch if you want so you can configure it with your unique config options

- in variables.tf change line 6 to a unique project name of your choosing

- on line 26 change my domain to your test domain. My domain is still in use so you'll have to use yours.

- be sure you have the following installed locally: terraform, azure-cli, kubectl

## Create the Infrastructure with Terraform

- login to your azure account with az login​ and then run az account set -s <your-subscription-id>
run terraform init -upgrade && terraform validate && terraform plan

- if you don't get any validate or plan errors, run terraform apply -auto-approve (if you do get validate errors, let me know what they are)

- login to the registrar for the domain you used. You'll notice in portal.azure.com there is an entry for DNS for the zone you created. If you look at the details it will tell you the four dns servers that microsoft assigned to you. You'll need to edit your domain name entry to reference those 4 dns servers.

- At this point all infrastructure is deployed, including the ACR registry, but not the Drupal app itself.  Go into devops and create the default docker pipeline "build and push image to azure container registry." Fill these out with your credentials. Run the Pipeline to build the Docker image.

- In Portal.azure.com click on the ACR registry to get the ACR Hostname, repository, image name, and tag.

## Launching the Drupal App

- in the file 'drupal-kubectl-test.tf' uncomment all of the code. At the top of that file add the test drupal hostname you want to use as well as the ACR hostname, repo name, image name, and tag, referenced from the acr registry in portal.azure.com.

- run the same 4 terraform commands again (terraform init -upgrade, terraform validate, terraform plan, terraform apply)

- Next,

- You should now have a full working infrastructure with a test drupal site connected to an external mysql database
