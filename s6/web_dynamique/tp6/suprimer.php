<?php
session_start();
$_SESSION["fileName"] = "suprimer.php";
$_SESSION["lastCodeE"] = $_GET["Code"];
$_SESSION["lastFiliere"] = $_GET["Filiere"];

if(isset($_SESSION["LoginUsername"])==0){
    require 'login.php';
    exit();
}

require 'data.php';
//suprimerEtudiant($_GET["Code"]);
if(supprimerEtudiant($_GET["Code"])){
    echo '<script type="text/JavaScript">
            alert("element deleted");
            </script>';
}else{
    echo '<scrip type="text/JavaScript">
            alert("element not deleted");
            </script>';
}

$location = "liste.php?Filiere=".$_GET["Filiere"];
header("location:$location");


?>
