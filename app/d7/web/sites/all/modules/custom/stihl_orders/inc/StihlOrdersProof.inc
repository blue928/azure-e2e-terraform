<?php

/**
 * @file
 * Stihl Orders Proof class.
 */

/**
 * Stihl Orders Proof class.
 */
class StihlOrdersProof {

  /**
   * ID associated with this order's proofs.
   *
   * @var int
   */
  protected $id = 0;

  /**
   * Indicates whether RLCI admins should be notified to review.
   *
   * @var bool
   */
  public $notify = TRUE;

  /**
   * Time the proofs were requested.
   *
   * @var int
   */
  public $created = 0;

  /**
   * Name of the method to execute.
   *
   * Used by the cron queue to store the stage of the proofing process.
   *
   * @var string
   */
  protected $action = 'checkStatus';

  /**
   * Path to the watched folder associated with this order.
   *
   * @var string
   */
  protected $watchedFolder = '';

  /**
   * Path to the directory containing the print-ready files for this order.
   *
   * @var string
   */
  protected $printFolder = '';

  /**
   * Path to the directory containing the data files associated with this order.
   *
   * @var string
   */
  protected $dataFolder = '';

  /**
   * Path to the ZIP file associated with this order.
   *
   * @var string
   */
  public $zip = '';

  /**
   * Full path of each data file associated with this order.
   *
   * @var array
   */
  protected $dataFiles = array();

  /**
   * Full path of each PDF Proof file associated with this order.
   *
   * @var array
   */
  protected $pdfs = array();

  /**
   * Cron queue for creating hangtag proofs.
   *
   * @var \DrupalQueue
   */
  protected $queue;

  /**
   * Constructor.
   *
   * @param int $order_id
   *   Order ID for which to create the proofs.
   */
  public function __construct($order_id) {
    $this->id = $order_id;
    $this->watchedFolder = STIHL_ORDERS_HOTFOLDER_URI . "{$this->id}/";
    $this->printFolder = STIHL_ORDERS_PRINT_URI . "{$this->id}/";
    $this->dataFolder = "private://{$this->id}/";
    $this->zip = STIHL_ORDERS_PROOF_URI . "{$this->id}.zip";
    $this->dataFiles = $this->getDataFiles();
    $this->queue = DrupalQueue::get('create_hangtag_proof', TRUE);
  }

  /**
   * Get the CSV data file(s) associated with this order's hangtag proofs.
   *
   * @return array
   *   An array of realpaths to this order's CSV files.
   */
  protected function getDataFiles() {
    $data_files = $this->ls($this->dataFolder, '*.csv');
    return $data_files;
  }

  /**
   * Get the PDF Proof file(s) associated with this order.
   *
   * @return array
   *   An array of realpaths to this order's PDF files.
   */
  protected function getPdfFiles() {
    $this->pdfs = $this->ls($this->watchedFolder, '*pdf');
    return $this->pdfs;
  }

  /**
   * Public wrapper to execute methods from the cron worker callback.
   *
   * @param array $data
   *   Information associated with this order to be stored in the `queue` table.
   */
  public function exec(array $data) {
    $this->notify = $data['notify'] != FALSE;
    $this->created = $data['created'];

    $time_expired = (int) ((REQUEST_TIME - $this->created) / 60);
    if ($this->created && ($timeout = variable_get('stihl_orders_proofs_timeout', 60)) && $time_expired > $timeout) {
      $message = 'Proof creation exceeded timeout at @stage stage. Process aborted after @time_expired minutes.';
      $replace = array('@time_expired' => $time_expired, '@stage' => $this->action);
      $this->warn($message, $replace, WATCHDOG_ERROR);
      return FALSE;
    }

    $this->{$data['action']}();
  }

  /**
   * Adds this order back to the cron queue.
   *
   * If we determine that an order is still processing on the hot folder site,
   * we can move onto the next order in the queue that needs proofs and come
   * back to check on this one later.
   */
  protected function wait() {
    // An array of data that will be stored in the `queue` table for this
    // order's cron job.
    $data = array(
      'order_id' => $this->id,
      'notify' => $this->notify,
      'action' => $this->action,
      'created' => $this->created,
    );

    $this->queue->createItem($data);

    $message = 'Added to the proofing queue; @data';
    $replace = array('@data' => http_build_query($data, NULL, ' '));
    $this->log($message, $replace, WATCHDOG_DEBUG);
  }

