<?php

$filiere = $var ["filiere"];

for ($i = 0; $i < count($filiere); $i++){   ?>
    <li>
        <a href ="../../index.php?action=liste&Filiere=<?= $filiere[$i]["CodeF"]?>"> <?= $filiere[$i]["IntituleF"] ?></a>
    </li>    <?php
}

?>
