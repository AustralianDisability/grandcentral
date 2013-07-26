<?php include 'page.header.inc'; ?>

<div id='left'><div class='navbar clear-block'>
  <?php if (!empty($page['context_links'])): ?>
    <div class='context-links clear-block'><?php print render($page['context_links']) ?></div>
  <?php endif; ?>
  <?php if (!empty($page['left'])) print render($page['left']) ?>
</div></div>

<div id='canvas' class='clear-block'>

  <?php include 'page.title.inc'; ?>

  <?php if ($show_messages && $messages): ?>
    <div class='growl'><?php print $messages; ?></div>
  <?php endif; ?>

  <div id='main'>
    <div id='content' class='page-content clear-block'>
      <h2> Temp :: layout-sidebar.template</h2>
      <div id='content-wrapper'><?php print render($page['content']) ?></div>
      <div id='content-region-wrapper'><?php print render($page['content_region']) ?></div>
    </div>
  </div>

</div>

<?php include 'page.footer.inc'; ?>