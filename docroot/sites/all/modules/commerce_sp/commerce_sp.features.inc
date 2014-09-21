<?php
/**
 * @file
 * commerce_sp.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function commerce_sp_commerce_product_default_types() {
  $items = array(
    'commerce_sp_subscription' => array(
      'type' => 'commerce_sp_subscription',
      'name' => 'Subscription',
      'description' => 'A product type for selling subscriptions.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function commerce_sp_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
