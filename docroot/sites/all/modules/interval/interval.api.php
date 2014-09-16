<?php
/**
 * @file
 * Documents hooks defined by the module
 * @copyright Copyright(c) 2011 Rowlands Group
 * @license GPL v2+ http://www.fsf.org/licensing/licenses/gpl.html
 * @author Lee Rowlands leerowlands at rowlandsgroup dot com
 *
 */

/**
 * Lets modules nominate their own intervals.
 *
 * The interval module provides various built in intervals such as month, year,
 * week etc but these can be extended by other modules
 *
 * @return array
 *   Implementations of this hook should return an array of intervals keyed by
 *   the machine name for the interval. Note the key name should not exceed
 *   20 characters (unless you implement hook_field_schema_alter)
 *
 *   Each interval defines the following keys
 *     plural: the plural label for the interval
 *     singular: the singular label for the interval
 *     php: the php name for the interval as used in strtotime
 *     multiplier: integer used with the php value = 1 fortnight = 14 days
 *
 * @see interval_interval_intervals
 * @see format_plural
 * @see strtotime
 */
function hook_interval_intervals() {
  return array(
    'month' => array(
      'plural' => t('Months'),
      'singular' => t('Month'),
      'php' => 'months',
      'multiplier' => 1
    ),
    'day' => array(
      'plural' => t('Days'),
      'singular' => t('Day'),
      'php' => 'days',
      'multiplier' => 1
    ),
    'year' => array(
      'plural' => t('Years'),
      'singular' => t('Year'),
      'php' => 'years',
      'multiplier' => 1
    ),
    'week' => array(
      'plural' => t('Weeks'),
      'singular' => t('Week'),
      'php' => 'days',
      'multiplier' => 7
    ),
    'fortnight' => array(
      'plural' => t('Fortnights'),
      'singular' => t('Fortnight'),
      'php' => 'days',
      'multiplier' => 14
    ),
    'quarter' => array(
      'plural' => t('Quarters'),
      'singular' => t('Quarter'),
      'php' => 'months',
      'multiplier' => 3
    )
  );
}
