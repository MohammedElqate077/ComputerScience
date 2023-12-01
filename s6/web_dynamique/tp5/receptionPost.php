<?php
include 'haut.php';
?>
<div align="center">
<br />Bonjour <?= $_POST["Nom"] . " " . $_POST["Prenom"] ?>
<br />Votre mot de passe est  <?= $_POST["Password"] ?>
<br />Votre sexe est : <?= $_POST["Sex"] ?>
<br />Votre filière est : <?= $_POST["Filiere"] ?>
</div>
<br />Vos loisirs:
<ul >
    <?php
    foreach ($_POST["S"] as $loisir)
        echo "<li>" . $loisir  . "</li>"?>
</ul>
<br />Vous avez entré le commentaire suivant:
<p><?= $_POST["Commentaire"] ?></p>
    <br/>


<hr/><br/>
<h1>Informations environnement</h1>

<br /><b>Votre adresse ($_SERVER["REMOTE_ADDR"]):</b>  <?= $_SERVER["REMOTE_ADDR"] ?>
<br /><b>Votre Navigateur ($_SERVER["HTTP_USER_AGENT"]):</b> <?= $_SERVER["HTTP_USER_AGENT"] ?>
<br /><b>Vous étiez sur la page($_SERVER["HTTP_REFERER"]): </b> <?= $_SERVER["HTTP_REFERER"] ?>
<br /><b>Vous êtes actuellement dans le script ($_SERVER["PHP_SELF"]): </b> <?= $_SERVER["PHP_SELF"] ?>
<br /><b>Vous êtes actuellement dans le script(__FILE__): </b> <?= __FILE__ ?>
<br /><b>à la ligne (__LINE__):  <?= __LINE__ ?>
<br /><b>Répertoire (__DIR__):  <?= __DIR__ ?>
<br /><b>La version de PHP tournée par le serveur (PHP_VERSION):  </b> <?= PHP_VERSION ?>
<br /><b>Le système d'exploitation du seveur (PHP_OS):  </b> <?= PHP_OS ?><br/>


 <?php
include 'bas.php'
?>
