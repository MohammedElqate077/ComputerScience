<?php

function openConnexion(){
    $servername = "localhost";
    $db = "mysql:host=$servername;dbname=SMI2022";
    $username = "smi_root" ;
    $password = "smi2022";

    try{
        $connexion = new PDO($db, $username, $password);
    }catch(PDOException $dbex){
        $connexion = null;
        die("erreur de connexion : ") . $dbex ->getMessage();
    }
    return $connexion;
}

function sendMailt($mail){
   return mail($mail["to"],$mail["subject"],$mail["msg"],$mail["header"]);
}

function render($vue, array $var=array()){
    ob_start();
    require ($vue);
    $view = ob_get_clean();
    require("Views/needs/template.php");
}

?>
