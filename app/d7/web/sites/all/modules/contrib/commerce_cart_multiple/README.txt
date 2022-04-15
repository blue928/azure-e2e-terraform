COMMERCE CART MULTIPLE
----------------------

CONTENTS OF THIS FILE
---------------------
   
 * Introduction
 * Requirements
 * Cautions
 * Configuration
 * Credits/Contact

INTRODUCTION
------------

The Commerce Cart Multiple module provides an interface for users to be able to
create and manage multiple shopping carts.

REQUIREMENTS
------------

This module requires the Commerce (https://drupal.org/project/commerce) module
with the Cart sub-module enabled.

CAUTIONS
--------

 * This module alters the logic of how the current shopping cart is determined.

   By default, the Cart module indicates the current shopping cart by selecting
   thecommerce order of 'cart' status with the highest order_id.  This module
   alters this to selecting the commerce order or 'cart' or 'checkout' status
   that has 'changed' most recently.  This allows for juggling of shopping carts
   by simply saving the cart that should be active.

 * This module allows for the creation of multiple shopping carts.

   A user with multiple cart permission can create additional shopping carts.
   While there is a check to prevent opening of multiple empty carts, there is
   a greater potential for unused carts to pile up.  Consider using modules that
   periodically delete unused carts.
   
CONFIGURATION
-------------
 
 * Configure user permissions in Administration » People » Permissions:

   - Administer carts

     Permission required for viewing and setting multiple carts.

   - Delete own carts

     Allow users to be able to delete a cart.

CREDITS / CONTACT
-----------------

 * Commerce Cart Multiple is based on Order UI, a sub-module of Commerce. 

 * By Dana C. Hutchins (spacetaxi) - https://www.drupal.org/user/244310/