  /**
   * Initiate the hangtag proofing process.
   *
   * @return bool
   *   TRUE if successful.
   */
  protected function create() {

    // We need to delete any in-progress proofs with the same ID when a request
    // for new proof is made. If the queue's empty, we can skip this step.
    if ($this->queue->numberOfItems() > 0) {

      // Admittedly, this is hacky but since the values of the data stored in
      // the queue for in-progress jobs is likely different than the values for
      // the current order, we use a `LIKE` query to key soley off the ID.
      $data = preg_replace('/.+\{|\}/', '', serialize(array('order_id' => $this->id)));

      // Remove existing cron jobs for this order.
      db_delete('queue')
        ->condition('data', '%' . $data . '%', 'LIKE')
        ->execute();
    }

    // Get a list of the data files associated with this order.
    $this->dataFiles = $this->getDataFiles();

    // Copy the data files to the hot folder's watched folder.
    if ($this->sendToWatchedFolder()) {
      $message = 'Data files transferred to watched folder (@folder): @data_files';
      $replace = array(
        '@folder' => $this->watchedFolder,
        '@data_files' => implode(', ', $this->dataFiles),
      );
      $this->log($message, $replace, WATCHDOG_DEBUG);
    }

    // We're waiting for the hot folder's cron job to pick up the data files and
    // process them against FusionPro, so we can skip this order, check on other
    // jobs in the queue, and check on this one afterwards.
    $this->wait();
    return TRUE;
  }

  /**
   * Copy the data files to the watched folder for processing.
   *
   * @return bool
   *   TRUE if all files were successfully transferred. FALSE otherwise.
   */
  protected function sendToWatchedFolder() {
    foreach ($this->dataFiles as $data_file) {
      // The path to the destination file.
      $destination = $this->watchedFolder . basename($data_file);

      // Attempt to copy the data file to the watched folder.
      if (!file_unmanaged_copy($data_file, $destination, FILE_EXISTS_REPLACE)) {
        $message = 'Unable to copy "@data_file" to "@destination"';
        $replace = array(
          '@data_file' => $data_file,
          '@destination' => $destination,
        );

        $this->warn($message, $replace);
        return FALSE;
      }
    }
    return TRUE;
  }

  /**
   * Check the status of the order's proofs.
   *
   * @return bool
   *   TRUE if processing is complete and proofs are created.
   *   FALSE if the proofs are still processing.
   */
  public function checkStatus() {

    // An array of all of the PDFs that have been created for this order.
    $pdfs = $this->getPdfFiles();

    // Get the real path to the watchedFolder rather than the stream wrapper
    // to match the paths in the $pdfs directory.
    $watchedFolder = drupal_realpath($this->watchedFolder) . '/';

    // An order's proofing process is complete when there is a PDF for
    // each of the data files associated with the order's ID.
    foreach ($this->dataFiles as $data_file) {

      // PDF should be named the same as the csv file.
      $pdf_file = $watchedFolder . pathinfo($data_file, PATHINFO_FILENAME) . '.pdf';

      // If $pdf_file is not in the array of available PDFs or it's been
      // modified in the past 60 seconds, we can assume that it is still
      // processing in the hot folder and skip to the next order.
      if (!in_array($pdf_file, $pdfs) || ((time() - filemtime($pdf_file)) < 60)) {
        if (!$this->created) {
          $this->created = REQUEST_TIME;
        }
        $this->log('Still processing; PDF not yet created for @pdf_file', array('@pdf_file' => $pdf_file), WATCHDOG_DEBUG);
        $this->wait();
        return FALSE;
      }
    }

    $this->log('All proofs created.');

    // Compress the output.
    $this->zipProofs();
  }

