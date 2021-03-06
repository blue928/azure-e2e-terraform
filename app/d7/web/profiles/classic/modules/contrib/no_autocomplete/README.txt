CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Recommended modules
 * Installation
 * Configuration
 * Maintainers


INTRODUCTION
------------

The No Autocomplete module adds the autocomplete=off attribute to selected key
user forms. On a browser that respects this setting, it means that the browser
will not try to autocomplete the password on the user login forms, or the whole
user edit form.

 * For a full description of the module, visit the project page:
   https://www.drupal.org/project/no_autocomplete

 * To submit bug reports and feature suggestions, or to track changes:
   https://www.drupal.org/project/issues/search/no_autocomplete


REQUIREMENTS
------------

No special requirements


RECOMMENDED MODULES
-------------------

 * Drush Help (https://www.drupal.org/project/drush_help):
   Improves the module help page showing information about the module drush
   commands.


INSTALLATION
------------

 * Install as you would normally install a contributed Drupal module.
   See: https://www.drupal.org/node/895232 for further information.


CONFIGURATION
-------------

 * Configure the module in Administration » Configuration » People »
   No Autocomplete:

   - Choose which feature you'd like to enable and save the configuration. For
     this you need the 'Administer No Autocomplete' permission.

 * Drush commands

   - drush na-login

     Configures the "autocomplete=off" option on the user login form.

   - drush na-profile

     Configures the "autocomplete=off" option on the user profile edit form.

   - drush na-summary

     Shows the variables status.


MAINTAINERS
-----------

Current maintainers:
 * Adrian Cid Almaguer (adriancid) - https://www.drupal.org/u/adriancid
 * Randy Fay (rfay) - https://www.drupal.org/u/rfay
 * Dhruvesh Tripathi (dhruveshdtripathi) - https://www.drupal.org/user/3083735
