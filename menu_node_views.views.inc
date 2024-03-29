<?php


/**
 * @file Menu Node Views definitions.
 */

/**
 * Implements hook_views_data().
 */
function menu_node_views_views_data() {
  $data = array();
  $data['menu_node']['table']['group'] = t('Menu');
  $data['menu_node']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
/*$data['menu_node']['mlid'] = array(
    'title' => t('Menu link id'),
    'help' => t('Unique menu item dentifier.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
  );
  $data['menu_node']['nid'] = array(
    'title' => t('Node id'),
    'help' => t('The node id, menu-sensitive.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'menu_node_views_argument_nid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );*/

  $data['menu_links']['table']['join'] = array(
    'menu_node' => array(
      'left_field' => 'mlid',
      'field' => 'mlid',
    ),
    'node' => array(
      'left_table' => 'menu_node',
      'left_field' => 'mlid',
      'field' => 'mlid',
    ),
  );
  $data['menu_links']['table']['base'] = array(
    'field' => 'mlid',
    'title' => t('Menu tree'),
    'help' => t('Menu item views.'),
  );
  $data['menu_links']['table']['group'] = t('Menu');
  $data['menu_links']['nid'] = array(
    'title' => t('Node id'),
    'help' => t('The node id, menu-sensitive.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'menu_node_views_argument_nid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['menu_links']['menu_name'] = array(
    'title' => t('Menu name'),
    'help' => t('The name of the menu.'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'menu_node_views_field_menu_name',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // TODO: Make this auto-link?
  $data['menu_links']['link_title'] = array(
    'title' => t('Link title'),
    'help' => t('The link text used for the menu item.'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'menu_node_views_field_link_title'
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['menu_links']['description'] = array(
    'title' => t('Description'),
    'help' => t('The description used for the menu item.'),
    'field' => array(
      'handler' => 'menu_node_views_field_description'
    ),
  );
  $data['menu_links']['link_path'] = array(
    'title' => t('Link path'),
    'help' => t('The link path for the menu item.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['menu_links']['mlid'] = array(
    'title' => t('Menu link id'),
    'help' => t('The unique menu link identifier.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['menu_links']['plid'] = array(
    'title' => t('Parent menu link id'),
    'help' => t('The unique menu link identifier for this item\'s parent.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'menu_links',
      'field' => 'plid',
      'handler' => 'views_handler_relationship',
      'label' => t('Menu link - parent item'),
    ),
  );
  $data['menu_links']['weight'] = array(
    'title' => t('Weight'),
    'help' => t('The weight of the menu item.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['menu_links']['hidden'] = array(
    'title' => t('Hidden'),
    'help' => t('The menu item visibility.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['menu_links']['depth'] = array(
    'title' => t('Depth'),
    'help' => t('The depth of the menu item.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // TODO: Write a depth handler.
  $data['menu_links']['p1'] = array(
    'title' => t('Parent'),
    'help' => t('The top-level parent of the menu item.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'menu_node_views_sort_menu',
    ),
  );
  $data['menu_links']['no_content'] = array(
    'title' => t('No content'),
    'help' => t('Menu items without content.'),
    'filter' => array(
      'handler' => 'menu_node_views_filter_no_content',
    ),
  );
  $data['node']['no_menu'] = array(
    'title' => t('Content without menu entry'),
    'help' => t('Content without menu entry.'),
    'filter' => array(
      'handler' => 'menu_node_views_filter_content_without_menu',
    ),
  );
  return $data;
}
