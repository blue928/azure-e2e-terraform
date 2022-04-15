<?php
/**
 * @file
 * Writes inline CSS from theme-settings $vars.
 */

?>

@CHARSET "UTF-8";
#logo { background-color: <?php print $logo_bgcolor; ?> }
#navbar, #footer-wrapper { background-color: <?php print $navbar_bgcolor; ?> }
a, a.btn-default { color: <?php print $links_color; ?> }
.btn-primary { background-color: <?php print $links_color; ?>; border-color: <?php print $links_color; ?> }
.btn-primary:hover { background-color: <?php print $links_color; ?>; border-color: transparent; opacity: .85; }
