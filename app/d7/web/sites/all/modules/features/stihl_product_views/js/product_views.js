/**
 * @file
 * Javascript file for stihl_products_views module.
 */

(function ($) {

  Drupal.behaviors.stihlProductViews = {
    attach: function () {

      // Hide and show hang tag preview images via clicking hang tag icons.
      $('#vertical-icon').click(function() {

        $('#horizontal-preview-image').hide();
        $('#vertical-preview-image').fadeIn('fast');

        $('#vertical-icon img').addClass('icon-border');
        $('#horizontal-icon img').removeClass('icon-border');
      });

      $('#horizontal-icon').click(function() {

        $('#vertical-preview-image').hide();
        $('#horizontal-preview-image').fadeIn('fast');

        $('#vertical-icon img').removeClass('icon-border');
        $('#horizontal-icon img').addClass('icon-border');
      });
    }
  };

}) (jQuery);
