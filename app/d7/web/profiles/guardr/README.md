# Guardr Distribution

Drupal distribution with common modules for enhancing web application security.

## Use Guardr as the base for a new Drupal project

Download [Guardr 7.x-2.49](http://ftp.drupal.org/files/projects/guardr-7.x-2.49-core.tar.gz) or use drush <code>$ drush dl guardr</code>.

Install Drupal using the Guardr codebase as you would normally, but make sure to select the Guardr profile during the installation process.

## Building a Guardr instance for development and testing

Download the [Guardr profile](http://ftp.drupal.org/files/projects/guardr-7.x-2.x-dev.tar.gz).

**Build the instance:**

<code>
$ drush --no-patch-txt make <path-to-guardr>/build-guardr.make <path-to-make-results>
</code>

Note: --no-patch-txt is optional, but recommended for production use. It prevents the creation of PATCHES.txt files in any project which has patches applied by the Guardr distribution.

**And finally install the site with drush site-install:**

<code>
$ cd <path-to-make-results>
</code>

<code>
$ drush si --db-url=mysql://[db_user]:[db_pass]@localhost/[db_name] --account-name=admin --account-pass=[account-password] --account-mail=admin@example.com --site-name=Guardr --site-mail=admin@example.com guardr
</code>

**Or if you have Drush >= version 5 you can use drush qd to test Guardr:**

<code>
$ cd <path-to-make-results>
</code>

<code>
$ drush qd --root=<path-to-make-results> --use-existing --profile=guardr --cache --watchdog --yes
</code>

**You can also download, install, and run Guardr from one drush qd command:**

<code>
$ drush qd guardr --core=guardr --profile=guardr --cache --watchdog --yes
</code>

##Default Settings

###Password Policy
*Applied by password_policy.module*

Passwords are set to expire every 90 days with a warning email sent out 14 & 7 days before it is set to expire.

Passwords must:

* Contain atleast 3 charecter types
* Must contain atleast 2 digits
* Cannot contain the username
* Be atleast 8 charecters long
* Cannot match the previous 24 passwords
