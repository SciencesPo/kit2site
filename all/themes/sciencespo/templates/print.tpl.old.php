<?php
// $Id: print.tpl.php,v 1.8.2.17 2010/08/18 00:33:34 jcnventura Exp $

/**
 * @file
 * Default print module template
 *
 * @ingroup print
 */
// //debug start *************************************
// 	print '<pre>$print[css] =';
// 	// var_dump($print['css']);
// 	print_r($print['css']);
// 	print '</pre>';
// 	exit;
// //debug end ***************************************
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $print['language']; ?>" xml:lang="<?php print $print['language']; ?>">
  <head>
    <?php print $print['head']; ?>
    <?php print $print['base_href']; ?>
    <title><?php print $print['title']; ?></title>
    <?php print $print['scripts']; ?>
    <?php print $print['sendtoprinter']; ?>
    <?php print $print['robots_meta']; ?>
    <?php print $print['favicon']; ?>
    <?php print $print['css']; ?>
  </head>
  <body>
	<div class="print-logo"><?php print $print['logo']; ?><?php print $print['site_name']; ?></div>
    <div class="print-breadcrumb"><?php print $print['breadcrumb']; ?></div>
    <div class="print-content"><?php print $print['content']; ?></div>
    <div class="print-footer"><?php print $print['footer_message']; ?></div>
  </body>
</html>