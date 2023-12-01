<?php
session_start();
$_SESSION["fileName"] = "insert.php";

require 'data.php';
include 'haut.php';

if(isset($_SESSION["LoginUsername"])==0){
    require 'login.php';
    exit();
}


addEtudiant($_POST);

$location = "liste.php?Filiere=".$_POST["Filiere"];
header("location:$location");

?>


