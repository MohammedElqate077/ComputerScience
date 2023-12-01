
<?php
session_start();
//$_SESSION[""]
$_SESSION["fileName"] = "listeFiliere.php";

if(isset($_SESSION["LoginUsername"])==0){
    require 'login.php';
    exit();
}
include 'haut.php';

    require 'data.php'
?>

<h1 align="center">Afficher Des Resultas</h1>
<hr/> <br/>

<?php printFiliere() ?>

<?php include 'bas.php' ?>

<?php getListeParFiliere("SMI"); ?>
