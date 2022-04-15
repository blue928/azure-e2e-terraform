/**
 * @file
 * Provides custom behaviors for the classic_bootstrap theme.
 */
 
(function ($) {
	Drupal.behaviors.classic_bootstrap = {
   	attach: function () {

   		// IE8 fallback for SVG logo.
   		if (!Modernizr.svg) {
   			var logo = $('.logo');
  			$('img[src*="svg"]',logo).attr('src', function() {
  				logo.parent().addClass('PNG');
					return $(this).attr('src').replace('.svg','.png');
  			});
			}

			// Enable tooltip on sidemenu if turned off in the theme settings UI.
			$("#sidemenu .footer").tooltip({
				container: 'body',
				placement: 'right',
				viewport: '#viewport'
			});

		 	// Toggle the visibility of the sidemenu.
   		function toggleStuff() {
				var sf = $("#sidemenu .footer");
				var txt = sf.attr("data-original-title");
				
				if (txt === 'Expand Sidebar ( [ )'){
				  sf.attr("data-original-title","Collapse Sidebar ( [ )");
				}
				if (txt === 'Collapse Sidebar ( [ )'){
				 	sf.attr("data-original-title","Expand Sidebar ( [ )");
				}
				$('#sidemenu').toggleClass('open');
   		}

			$('#sidemenu, #sidemenu .footer, .navbar-toggle').on('click', function(e) {
				// If a #sidemenu child element is clicked stop the toggle.
				if (e.target !== this) {
					return;
				}
				toggleStuff();
			});
			
			// Toggle the sidemenu if '[' key is pressed.
			$(document).on("keydown", function(e) {
				if (e.which === 219) {
					toggleStuff();
					e.stopPropagation();
				}
			});

 			// Expand the sidemenu if desktop screen sizes.
			$(window).load(function(){
				if ($(window).width() >= 992) {
					toggleStuff();
				}
			});

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
		}
	};
}) (jQuery);