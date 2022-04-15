<?php

/**
 * @file
 * Example of FusionPro module in action.
 */

/**
 * Call the FusionPro module functions.
 */
function example_fusion_pro() {
  $source_data = array(
    'template_file' => 'yourtemplatefile',
    'type' => 'type',
    'data' => array(
      'first_pdf_name' => array(
        'field1' => 'value1',
        'field2' => 'value2',
      ),
      'second_pdf_name' => array(
        'field1' => 'value1',
        'field2' => 'value2',
      ),
    ),
  );

  // Make multiple calls.
  $template_file = $source_data['template_file'];
  $type = $source_data['type'];
  $data = array($source_data['data']);
  $caller = 'module_name';
  fusion_pro_get_pdfs($template_file, $type, $data, $caller);

  // Make single call.
  $pdf_name = 'first_pdf_name';
  $row = $source_data['data'][$pdf_name];
  fusion_pro_get_pdf($template_file, $type, $pdf_name, $row, $caller);
}