  /**
   * Creates a zip file for client download.
   *
   * The zip file will contain all of the PDF proofs associated with this order
   * as well as all of the data files used to create the PDF proofs.
   *
   * @return bool
   *   TRUE if files were successfully compressed. FALSE otherwise.
   */
  protected function zipProofs() {
    // Make sure there are files to zip.
    if (empty($this->dataFiles) || empty($this->pdfs)) {
      $this->warn('No files found to zip.');
      $this->transitionToReviewState();
      return $this->cleanup();
    }

    // Create an array to hold the command.
    $command = array();

    // ZIP command to execute on the server:
    // -r: Recursively add all files in the specified directory.
    // -j: Store just the name of the file (not the paths).
    // -9: Level of compression. Nine is the highest.
    $command[] = 'zip -rj9';

    // Add the command arguments and wrap the paths in quotes.
    foreach (array_merge((array) drupal_realpath($this->zip), $this->dataFiles, $this->pdfs) as $file) {
      $command[] = '"' . $file . '"';
    }

    // Execute the command and capture the output and exit code.
    exec(implode(' ', $command), $output, $exit_code);

    // Anything higher than an exit status of 0 is indicative of an error.
    if ($exit_code > 0) {
      $this->warn('Error zipping proofs; <pre>@err</pre>', array('@err' => print_r($output, TRUE)));
      return FALSE;
    }

    // Clear file status cache to ensure accurate result.
    clearstatcache();

    // Check if the file was created.
    if (file_exists($this->zip)) {

      // Transition the state of this order to 'ready for review'.
      $this->transitionToReviewState();

      // Log the triumphant success to watchdog with a link to the zip.
      $this->log('Proofs compressed for download.');

      // Clean up after ourselves.
      $this->cleanup();
    }
    else {
      // If the file wasn't created, log the error.
      $this->warn('Compressed proofs not found but were expected; @zip', array('@zip' => $this->zip));
    }
  }

  /**
   * Transition the order to 'ready for review'.
   */
  protected function transitionToReviewState() {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $this->id);
    if ($order_wrapper->field_order_status->value() == stihl_orders_get_states_by_workflow()['submitted']) {
      if (_stihl_orders_update_order_workflow_transition($this->id, 'ready for review') == FALSE) {
        $this->warn('Unable to transition to ready for review', array(), WATCHDOG_ERROR);
      }
    }

