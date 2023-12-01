<?php

$etud = $var["detaillEtudiant"];
?>

<h1> Detail De L'Etudiant : <?=$etud["CodeE"] ?></h1><hr/><br/>

<b> Code :    <?= $etud["CodeE"]    ?>  </b><br />
<b> Nom :     <?= $etud["Nom"]     ?>  </b><br />
<b> Prénom :  <?= $etud["Prenom"]  ?>  </b><br />
<b> Filière : <?= $etud["Filiere"] ?>  </b><br />
<b> Note :    <?= $etud["Note"]    ?>  </b><br /><br/>

<div align="center">
    <a href="../index.php?action=modifier&id=<?=$etud["CodeE"]?>&Filiere=<?=$etud["Filiere"]?>" >Modifier </a> &nbsp; &nbsp; &nbsp;
    <a href="../index.php?action=suprimer&id=<?=$etud["CodeE"]?>&Filiere=<?=$etud["Filiere"]?>" >Suprimmer</a>
</div>


<?php include 'bas.php' ?>

