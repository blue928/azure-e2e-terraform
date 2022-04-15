/**
 * @file
 * Javascript file for stihl_products module.
 */

(function ($) {
  Drupal.behaviors.stihlOrdersEdit = {
    attach: function (context, settings) {
      $('[id^=select-tid-]').click(function () {
        var checkboxes = $(this).parent().find('input:checkbox');
        $(checkboxes).prop('checked', !checkboxes.prop('checked'));
      });
    }
  };
}) (jQuery);
