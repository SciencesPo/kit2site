<?php if ($arguments['titre']) { ?>
	<h1><?php print $arguments['titre']; ?></h1>
<?php } ?>

<?php if ($arguments['extrait_du_titre']) { ?>
	<h1><?php print $arguments['extrait_du_titre']; ?></h1>
<?php } ?>

<?php if ($arguments['sous-titre']) { ?>
	<div class="sous_titre"><?php print $arguments['sous-titre']; ?></div>
<?php } ?>

<?php if ($arguments['extrait_du_sous-titre']) { ?>
	<div class="sous_titre"><?php print $arguments['extrait_du_sous-titre']; ?></div>
<?php } ?>

<div class="border"></div>


<?php if ($arguments['carrousel']) { ?>
	<div id="carousel_zone4" class="carrousel clearfix">
		<?php print theme_carousel('#carousel_zone4', $arguments['carrousel'], array('ratio' => true)); ?>
	</div>
<?php } ?>

<?php if ($arguments['texte']) { ?>
	<div class="texte"><?php print $arguments['texte']; ?></div>
<?php } ?>

<?php if ($arguments['extrait_du_texte']) { ?>
	<div class="texte"><?php print $arguments['extrait_du_texte']; ?></div>
<?php } ?>

<?php if ($arguments['exergue']) { ?>
	<div class="exergue couleur-secondaire"><?php print $arguments['exergue']; ?></div>
<?php } ?>

<?php if ($arguments['extrait_de_exergue']) { ?>
	<div class="exergue couleur-secondaire"><?php print $arguments['extrait_de_exergue']; ?></div>
<?php } ?>


