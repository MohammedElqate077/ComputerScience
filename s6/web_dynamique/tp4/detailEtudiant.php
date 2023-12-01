<?php
include 'haut.php';
require 'data.php';

$filiereEtudaint = $_GET["Filiere"];
$codeEtudiant = $_GET["Code"];
$etud = getEtudiant($codeEtudiant);
?>

<h1> Detail De L'Etudiant : <?=$codeEtudiant ?></h1><hr/><br/>

<b> Code :    <?= $etud["Code"]    ?>  </b><br />
<b> Nom :     <?= $etud["Nom"]     ?>  </b><br />
<b> Prénom :  <?= $etud["Prenom"]  ?>  </b><br />
<b> Filière : <?= $etud["Filiere"] ?>  </b><br />
<b> Note :    <?= $etud["Note"]    ?>  </b><br /><br/>

<div align="center">
    <a href="modifierr.php?Code<?=$codeEtudiant?>" >Modifier </a> &nbsp; &nbsp; &nbsp;
    <a href="suprimerr.php?Code<?=$codeEtudiant?>" >Suprimmer</a>
</div>


<?php include 'bas.php' ?>
