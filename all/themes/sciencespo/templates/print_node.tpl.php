<?php
// $Id: print.tpl.php,v 1.8.2.17 2010/08/18 00:33:34 jcnventura Exp $

/**
 * @file
 * Default print module template
 *
 * @ingroup print
 */
// //debug start *************************************
	// print '<pre>$node =';
	// // var_dump($node);
	// print_r($node);
	// print '</pre>';
	// exit;
// //debug end ***************************************
?>

<h1><?php print $node->title; ?></h1>
<h2><?php print $node->field_sous_titre[0]['view']; ?></h2>
<div><?php print $node->content['body']['#value']; ?></div>
<hr class="print-hr" />
<div><?php print $node->field_zone_de_droite[0]['view']; ?></div>
<hr class="print-hr" />

<h2><?php print t('More'); ?></h2>
<div>
<ul>
<?php
	foreach ($node->links_related as $link) {
		print '<li><a href="'.$link['url'].'">'.$link['link_title'].'</a></li>';
	}
?>

</ul>
</div>
