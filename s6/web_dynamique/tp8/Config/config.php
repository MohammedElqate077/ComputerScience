<?php

function openConnexion(){
    $servername = "localhost";
    $db = "mysql:host=$servername;dbname=DBNAME";
    $username = "USERNAME" ;
    $password = "PASSWORD";

    try{
        $connexion = new PDO($db, $username, $password);
    }catch(PDOException $dbex){
        $connexion = null;
        die("erreur de connexion : ") . $dbex ->getMessage();
    }
    return $connexion;
}

function render($vue, array $var=array()){
    ob_start();
    require ($vue);
    $view = ob_get_clean();
    require("Views/needs/template.php");
}

?>
