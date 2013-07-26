<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
<?php print $head ?>
<?php print $styles ?>
<?php print $scripts ?>
<title><?php print $head_title ?></title>
</head>

<body <?php print drupal_attributes($attr) ?>>
<?php if (!empty($page['admin'])) print render($page['admin']) ?>

<?php if ($page['header']): ?><div id="header" class='clear-block'><?php print render($page['header']); ?></div><?php endif; ?>

<div id='branding' class='clear-block'>
  <?php if ($admin_link): ?><div class="admin-link"><?php print $admin_link; ?></div><?php endif; ?>
  <?php if ($site_name): ?><h1 class='site-name'><?php print $site_name ?></h1><?php endif; ?>
  <?php if ($site_slogan): ?><div class='site-slogan'><?php print $site_slogan ?></div><?php endif; ?>
  <div class="help-link"><?php if ($help_link) print $help_link; ?></div>
  <?php if (isset($main_menu)) : ?>
    <?php print theme('links', $main_menu, array('class' => 'links main-menu')) ?>
  <?php endif; ?>
</div>
