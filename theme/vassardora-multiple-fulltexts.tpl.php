<?php
/**
 * @file
 * Template for the full-text override for Vassar.
 */

// XXX: Use of "tabs primary" is a quick hack to get 'em showing in a
// somewhat nice manner.
?>
<ul class="tabs primary">
  <?php foreach ($pages as $name => $info):?>
  <li name="vassardora_fulltext_<?php echo $name;?>" class="vassardora_fulltext_link"><a href='#BRfulltext'><?php echo $info['label']; ?></a></li>
  <?php endforeach; ?>
</ul>
<?php
foreach ($pages as $name => $info):
?>
<div class="vassardora_fulltext" id="vassardora_fulltext_<?php echo $name; ?>">
  <?php foreach ($info['sections'] as $section): ?>
  <div class="<?php echo $section['class']; ?>">
    <em class="label"><?php echo $section['label']; ?></em>
    <pre><?php echo $section['text']; ?></pre>
  </div>
  <?php endforeach; ?>
</div>
<?php endforeach; ?>
