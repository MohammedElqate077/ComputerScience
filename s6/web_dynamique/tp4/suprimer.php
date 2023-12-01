<?php
include 'haut.php';
include 'data.php';

$etudiant = suprimerEtudiant($_GET["Code"]);

?>

<h1> Detail De L'Etudiant : <?=$etudiant["Code"] ?></h1><hr/><br/>

<b> Code :    <?= $etudiant["Code"]    ?>  </b><br />
<b> Nom :     <?= $etudiant["Nom"]     ?>  </b><br />
<b> Prénom :  <?= $etudiant["Prenom"]  ?>  </b><br />
<b> Filière : <?= $etudiant["Filiere"] ?>  </b><br />
<b> Note :    <?= $etudiant["Note"]    ?>  </b><br /><br/>

<?php
include 'bas.php';
?>

