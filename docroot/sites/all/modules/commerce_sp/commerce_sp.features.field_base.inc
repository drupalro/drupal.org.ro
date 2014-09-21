<?php
/**
 * @file
 * commerce_sp.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function commerce_sp_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'commerce_price'
  $field_bases['commerce_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_product',
    ),
    'field_name' => 'commerce_price',
    'foreign keys' => array(),
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'field_commerce_sp_skip_expire'
  $field_bases['field_commerce_sp_skip_expire'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_sp_skip_expire',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Automatic',
        1 => 'Skip automatic expiration',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_commerce_sp_time'
  $field_bases['field_commerce_sp_time'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_sp_time',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'interval' => array(
        0 => 'interval',
      ),
      'period' => array(
        0 => 'period',
      ),
    ),
    'locked' => 0,
    'module' => 'interval',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'interval',
  );

  // Exported field_base: 'field_commerce_sp_validity'
  $field_bases['field_commerce_sp_validity'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_sp_validity',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'field_permissions' => NULL,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 'second',
        'year' => 'year',
      ),
      'profile2_private' => FALSE,
      'repeat' => 0,
      'timezone_db' => 'UTC',
      'todate' => '',
      'tz_handling' => 'user',
    ),
    'translatable' => 0,
    'type' => 'datestamp',
  );

  return $field_bases;
}
