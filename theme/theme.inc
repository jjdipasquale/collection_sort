<?php

/**
 * @file
 * Various theme hook implementations.
 */

/**
 * Filter and classify the sections of page entries.
 *
 * @param array $pages
 *   The array of pages, as used in the related preprocess functions.
 *
 * @see template_preprocess_vassardora_one_page_fulltext()
 * @see template_preprocess_vassardora_two_page_fulltext()
 */
function vassardora_filter_and_classify_page_entries(array &$pages) {
  foreach ($pages as &$page) {
    // Filter out sections missing text.
    $page['sections'] = array_values(array_filter($page['sections'], function($element) {
      return $element['text'];
    }));

    $num_sections = count($page['sections']);
    if ($num_sections > 0) {
      foreach ($page['sections'] as &$section) {
        $section['text'] = filter_xss($section['text']);
      }

      if ($num_sections > 1) {
        foreach ($page['sections'] as $index => &$section) {
          $section['class'] = 'text' . ((($index & 1) == 0)?
            'Left' :
            'Right');
        }
      }
      elseif ($num_sections == 1) {
        // Need a class to avoid strict warnings.
        $page['sections'][0]['class'] = '';
      }
    }
  }

  // Filter out "pages" without sections.
  $pages = array_filter($pages, function ($element) {
    return (count($element['sections']) > 0);
  });
}

/**
 * Implements template_preprocess_HOOK().
 */
function template_preprocess_vassardora_fulltext(array &$vars) {
  vassardora_filter_and_classify_page_entries($vars['pages']);

  if (count($vars['pages']) == 0) {
    $vars['pages']['no_text'] = array(
      'label' => t('N/A'),
      'sections' => array(
        array(
          'label' => t('Not available'),
          'class' => '',
          'text' => t('Sorry, but there are no full text/transcription datastreams available.'),
        ),
      ),
    );
  }
}
