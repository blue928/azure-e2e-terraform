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

This module extends the functionality of menu_item_visbility:
https://www.drupal.org/project/menu_item_visibility
It gives the user a new tab where they can select contexts to associate with
a menu item. That menu item will only appear visible on pages where the context
is active.
It based heavily on the menu_item_visibility and context_block_visibility
modules:
    https://www.drupal.org/project/menu_item_visibility
    https://www.drupal.org/project/context_block_visibility


 * For a full description of the module, visit the project page:
   https://www.drupal.org/sandbox/rjjakes/2815295

 * To submit bug reports and feature suggestions, or to track changes:
   https://www.drupal.org/project/issues/2815295?status=All&categories=All


REQUIREMENTS
------------

This module requires the following modules:

 * Menu item visibility (https://drupal.org/project/menu_item_visibility)
 * Context (https://drupal.org/project/context)


RECOMMENDED MODULES
-------------------

 * Menu item visibility (https://www.drupal.org/project/menu_item_visibility)
   When enabled, the setting for the menu item context appear below the
   settings provided by Menu item visbility in the tab group.

 * Context block visbility
   (https://www.drupal.org/project/context_block_visibility):
   A lot of the logic for Context menu item visibility was reworked from this
   module.


INSTALLATION
------------

 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.


CONFIGURATION
-------------

 * Configure contexts in Administration » Structure » Context:

  - Add one or more contexts.

 * Edit/add a link within the menu in Administration » Structure » Menus:

  - Under the "Roles" tab provided by menu_item_visibility, there will be a new
    tab called "Context" will presents a list of the contexts available on the
    site. The admin can active one or more contexts within this menu item and
    the menu link will only show on the site if the context is active for the
    current page.


MAINTAINERS
-----------

Current maintainers:
 * https://www.drupal.org/u/rjjakes
