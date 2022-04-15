<?php

/**
 * @file
 * Fusion Pro stream wrapper extension.
 */

/**
 * FP preview (preview://) stream wrapper class.
 *
 * Provides support for using the Drupal File API on FP preview files.
 *
 * Extends DrupalPublicStreamWrapper.
 */
class FusionProPreviewStreamWrapper extends DrupalPublicStreamWrapper {
  /**
   * Return the absolute path of the FP preview folder.
   */
  public function getDirectoryPath() {
    return variable_get('fusion_pro_pdf_storage_path', '/var/www/preview');
  }

}
