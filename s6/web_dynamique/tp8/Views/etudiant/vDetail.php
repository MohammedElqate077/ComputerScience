<?php

$etud = $var["etud"];
$codeEtudiant = $etud["CodeE"];
$f = $etud["Filiere"];

?>

<h1> Detail De L'Etudiant : <?=$codeEtudiant ?></h1><hr/><br/>

<b> Code :    <?= $etud["CodeE"]    ?>  </b><br />
<b> Nom :     <?= $etud["Nom"]     ?>  </b><br />
<b> Prénom :  <?= $etud["Prenom"]  ?>  </b><br />
<b> Filière : <?= $etud["Filiere"] ?>  </b><br />
<b> Note :    <?= $etud["Note"]    ?>  </b><br /><br/>

<div align="center">
    <a href="../../index.php?action=modifier&Code=<?=$codeEtudiant?>&Filiere=<?=$f?>" >Modifier </a> &nbsp; &nbsp; &nbsp;
    <a href="../../index.php?action=supprimer&Code=<?=$codeEtudiant?>&Filiere=<?=$f?>" >Supprimer</a>
</div>


