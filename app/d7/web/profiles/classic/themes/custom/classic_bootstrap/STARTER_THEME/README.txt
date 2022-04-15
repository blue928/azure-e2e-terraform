This theme is a subtheme of Classic Bootstrap, which is a subtheme of the Drupal Bootstrap theme. Classic Bootstrap and Drupal Bootstrap are both required to be installed as a base themes, but do not have to be enabled.

Usage:
	[1] Move this theme to sites/all/themes.
	[2] Rename 'starter_theme' to something that makes sense for your project.
	[3] Change 'starter_theme.info' to match your theme name. Example: foo.info.
	[4] Change line 1 of the info file from 'Starter Theme' to your theme name.
	[5] Change 'starter_theme_preprocess_html' line 11 in template.php to your theme name + '_preprocess_html'. Example: 'foo_preprocess_html'.
	[6] Change 'admin/appearance/settings/starter_theme' line 14 of template.php to 'admin/appearance/settings' + your_theme_name. Example: 'admin/appearance/settings/foo'.
	[7] Flush caches [drush cc all].
	[8] Enable the jQuery Update module [drush en profiles/classic/modules/contrib/jquery_update].
	[9] Bootstrap requires a min of jquery 1.7. Make sure the jQuery Update default version is 1.7 or higher 'admin/config/development/jquery_update'.
	[10] Enable the new theme in Appearance 'admin/appearance'.
	[11] Set the new theme as the admin theme 'admin/appearance'. Yes, do it.
	[12] Set a custom logo path in admin/appearance/settings for your theme. SVG files are recommended for clean images on responsive retina devices. There is CSS in place to scale your SVG file.
	[13] Optionally disable the Home menu link in 'admin/structure/menu/manage/main-menu'. Just makes the navbar cleaner.


Features:

	[1] You may use an SVG file for the theme logo, which is provided by default. You may replace the logo.svg file as needed.
	[2] This theme uses the Farbtastic module, as provided by Drupal 7 core. The implementation of this module allows an admin to override the default colors of main HTML elements provided by the LESS files.
	[3] DO NOT EDIT THE CSS FILES DIRECTLY. Use the LESS files to generate the CSS files.
	[4] The Classic Bootstrap theme implements a jQuery keydown() function to expand the sidemenu, which will be available.
	[5] Add a block of content to the top_bar region to add to the sidemenu. I will probably change the name of this region accordingly.

	More to come.