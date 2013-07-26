<div class='utility clearfix'>

<?php
$delete = jake_views_render_field($fields['link_delete']);
if ($delete):
?>
<div class='utility-links clearfix'><?php var_dump(__FILE__,$edit); print $edit ?><?php print $delete ?></div>
<?php endif; ?>

<?php print jake_views_render_field($fields['title']) ?>

</div>