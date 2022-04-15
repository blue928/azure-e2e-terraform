# Classic distribution

Drupal distribution for common features used across Classic Graphics applications and websites. The Classic distro uses Guardr as a base profile.

## Build the Classic distribution codebase with drush make

* Checkout classic_distro.git locally
* Run the following to build the Classic distribution codebase:
<code>
drush --no-patch-txt make [path-to-classic]/build-classic.make.yml [path-to-make-results]
</code>

## Classic distribution installation options

* Run the Drupal installer as you would install any other Drupal instance
* Use drush si to install
<code>
$ drush si --db-url=mysql://[db_user]:[db_pass]@localhost/[db_name] --account-name=admin --account-pass=[account-password] --account-mail=admin@example.com --site-name=Classic --site-mail=admin@example.com classic

Note: --no-patch-txt is for drush make operations is optional, but recommended for production use. It prevents the creation of PATCHES.txt files in any project which has patches applied by the Guardr and Classic distributions.
</code>

### Build and Install Script
There is a built-in shell script located at: `scripts/build.sh`

This script can build, optionally install, and optionally check for module updates.

**Notes:**

1. Script must be run from profile directory.

2. Destination directory is **required** by the script.  The destination directory will be placed parallel to the distro directory.

3. Site install requires you to define local settings in script file.  See *User Configurations* in `scripts/build.sh`.

**Examples:**

Using your terminal, inside the profile directory, run:

`scripts/build.sh -d [destination]`

`scripts/build.sh -d httpdocs`


To run Drush site_install after the build run:

`scripts/build.sh -d httpdocs -i`


To check for module updates run:

`scripts/build.sh -d httpdocs -i -u`

### Script Requirements

` -d [destination]`  The destination directory name.

### Script Options

` -i `  Run the Drush *site_install* command after the build.

` -u `  Check for updates after the site is installed.

` -v `  See output of Drush verbose.

` -h `  See these options.



