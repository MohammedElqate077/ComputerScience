

<h1 align="center">Afficher Des Resultas</h1>
<hr/> <br/>


<?php

//$filiere = getListeFiliere();
$filiere = $var["filiere"];
echo "<li><a href =\"../index.php?action=Etudiant&CodeF=\"\"> toutes les etudiants </a></li>";
for ($i = 0; $i < count($filiere); $i++){   ?>
    <li>
        <a href ="../index.php?action=etudiant&CodeF=<?= $filiere[$i]["CodeF"]?>"> <?= $filiere[$i]["IntituleF"] ?></a>
    </li>    <?php
}

?>


