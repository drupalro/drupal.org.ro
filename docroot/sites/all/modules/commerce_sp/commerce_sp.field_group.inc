<?php
/**
 * @file
 * commerce_sp.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function commerce_sp_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_commerce_sp|user|user|form';
  $field_group->group_name = 'group_commerce_sp';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Subscription',
    'weight' => '4',
    'children' => array(
      0 => 'field_commerce_sp_skip_expire',
      1 => 'field_commerce_sp_validity',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_commerce_sp|user|user|form'] = $field_group;

  return $export;
}
