<?php
// $Id$

/**
 * @file
 * Administrative page callbacks for the wot module.
 */

/**
 * Administration settings form.
 *
 * @see system_settings_form()
 */
function wot_admin_settings() {
  $form = array();

  $form['wot'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#maxlength' => 30,
    '#title' => t('WOT verification code'),
    '#description' => t('This code shall only include digits (0 to 9) and hexadecimal characters (a to f).'),
    '#default_value' => variable_get('wot', NULL),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  $form['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('wot_admin_settings_reset_submit'),
  );

  $form['#submit'][] = 'wot_admin_settings_submit';

  return $form;
}

