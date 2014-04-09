<?php
/**
* Implements hook_block_info().
*/
function collection_sort_block_info() {
  $blocks['collection_sort'] = array(
    // The name that will appear in the block list.
    'info' => t('Collection sort'),
    // Default setting.
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );
  return $blocks;
}

function collection_sort_display() {
	$url = str_replace("%3A",":",$_SERVER['REQUEST_URI']);
        $sortstring = '<div class="collection-sort">Sort by:&#160;';

        $display='&display=list';

        if(stristr($_SERVER['QUERY_STRING'],'display=grid'))
                $display="&display=grid";

        $datesort = '<a href="?sortby=date' . $display .'">date</a>';
        $titlesort = '<a href="?sortby=title' . $display . '">title</a>';

        if (stristr($url,'sortby=date'))
                $datesort = '<span class="collection_sort_off">date</span>';
        if (stristr($url,'sortby=title'))
               $titlesort = '<span class="collection_sort_off">title</span>';

        $sortstring .=  $titlesort . " | " . $datesort;
        $sortstring .=  "</div>\n";
	return $sortstring;
} // end FUNCTION collection_sort_display()

function collection_sort_block_view($delta = '') {
	$block['content'] = collection_sort_display();
	return $block;
}
?>
