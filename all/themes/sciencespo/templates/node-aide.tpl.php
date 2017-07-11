<?php
// $Id: node.tpl.php,v 1.10 2009/11/02 17:42:27 johnalbin Exp $

/**
 * @file
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 *   The following applies only to viewers who are registered users:
 *   - node-by-viewer: Node is authored by the user currently viewing the page.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $build_mode: Build mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $build_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * The following variables are deprecated and will be removed in Drupal 7:
 * - $picture: This variable has been renamed $user_picture in Drupal 7.
 * - $submitted: Themed submission information output from
 *   theme_node_submitted().
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see zen_preprocess()
 * @see zen_preprocess_node()
 * @see zen_process()
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix">
  <?php print $user_picture; ?>

  <?php if ($type == 'aide'): ?>
    <h1 class="title-article">
		<?php 
			// global $base_url;
			// global $language;
			// $p = preg_replace('/\/.*\/.*\/(.*)\/(.*)/', $base_url.'/'.$language->language.'/$1/$2', $node_url);
			// print l($title, $p, array('html' => true));
			print $title;
		?>
	</h1>
  <?php endif; ?>

  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>

  <?php if ($display_submitted || $terms): ?>
    <div class="meta">
      <?php if ($display_submitted): ?>
        <span class="submitted">
          <?php
            print t('Submitted by !username on !datetime',
              array('!username' => $name, '!datetime' => $date));
          ?>
        </span>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <div class="content">
    <?php 
		print $content; 

	//affichage des liens "pour en savoir plus"
		//V2.4 = suppression des liens de traduction
		$links = preg_replace('/<li class="node_translation_(.*)<\/a><\/li>/', '', $links);	

		$links = str_replace('<ul class="links inline">', '<div class="related_links"><h2>'.t('More').'</h2><ul class="couleur-principale">', $links);	
		$links = str_replace('</ul>', '</ul></div>', $links);	
		$links = str_replace('Visit ', '', $links);
		if(strstr($links, '</li>')){
			print $links; 
		}

	?>
  </div>


</div> <!-- /.node -->


<div class="share-bar">
	<table class="imprimer">
		<tr>
			<td>
				<!-- AddThis Button BEGIN -->
				<a href="#" class="addthis_button_compact"></a>
				<?php global $base_url; print '<a href="#"><img src="'.$base_url.'/sites/all/themes/sciencespo/images/icon_trait.png" /></a>'; ?>
				<a href="#" class="addthis_button_google"></a>
				<a href="#" class="addthis_button_twitter"></a>
				<a href="#" class="addthis_button_facebook"></a>
				<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=ra-4e369a6205d16b1e"></script>
				<!-- AddThis Button END -->
				<?php 
					global $language;
					global $base_url;
					
					$options = array();
					$options['language'] = $language->language;
					$options['html'] = TRUE;
					
					$print_icon = l('<img src="'.$base_url.'/sites/all/themes/sciencespo/images/icon_print.png" />', 'print/'.$node->nid, $options);
					// $print_icon = '<a href="'.$base_url.'/'.$language->language.'/print/'.$node->nid.'"><img src="'.$base_url.'/sites/all/themes/sciencespo/images/icon_print.png" /></a>';
					$mail_icon = l('<img src="'.$base_url.'/sites/all/themes/sciencespo/images/icon_mail.png" />', 'printmail/'.$node->nid, $options);
					// $mail_icon = '<a href="'.$base_url.'/'.$language->language.'/printmail/'.$node->nid.'"><img src="'.$base_url.'/sites/all/themes/sciencespo/images/icon_mail.png" /></a>';
					$pdf_icon = l('<img src="'.$base_url.'/sites/all/themes/sciencespo/images/icon_pdf.png" />', 'printpdf/'.$node->nid, $options);
					// $pdf_icon = '<a href="'.$base_url.'/'.$language->language.'/printpdf/'.$node->nid.'"><img src="'.$base_url.'/sites/all/themes/sciencespo/images/icon_pdf.png" /></a>';

					print $print_icon;
					print $mail_icon;
					print $pdf_icon;
				?>
			</td>
		</tr>
	</table>
</div>
<?php if ($terms): 
	$title = t("Voir tous les contenus relatifs à ");
	$terms = preg_replace('/title="(.*?)"/', 'title="'.$title.'$1"', $terms);
?>
	<div class="terms-container">
		<div class="terms terms-inline"><span lang="en">Tags</span> : <?php print $terms; ?></div>
	</div>
<?php endif; ?>
