/**
 * @file
 * Provides custom behaviors for the classic_bootstrap theme.
 */

(function ($) {
	Drupal.behaviors.stihl = {
   	attach: function () {
   		// IE8 fallback for SVG logo.
   		if (!Modernizr.svg) {
   			var logo = $('.logo');
  			$('img[src*="svg"]',logo).attr('src', function() {
  				logo.parent().addClass('PNG');
					return $(this).attr('src').replace('.svg','.png');
  			});
			}

		 	// Farbtastic color picker stuff.
		 	if(window.location.href.indexOf("appearance/settings") > -1) {
	      var c = $('#edit-colors input');
	      var f = $.farbtastic('#picker');
	      var p = $('#picker').css('opacity', 0.25);
	      var selected;
	      c.each(function () {
	        f.linkTo(this);
	        $(this).css('opacity', 0.5);
	      })
	      .focus(function() {
	        if (selected) {
	          $(selected).css('opacity', 0.5);
	        }
	        f.linkTo(this);
	        p.css('opacity', 1);
	        $(selected = this).css('opacity', 1);
	      });
	    }

      // Prevent going to cart when clicking the cart link.
      $("a.cart-toggle").on("click", function(event) {
        event.preventDefault();
      });

      // Silly logic to make caret control dropdown but link still be followed.
      $('#pop-menu li.dropdown').on('click', function(e) {
        return false;
      });

      $('#pop-menu li.dropdown > a > .caret').on('click', function(e) {
        e.preventDefault();
        e.stopPropagation();
        var $el = $(this);
        $el.parent('[data-toggle=dropdown]').dropdown('toggle');
      });

      $('#pop-menu li.dropdown a').on('click', function(e) {
        var $el = $(this);
        if ($el.length && $el.attr('href')) {
          location.href = $el.attr('href');
        }
      });
		}
	};
}) (jQuery);
