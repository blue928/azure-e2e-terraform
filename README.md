
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

- At this point all infrastructure is deployed, including the ACR registry, but not the Drupal app itself, which requires the ACR to be deployed first.  Go into Devops and create the default docker pipeline "build and push image to azure container registry." Fill these out with your credentials. Run the Pipeline to build the Docker image.

- In Portal.azure.com click on the ACR registry to get the ACR Hostname, repository, image name, and tag.

## Launching the Drupal App

- in the file 'drupal-kubectl-test.tf' uncomment all of the code. At the top of that file add the test drupal hostname you want to use as well as the ACR hostname, repo name, image name, and tag, referenced from the acr registry in portal.azure.com.

- run the same 4 terraform commands again (terraform init -upgrade, terraform validate, terraform plan, terraform apply)

- The test app is installed in the 'default' namespace. You can now interact with the app's pods to deploy the database and further configure the drupal app, if necessary (drush commands).
- To deploy the database run 'kubectl get pod' to get the name of the app's pod. Copy the database from the local folder to a tmp folder and import the db with mysql. Note, unzip the db.sql file if necessary. mysql only imports from raw .sql files. Execute these commands to get up and running.
  - kubectl get pod
  - kubectl cp ./app/db/initdb.d/db.sql stihl9-55b94b5bf5-km5t6:/tmp (Note your pod name will be different per the above command )
  - kubectl exec --stdin --tty stihl9-55b94b5bf5-km5t6 -- /bin/bash # This will put you inside the pod
  - mysql -u ${MYSQL_USER} -p${MYSQL_PASSWORD} -h${DATABASE_HOST} ${MYSQL_DATABASE} < /tmp/db.sql (note this takes about 20 min)
  - drush cc all
  - drush dis ldap* -y
  - drush cc all
  - drush user-create adminuser --mail="myemail@maddress.edu" --password="UserPw"; drush user-add-role "administrator" adminuser ; drush uli adminuser

- You should now have a full working infrastructure with the stihl drupal site connected to an external mysql database

- ### TODO

- Configure tighter security for production
- switch from default namespace to specified namespace for production, test, qa, staging, etc
- update pipelines to fire with correct admin credentials; deploy into correct namespace based on credentials.
- integrate ldap access
