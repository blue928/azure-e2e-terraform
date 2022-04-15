<?php

/**
 * @file
 * Hooks provided by the Fusion Pro module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Change the encoding pattern definitions before conversion occurs.
 *
 * @param array $patterns
 *   An array of character conversions (key) and replacement patterns (value).
 */
function hook_fusion_pro_encode_entities_alter(array &$patterns) {
  // Replace an existing encoding.
  $patterns['®'] = '(MY-CUSTOM-REG)';
  // Remove an existing encoding.
  unset($patterns['™']);
  // Add a custom encoding.
  $patterns['ﾮ'] = '&#65454;';
}

/**
 * @} End of "addtogroup hooks".
 */
