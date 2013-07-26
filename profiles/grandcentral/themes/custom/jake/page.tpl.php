<?php include 'page.header.inc'; ?>


<div id='left'><div class='navbar clear-block'>
  <?php if (!empty($page['context_links'])): ?>
    <div class='context-links clearfix'><?php print render($page['context_links']); ?></div>
  <?php endif; ?>
  <?php print render($page['sidebar_first']) ?>
</div></div>

<div id='canvas' class='clearfix'>

  <?php include 'page.title.inc'; ?>

  <?php if ($show_messages && $page['messages']): ?>
    <div class='growl'><?php print render($page['messages']); ?></div>
  <?php endif; ?>

  <div id='main'>
    <div id='content' class='page-content clearfix'>
      <div id='content-wrapper'><?php print render($page['content']) ?></div>
      <div id='content-region-wrapper'><?php print render($page['content_region']); ?></div>
    </div>
  </div>

  <?php if ($page['sidebar_second']): ?>
    <div id='right'><div class='sidebar clearfix'>
      <?php print render($page['highlighted']); ?>
      <?php print render($page['sidebar_second']) ?>
    </div></div>
  <?php endif; ?>

</div>

<?php include 'page.footer.inc'; ?>
