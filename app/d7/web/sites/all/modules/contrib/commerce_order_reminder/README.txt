
DESCRIPTION
-----------

As the name implies, this light weighted module sends email
reminders to website users of the orders that were left
uncompleted. The reminders will only be sent about those
orders that have the email property filled. This includes
even those orders of anonymous users that entered their email
in the billing information form but did not complete the
checkout process.

Commerce Order Reminder is capable of sending different
notifications, allows setting up time ranges, and has many
more options. The sending of reminders occurs automatically
while cron run, so once you get the module set up, you do
not need to worry about it anymore.

FEATURES
--------

* Configurable minimum and maximum age of the orders to
  send reminders of
* Configurable reminder periodicity (if there is more than
  one reminder)
* Configurable specific sender information (name and email)
* Possibility to restrict reminders to certain user roles
* Possibility to send several reminders
* Configurable email templates for each reminder
* All email templates support tokens, including Commerce
  Order tokens of the order to be reminded of

USING THE MODULE
----------------

Go to admin/commerce/config/commerce-order-reminder, set
up the module and enjoy your email reminders being sent
automatically.

The module has no other dependencies than Commerce Order.
If you install Token though, you will be able to use a
convenient Token Tree when editing reminder email templates.
