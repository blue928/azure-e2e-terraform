<?php

?>
<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="container-fluid">
    <div class="row">
      <div class="col-md-3">
        <?php print render($content['product_preview']); ?>
        <?php print render($content['product_preview_button']); ?>
      </div>
      <div class="col-md-9">
        <div class="row">
          <?php print render($title_prefix); ?>
          <?php if (!$page && $title): ?>
            <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
        </div>
        <div class="row">
          <div class="col-md-7">
            <ul class="product-info-list list-group">
              <?php if ($content['sku']): ?>
                <li class="list-group-item">
                  <?php print render($content['sku']); ?>
                </li>
              <?php endif; ?>
              <?php if ($content['field_product_type']): ?>
                <li class="list-group-item">
                  <?php print render($content['field_product_type']); ?>
                </li>
              <?php endif; ?>
              <?php if ($content['field_event_type']): ?>
                <li class="list-group-item">
                  <?php print render($content['field_event_type']); ?>
                </li>
              <?php endif; ?>
              <?php if ($content['field_dimensions']): ?>
                <li class="list-group-item">
                  <?php print render($content['field_dimensions']); ?>
                </li>
              <?php endif; ?>
            </ul>
          </div>
          <div class="col-md-5 text-center">
            <?php if ($content['field_available_until']): ?>
              <span class="text-danger">
                <?php print render($content['field_available_until']); ?>
              </span>
            <?php endif; ?>
            <?php if ($content['field_price_table']): ?>
              <?php print render($content['field_price_table']); ?>
            <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="col-md-12">
        <?php print render($content['add_to_cart']); ?>
      </div>
    </div>
  </div>

</article><!-- /.node -->