    // Notify the appropriate parties that the proofs are ready for review.
    if ($this->notify) {
      stihl_orders_send_order_status_change_email($order_wrapper, 'order_ready_for_review');
    }
  }

  /**
   * Clean up after proofs have been created.
   *
   * Remove the directories, uncompressed PDFs, and data files that were used
   * in creating the ZIP file to free up disk space.
   *
   * @return bool
   *   TRUE if successful; FALSE otherwise.
   */
  public function cleanup() {

    // Set stage to 'cleanup' for future cron runs for this order.
    $this->action = 'cleanup';

    // Get an array of all CSV files in the watched directory.
    $watchedFiles = $this->ls($this->watchedFolder, '*.csv');

    // The csv files in the watched folder are managed by the hot folder. So,
    // we will depend on the hot folder to clean those up. If there are no CSVs
    // in the watched folder, it's fine to start cleaning up.
    if (!empty($watchedFiles)) {

      $message = 'Unable to clean up; File(s) still in use: @files';
      $replace = array('@files' => implode(', ', $watchedFiles));
      $this->log($message, $replace, WATCHDOG_DEBUG);

      // If the hot folder hasn't finished cleaning up after itself, move on to
      // the next order in the queue and check again later by adding it back to
      // the queue and returning.
      $this->wait();
      return FALSE;
    }

    // Remove the dataFolder and watchedFolder.
    foreach (array('dataFolder', 'watchedFolder') as $dir) {
      $dir = $this->{$dir};
      if (is_dir($dir)) {
        if ($this->emptyDir($dir) == FALSE) {
          $this->wait();
          continue;
        }
        if (file_unmanaged_delete_recursive($dir) == FALSE) {
          $this->warn('Unable to remove @dir', array('@dir' => $dir));
        }
      }
    }
    $this->log('Clean up complete!');
    return TRUE;
  }

  /**
   * Ensures that the required file/folder structure is in place for proofing.
   *
   * @return bool
   *   Returns TRUE if everything is set up correctly, FALSE otherwise.
   */
  public function prepForProofs() {
    // If a zip file already exists for this order, remove it so that
    // we can guarantee we're returning the most up-to-date zip file.
    if (file_exists($this->zip) && drupal_unlink($this->zip)) {
      $this->log('Removed @zip', array('@zip' => $this->zip), WATCHDOG_DEBUG);
    }

    if (!empty($this->dataFiles)) {
      $filenames = array_map('basename', $this->dataFiles);
      $message = 'Overwrote existing data files. It may be necessary to reset the hotfolder job(s) for the following: @filenames';
      $replace = array('@filenames' => implode(', ', $filenames));
      $this->warn($message, $replace);
    }

    // Prepare the directories.
    foreach (array('watchedFolder', 'dataFolder', 'printFolder') as $dir) {
      $dir = $this->{$dir};
      // Ensure the directories exist and are writable.
      if (!file_prepare_directory($dir, FILE_CREATE_DIRECTORY)) {
        $this->warn('Unable to create directory: @dir', array('@dir' => $dir), WATCHDOG_ERROR);
        return FALSE;
      }
      // Remove any old files from the directories.
      $this->emptyDir($dir);
    }
    return TRUE;
  }

  /**
   * Remove all files from a specified directory.
   *
   * @param string $dir
   *   Path to the directory.
   *
   * @return bool
   *   TRUE on success (or directory doesn't exist); FALSE on failure.
   */
  protected function emptyDir($dir) {
    $files = $this->ls($dir);
    if (!($success = empty($files))) {
      // Remove the files in the directory.
      $removed_files = array_map('drupal_unlink', $files);

      // Determine if all files were successfully removed.
      $success = in_array(0, $removed_files) == FALSE;

      // Set the content and severity of the log message based on the result.
      $message = $success ? 'Removed all files in @dir' : 'Unable to remove all files from @dir';
      $severity = $success ? WATCHDOG_DEBUG : WATCHDOG_ERROR;
      $replace = array('@dir' => $dir);
      $this->log($message, $replace, $severity);
    }
    return $success;
  }

  /**
   * List the files in a given directory.
   *
   * @param string $path
   *   The path to the directory.
   * @param string $grep
   *   Pattern to match files in $path against.
   *
   * @return array
   *   Array of files matching the pattern ($grep) in $path.
   *   Empty array if no files matching the pattern are found.
   */
  protected function ls($path, $grep = '*.*') {
    clearstatcache();
    $path = drupal_realpath($path);
    if (file_exists($path) && is_dir($path)) {
      return glob($path . "/{$grep}");
    }
    return array();
  }

  /**
   * Create watchdog warning.
   *
   * @see log()
   */
  protected function warn($message, array $replace = array(), $severity = WATCHDOG_WARNING, $link = NULL) {
    $this->log($message, $replace, $severity, $link);
  }

  /**
   * Create watchdog notification.
   *
   * @param string $message
   *   Message to display in db log.
   * @param array $replace
   *   Array of string replacement values for $message.
   * @param int $severity
   *   Severity of the message; Ranges from 0 (most severe) to 7 (least severe).
   * @param string $link
   *   A link to associate with the message.
   */
  protected function log($message, array $replace = array(), $severity = WATCHDOG_INFO, $link = NULL) {
    // Warnings and higher should be reported.
    if ($severity <= WATCHDOG_WARNING) {
      $this->sendNotification(strtr($message, $replace), $severity);
    }

    if ($severity <= variable_get('stihl_orders_proofs_logging', WATCHDOG_INFO)) {
      // Prepend each log message with the order_id.
      $message = 'Order #@order_id: ' . $message;
      $replace['@order_id'] = $this->id;
      // Log message to watch dog.
      watchdog('stihl_orders', $message, $replace, $severity, $link);
    }
  }

  /**
   * Send a notification via Email or Slack.
   *
   * @param string $message
   *   Message to be sent.
   * @param int $severity
   *   Level of severity of the notification.
   *   Ranges from 0 (most severe) to 7 (least severe).
   */
  protected function sendNotification($message, $severity = WATCHDOG_INFO) {
    // Determine Environment (default to Production).
    $environment = 'Production';
    if (preg_match('/test|staging/i', $GLOBALS['base_url'], $env)) {
      $environment = ucwords(strtolower(reset($env)));
    }

    // Determine the level of severity (default to "notice").
    $severity_level = 'notice';
    if ($severity < WATCHDOG_WARNING) {
      $severity_level = 'error';
    }
    elseif ($severity < WATCHDOG_NOTICE) {
      $severity_level = 'warning';
    }

    // Send notification based on configuration.
    switch (variable_get('stihl_orders_proofs_internal_notifications', 'slack')) {
      case 'slack':
        $this->sendSlack($message, $severity_level, $environment);
        break;

      case 'email':
        $this->sendEmail($message, $severity_level, $environment);
        break;
    }
  }

  /**
   * Send notification via email.
   *
   * @param string $message
   *   Message to be delivered.
   * @param string $severity
   *   Level of severity of the notification.
   *   Expected values: error|warning|notice.
   * @param string $environment
   *   Environment from which the notice is being sent.
   *   Expected values: Test|Staging|Production.
   */
  protected function sendEmail($message, $severity, $environment) {
    $module = 'stihl_orders';
    $key = 'proof_failure';
    $to = variable_get('stihl_orders_proofs_failure_emails', 'dev@knowclassic.com');
    $language = language_default();
    $params = array(
      'order_id' => $this->id,
      'severity' => $severity,
      'message' => $message,
      'environment' => $environment,
    );
    $send = TRUE;
    $from = 'noreply@knowclassic.com';
    drupal_mail($module, $key, $to, $language, $params, $from, $send);
  }

  /**
   * Send notification via Slack.
   *
   * @param string $message
   *   Message to be delivered.
   * @param string $severity
   *   Level of severity of the notification.
   *   Expected values: error|warning|notice.
   * @param string $environment
   *   Environment from which the notice is being sent.
   *   Expected values: Test|Staging|Production.
   */
  protected function sendSlack($message, $severity, $environment) {
    // Make sure the slack function is available.
    if (function_exists('slack_send_message')) {
      $color_key = array(
        'error' => '#FF0000',
        'warning' => '#FFE800',
        'notice' => '#06CA00',
      );

      // Get the webhook URL and username from the slack module config.
      $webhook_url = slack_get_default_webhook_url();
      $username = slack_get_default_username();
      $channel = variable_get('stihl_orders_proofs_failure_slack_channel', '#test-alerts');

      // Use the CG icon.
      $icon_options = array('type' => 'emoji', 'emoji' => ':classic:');

      // Configure the notification.
      $attachment_options = array(
        'title' => t('STIHL Hangtag Order #@order_id', array('@order_id' => $this->id)),
        'title_link' => $GLOBALS['base_url'] . '/orders/submit/' . $this->id,
        'color' => $color_key[$severity],
        'footer' => "Stihl Hangtag Portal - {$environment}",
        'mrkdwn_in' => array('text'),
      );

      // Replace <pre> tags with markdown codeblock syntax.
      $message = preg_replace('/<\/?pre>/', '```', $message);

      // Errors should alert the channel.
      $message = $severity == 'error' ? "<!channel>: {$message}" : $message;

      // Send the message to #slack.
      slack_send_message($webhook_url, $message, $channel, $username, $icon_options, $attachment_options);
    }
    // If the Slack module is not correctly configured, notify via email.
    else {
      $message = "Unable to post notification to Slack.\n{$message}";
      $this->sendEmail($message, $severity, $environment);
    }
  }

  /**
   * Create an array of order export csv file paths.
   *
   * @param EntityMetadataWrapper $line_item
   *   The line item entity metadata wrapper.
   * @param int $bd_id
   *   The id of the BD for this order.
   *
   * @return array
   *   An array of csv file paths.
   */
  public function filePathsArray(EntityMetadataWrapper $line_item, $bd_id) {
    // BD id 10 (Stihl Southeast) has a specific directory for csv exports.
    // Determine if order is from SSE distributor id 10.
    $is_sse = ($bd_id == 10) ? TRUE : FALSE;

    // This function builds an array of file paths.
    $file_path_array = array();

    // Map the field_sign_style to the value to be used in the name of the csv.
    // field_sign_style => value used in csv.
    $style_map = array(
      'vertical_one_sided' => 'V1',
      'vertical_two_sided' => 'V2',
      'horizontal' => 'H',
    );

    // Determine the style based on the line item's field_sign_style value and
    // the defined $style_map. If the order is from SSE, the style is 'S'.
    $style = $is_sse ? 'S' : $style_map[$line_item->field_sign_style->value()];

    // Kit 1 group.
    if ($line_item->field_kit_1_qty->value() > 0) {
      $file_path_array['kit1'] = $this->dataFolder . "K1_{$style}_{$this->id}.csv";
    }
    // Kit 2 group.
    if ($line_item->field_kit_2_qty->value() > 0) {
      $file_path_array['kit2'] = $this->dataFolder . "K2_{$style}_{$this->id}.csv";
    }
    // Bulk group.
    if ($line_item->field_order_bulk->value() > 0) {
      $file_path_array['bulk'] = $this->dataFolder . "B_{$style}_{$this->id}.csv";
    }

    // Remove keys and return a simple array.
    return array_values($file_path_array);
  }

  /**
   * Create the data files needed to create proofs for an order.
   *
   * Using the order, user, product, and pricing data opens a new csv file and
   * each line item creates a row in the csv file. There is a csv file for
   * horizontal and a csv file for vertical hangtags. This csv file is used in
   * hotfolder for Fusion Pro.
   *
   * @param object $order
   *   A fully loaded order object.
   */
  public function createDataFiles($order) {
    $order_year_reference = $order->field_pricing_year_reference[LANGUAGE_NONE][0]['target_id'];
    $order_year = stihl_pricing_years_get_year_by_id($order_year_reference);

    // Prepare the necessary directories for proofs.
    if (!$this->prepForProofs()) {
      return;
    }

    // User submitting order and their bd location.
    $submitter = entity_metadata_wrapper('user', $order->uid);
    $bd = $submitter->field_bd_reference->value();

    // Iterate line items to create csv row of field data.
    foreach ($order->commerce_line_items[LANGUAGE_NONE] as $line_item) {

      $line_item = entity_metadata_wrapper('commerce_line_item', $line_item['line_item_id']);
      $product = entity_metadata_wrapper('commerce_product', $line_item->commerce_product->value());

      // Build an array of fields for a csv row.
      $fields['Order ID'] = $order->order_id;
      $fields['Order Name'] = $order->field_order_title[LANGUAGE_NONE][0]['value'];
      $fields['Pricing Year'] = $order_year;
      $fields['Ordered By'] = $submitter->name->value();
      $fields['Ordered For'] = $bd->name;
      $fields['Ordered For ID'] = $bd->id;
      $fields['RLC SKU'] = $product->sku->value();
      $fields['Price'] = $line_item->field_tag_price->value();
      $fields['Horizontal'] = $product->field_horizontal_hangtag->value();
      $fields['Chainsaw'] = $product->field_chainsaw->value();
      $fields['Pricing Language'] = $line_item->field_special_pricing_language->value();
      $fields['New'] = $product->field_new->value();
      $fields['Model'] = stihl_orders_convert_fusionpro_characters($product->field_model->value());
      $fields['Main Length'] = stihl_orders_convert_fusionpro_characters($product->field_main_length->value());
      $fields['Part Number'] = $product->field_subhead_partnumber->value();
      $fields['Length 2'] = $line_item->field_variation_name_1->value();
      $fields['Price 2'] = $line_item->field_variation_price_1->value();
      $fields['Length 3'] = $line_item->field_variation_name_2->value();
      $fields['Price 3'] = $line_item->field_variation_price_2->value();
      $fields['Length 4'] = $line_item->field_variation_name_3->value();
      $fields['Price 4'] = $line_item->field_variation_price_3->value();
      $fields['Two Sided'] = ($line_item->field_sign_style->value() == 'vertical_two_sided') ? 'Y' : 'N';

      // File paths determined by product groups and sign style.
      $file_paths_array = $this->filePathsArray($line_item, $bd->id);

      // For each potential csv, write the $fields array to the csv row.
      foreach ($file_paths_array as $file_path) {
        stihl_orders_write_row_to_fusionpro_csv($file_path, $fields, $line_item);
      }
    }

    $this->log('Successfully exported csv files(s).');

    // Timestamp order to record csv file created.
    $order->field_order_csv_exported[LANGUAGE_NONE][0]['value'] = format_date(REQUEST_TIME, 'custom', 'Y-m-d H:i:s', 'UTC');
    commerce_order_save($order);

    // Now that the CSV data files have been written, create the proofs.
    $this->create();
  }

}
