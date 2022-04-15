/**
 * @file
 * Javascript file for stihl_products module.
 */

(function ($) {
  Drupal.behaviors.stihlOrders = {
    attach: function () {

      // If the row contains a kit field, add styles to adjust the layout.
      $('.kit').parents('.row').addClass('has-kit');
      // If the row is a chainsaw item or contains extra fields, add styles
      // to adjust the layout and for appearance.
      $('#category-5').find('.row').addClass('multi-row');
      $('.extra-fields').parents('.row').addClass('multi-row');

      // Select the parent fieldset of any field that has an error on submit.
      $fieldset_error = $('.has-error').parents('.collapsible');
      // Add classes to make sure the panel with field error is not collapsed
      // so the user can see the field(s) with the error.
      $fieldset_error.removeClass('collapsed').find('.panel-collapse').addClass('in');
      // Collapse any other fieldsets to focus the view on the errors.
      if ($('.collapsible').find('.has-error').length != 0) {
        $(this).addClass('collapsed').find('.panel-collapse').removeClass('in');
      }

      // Close the current fieldset and show the previous on '.prev' nav click.
      $('.btn.prev').click(function(e) {
        e.preventDefault();
        $(this).parents('.collapsible').addClass('collapsed').find('.panel-collapse').removeClass('in');
        $(this).parents('.collapsible').prev().removeClass('collapsed').find('.panel-title').click();
      });

      // Close the current fieldset and show the next on '.next' nav click.
      $('.btn.next').click(function(e) {
        e.preventDefault();
        $(this).parents('.collapsible').addClass('collapsed').find('.panel-collapse').removeClass('in');
        $(this).parents('.collapsible').next().removeClass('collapsed').find('.panel-title').click();
      });

    }
  };

  Drupal.behaviors.stihlOrderProgress = {
    attach: function () {
      if ($('body').hasClass('page-orders-configure')) {
        // Get all the fieldsets in an order.
        var fieldsets = $('#-stihl-orders-render-configure-line-items-form fieldset');

        // Iterate through each fieldset in order to be able to check
        // for which fields have data (that count).
        fieldsets.each(function(){
          var self = this;

          $(self).find('.row').each(function(){
            // Perform check on each field in a row to determine its
            // completeness.
            checkForCompleteness($(this));
          });

        });

        // After classes have been added to 'completed' fields, update the
        // counts in the fieldset.
        updateFieldsetCounts(fieldsets);

        $('.kit-1 input, .kit-2 input, .bulk input').on('blur', function() {
          // Check for 'completeness'.
          checkForCompleteness($(this).closest('.row'));

          // Update counts.
          updateFieldsetCounts(fieldsets);
        });
      }
    }
  };

  /**
   * Update each row with a class when quantity are filled out.
   *
   * @param row
   *   jQuery object. Each row in an order.
   */
  function checkForCompleteness(row) {
    if (
      row.hasClass('has-kit') &&
      (row.find('.kit-1 input').val() ||
      row.find('.kit-2 input').val() ||
      row.find('.bulk input').val())
      ) {
      // Add class to row if quantity fields are completed.
      $(row).addClass('input-completed');
    }
    else if (!$(row).hasClass('has-kit') && $(row).find('.bulk input').val()) {
      // Add class to row if quantity fields are completed.
      $(row).addClass('input-completed');
    }
    else if (
      !row.find('.kit-1 input').val() &&
      !row.find('.kit-2 input').val() &&
      !row.find('.bulk input').val()
    ) {
      $(row).removeClass('input-completed');
    }
  }

  /**
   * Loops through each fieldset and updates 'completeness' count.
   *
   * @param fieldsets
   *   jQuery object of all fieldsets in an order.
   */
  function updateFieldsetCounts(fieldsets) {
    // Update counts in fieldset.
    fieldsets.each(function() {
      $(this).find('.tid-completed').text($(this).find('.input-completed').length);
    });
  }
}) (jQuery);
