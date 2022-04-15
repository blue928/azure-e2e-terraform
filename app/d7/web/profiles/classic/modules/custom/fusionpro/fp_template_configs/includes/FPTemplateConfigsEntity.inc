<?php

/**
 * @file
 * FP Template Configs entity class.
 */

/**
 * Template Config entity class.
 */
class FPTemplateConfigsEntity extends Entity {

  /**
   * Override with a custom URI.
   */
  protected function defaultUri() {
    return array('path' => FP_TEMPLATE_CONFIGS_VIEW_URI . '/' . $this->identifier());
  }

  /**
   * Determine the name of the function which invoked a method in this class.
   *
   * @return string
   *   The name of the invoking function.
   */
  private function getCaller() {
    $trace = debug_backtrace();

    // $trace[0]: this function (getCaller).
    // $trace[1]: the name of the function that called 'getCaller'.
    // $trace[2]: the name of the invoking function.
    return isset($trace[2]['function']) ? $trace[2]['function'] : 'fp_template_configs';
  }

  /**
   * Determines which XMLRPC method to use based on $this->data_format.
   *
   * @return string
   *   The XMLRPC method to invoke on the FusionPro server.
   */
  protected function getCompositionMethod() {
    return $this->data_format == 'csv' ? 'generate_v2_csv' : 'generate_v2';
  }

  /**
   * Determines the output file type.
   *
   * @return string
   *   Returns the output file type if it exists.
   *   Defaults to 'pdf.'
   */
  protected function getOutputType() {
    return $this->file_type ?: 'pdf';
  }

  /**
   * Determines if a given file in the preview:// directory is readable.
   *
   * @param string $file_name
   *   The name of the file to check - no extension.
   *
   * @return string
   *   Returns the full path of the file if it exists,
   *   returns NULL if it does not exist.
   */
  protected function fileExists($file_name) {
    $file_path = "preview://{$file_name}.{$this->getOutputType()}";
    // Attempt to open a file resource.
    $file_pointer = @fopen($file_path, 'r');
    return $file_pointer ? $file_path : NULL;
  }

  /**
   * Compose data against this FP template configuration.
   *
   * @param array $data
   *   An array of keyed-array(s) which correspond to FP data fields
   *   that will be used to compose an output file ($file_name).
   * @param string $file_name
   *   An optional base name for the resulting output file.
   *
   * @return string
   *   Returns the full path to the composed file if the composition
   *   was successful – returns NULL if it wasn't.
   */
  public function compose(array $data, $file_name = '') {

    // Dynamically determine the caller.
    $caller = $this->getCaller();

    // If no data was sent, report the error and finish.
    if (empty($data)) {
      watchdog($caller, 'No data passed to FP at composition time.', array(), WATCHDOG_WARNING);
      return NULL;
    }

    // Create a hash of the data for caching purposes but it will also
    // double as a default $file_name in the event that one isn't supplied.
    $hash = md5(serialize($data));
    $file_name .= "_$hash";

    // If the template config has caching enabled, check to see if a file
    // created from the same dataset exists.
    // If it does, we can return that file and avoid a redundant composition.
    if (($output_name = $this->fileExists($file_name)) && $this->cache) {
      return $output_name;
    }

    // Determine the values associated with this template config that are
    // necessary to make the call to FusionPro.
    $type = $this->getOutputType();
    $template = $this->template;
    $method = $this->getCompositionMethod();

    // Invoke the function in the fusion_pro module here to actually create
    // the file. On success, it returns the file name (no extension).
    if ($output_name = fusion_pro_get_pdf($template, $type, $file_name, $data, $caller, $method)) {

      // Check to ensure we can read the file ($output_name).
      return $this->fileExists($output_name);
    }

    return NULL;
  }

}
