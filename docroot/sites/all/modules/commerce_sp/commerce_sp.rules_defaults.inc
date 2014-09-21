<?php
/**
 * @file
 * commerce_sp.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_sp_default_rules_configuration() {
  $items = array();
  $items['rules_commerce_sp_cancel_subscription_expiration'] = entity_import('rules_config', '{ "rules_commerce_sp_cancel_subscription_expiration" : {
      "LABEL" : "Cancel subscription expiration",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "account:field-commerce-sp-skip-expire" ],
            "value" : [ "account-unchanged:field-commerce-sp-skip-expire" ]
          }
        },
        { "data_is" : { "data" : [ "account:field-commerce-sp-skip-expire" ], "value" : 1 } }
      ],
      "DO" : [
        { "schedule_delete" : {
            "component" : "rules_commerce_sp_subscription_end",
            "task" : "expire-[account:uid]"
          }
        }
      ]
    }
  }');
  $items['rules_commerce_sp_line_item_is_subscription_product'] = entity_import('rules_config', '{ "rules_commerce_sp_line_item_is_subscription_product" : {
      "LABEL" : "Apply subscription if line item is subscription product",
      "PLUGIN" : "rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line item", "type" : "commerce_line_item" } },
      "IF" : [
        { "data_is" : { "data" : [ "line-item:type" ], "value" : "product" } },
        { "data_is" : {
            "data" : [ "line-item:commerce-product:type" ],
            "value" : "commerce_sp_subscription"
          }
        },
        { "data_is" : {
            "data" : [ "line-item:commerce-product:field-commerce-sp-time:interval" ],
            "op" : "\\u003E",
            "value" : "0"
          }
        }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "line-item:commerce-product:field-commerce-sp-time:interval" ],
              "op" : "*",
              "input_2" : [ "line-item:quantity" ]
            },
            "PROVIDE" : { "result" : { "subscription_time_number" : "Subscription time number" } }
          }
        },
        { "data_convert" : {
            "USING" : { "type" : "integer", "value" : [ "subscription-time-number" ] },
            "PROVIDE" : { "conversion_result" : { "conversion_result" : "Conversion result" } }
          }
        },
        { "component_rules_commerce_sp_subscription_time_to_validity" : {
            "subscription_time_number" : [ "conversion-result" ],
            "subscription_time_period" : [ "line-item:commerce-product:field-commerce-sp-time:period" ],
            "account" : [ "line-item:order:owner" ]
          }
        }
      ]
    }
  }');
  $items['rules_commerce_sp_line_item_subscription_product_apply'] = entity_import('rules_config', '{ "rules_commerce_sp_line_item_subscription_product_apply" : {
      "LABEL" : "Apply subscription if line item is subscription product",
      "PLUGIN" : "rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line item", "type" : "commerce_line_item" } },
      "IF" : [
        { "data_is" : { "data" : [ "line-item:type" ], "value" : "product" } },
        { "data_is" : {
            "data" : [ "line-item:commerce-product:type" ],
            "value" : "commerce_sp_subscription"
          }
        },
        { "data_is" : {
            "data" : [ "line-item:commerce-product:field-commerce-sp-time:interval" ],
            "op" : "\\u003E",
            "value" : "0"
          }
        }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "line-item:commerce-product:field-commerce-sp-time:interval" ],
              "op" : "*",
              "input_2" : [ "line-item:quantity" ]
            },
            "PROVIDE" : { "result" : { "subscription_time_number" : "Subscription time number" } }
          }
        },
        { "data_convert" : {
            "USING" : { "type" : "integer", "value" : [ "subscription-time-number" ] },
            "PROVIDE" : { "conversion_result" : { "conversion_result" : "Conversion result" } }
          }
        },
        { "component_rules_commerce_sp_subscription_time_to_validity" : {
            "subscription_time_number" : [ "conversion-result" ],
            "subscription_time_period" : [ "line-item:commerce-product:field-commerce-sp-time:period" ],
            "account" : [ "line-item:order:owner" ]
          }
        }
      ]
    }
  }');
  $items['rules_commerce_sp_schedule_subscription_expiration'] = entity_import('rules_config', '{ "rules_commerce_sp_schedule_subscription_expiration" : {
      "LABEL" : "Schedule subscription expiration",
      "PLUGIN" : "rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "USES VARIABLES" : { "account" : { "label" : "User account", "type" : "user" } },
      "IF" : [
        { "data_is_empty" : { "data" : [ "account:field-commerce-sp-skip-expire" ] } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "rules_commerce_sp_subscription_end",
            "date" : [ "account:field-commerce-sp-validity" ],
            "identifier" : "expire-[account:uid]",
            "param_user" : [ "account" ]
          }
        }
      ]
    }
  }');
  $items['rules_commerce_sp_subscription_aborted_as_account_is_del'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_aborted_as_account_is_del" : {
      "LABEL" : "Subscription aborted as user account is deleted",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "user_delete" ],
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "account:field-commerce-sp-validity" ] } }
      ],
      "DO" : [
        { "schedule_delete" : {
            "component" : "rules_commerce_sp_subscription_end",
            "task" : "expire-[account:uid]"
          }
        }
      ]
    }
  }');
  $items['rules_commerce_sp_subscription_bought'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_bought" : {
      "LABEL" : "Apply bought subscription time",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "3",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_commerce_sp_line_item_subscription_product_apply" : { "line_item" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_commerce_sp_subscription_end'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_end" : {
      "LABEL" : "Subscription end",
      "PLUGIN" : "rule set",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [
              { "data_set" : { "data" : [ "user:field-commerce-sp-validity" ] } },
              { "data_set" : { "data" : [ "user:field-commerce-sp-skip-expire" ], "value" : 0 } }
            ],
            "LABEL" : "Clear subscription settings"
          }
        }
      ]
    }
  }');
  $items['rules_commerce_sp_subscription_schedule_update'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_schedule_update" : {
      "LABEL" : "Update subscription expiration schedule",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "OR" : [
            { "AND" : [
                { "NOT data_is" : {
                    "data" : [ "account:field-commerce-sp-validity" ],
                    "value" : [ "account-unchanged:field-commerce-sp-validity" ]
                  }
                },
                { "NOT data_is_empty" : { "data" : [ "account:field-commerce-sp-validity" ] } }
              ]
            },
            { "AND" : [
                { "NOT data_is" : {
                    "data" : [ "account:field-commerce-sp-skip-expire" ],
                    "value" : [ "account-unchanged:field-commerce-sp-skip-expire" ]
                  }
                },
                { "data_is_empty" : { "data" : [ "account:field-commerce-sp-skip-expire" ] } }
              ]
            }
          ]
        }
      ],
      "DO" : [
        { "component_rules_commerce_sp_schedule_subscription_expiration" : { "account" : [ "account" ] } }
      ]
    }
  }');
  $items['rules_commerce_sp_subscription_start'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_start" : {
      "LABEL" : "Subscription start",
      "PLUGIN" : "rule set",
      "TAGS" : [ "commerce_sp" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "RULES" : []
    }
  }');
  $items['rules_commerce_sp_subscription_started_insert'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_started_insert" : {
      "LABEL" : "Subscription started (insert)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert" ],
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "account:field-commerce-sp-validity" ] } }
      ],
      "DO" : [
        { "component_rules_commerce_sp_subscription_start" : { "user" : [ "account" ] } },
        { "component_rules_commerce_sp_schedule_subscription_expiration" : { "account" : [ "account" ] } }
      ]
    }
  }');
  $items['rules_commerce_sp_subscription_started_update'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_started_update" : {
      "LABEL" : "Subscription started (update)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "account:field-commerce-sp-validity" ] } },
        { "data_is_empty" : { "data" : [ "account-unchanged:field-commerce-sp-validity" ] } }
      ],
      "DO" : [
        { "component_rules_commerce_sp_subscription_start" : { "user" : [ "account" ] } },
        { "component_rules_commerce_sp_schedule_subscription_expiration" : { "account" : [ "account" ] } }
      ]
    }
  }');
  $items['rules_commerce_sp_subscription_time_to_validity'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_time_to_validity" : {
      "LABEL" : "Apply bought subscription time to user subscription validity",
      "PLUGIN" : "rule set",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules", "interval" ],
      "USES VARIABLES" : {
        "subscription_time_number" : { "label" : "Subscription time number", "type" : "integer" },
        "subscription_time_period" : { "label" : "Subscription time period", "type" : "token" },
        "account" : { "label" : "User account to apply the time", "type" : "user" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "data_is_empty" : { "data" : [ "account:field-commerce-sp-validity" ] } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "account:field-commerce-sp-validity" ], "value" : "now" } }
            ],
            "LABEL" : "User has no subscription yet"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "date" : { "date" : "New date" } },
            "DO" : [
              { "interval_apply" : {
                  "USING" : {
                    "interval" : [ "subscription-time-number" ],
                    "period" : [ "subscription-time-period" ],
                    "date" : [ "account:field-commerce-sp-validity" ]
                  },
                  "PROVIDE" : { "date" : { "date" : "New date" } }
                }
              },
              { "data_set" : {
                  "data" : [ "account:field-commerce-sp-validity" ],
                  "value" : [ "date" ]
                }
              }
            ],
            "LABEL" : "Add the time interval to the validity date"
          }
        }
      ]
    }
  }');
  $items['rules_commerce_sp_subscription_validity_is_unset'] = entity_import('rules_config', '{ "rules_commerce_sp_subscription_validity_is_unset" : {
      "LABEL" : "End subscription when validity is unset",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "commerce_sp" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "account:field-commerce-sp-validity" ],
            "value" : [ "account-unchanged:field-commerce-sp-validity" ]
          }
        },
        { "data_is_empty" : { "data" : [ "account:field-commerce-sp-validity" ] } }
      ],
      "DO" : [
        { "schedule_delete" : {
            "component" : "rules_commerce_sp_subscription_end",
            "task" : "expire-[account:uid]"
          }
        },
        { "component_rules_commerce_sp_subscription_end" : { "user" : [ "account" ] } }
      ]
    }
  }');
  return $items;
}
