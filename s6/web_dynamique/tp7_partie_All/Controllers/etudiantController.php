<?php
session_start();
require_once("Models/etudiantModle.php");

function index(array $t){
    $view = "Views/needs/vHome.php";
    render($view);
}

function liste(){
    //$f = !empty($_GET["Filiere"])? $_GET["Filiere"]: "";
    if(empty($_GET["Filiere"])){
        $f = "";
        $isAll = true;
    }else $f = $_GET["Filiere"];
    $etudiant = getListeEtudiant($f);
    $max = firstInFiliere($f);
    $view = "Views/etudiant/vEtudiant.php";
    render($view,["etudiant"=>$etudiant,"filiere"=>$f,"isAll"=>$isAll,"max"=>$max]);
}

function filiere(){
    $filieres = getListeFiliere();
    $view = "Views/etudiant/vListe.php";
    render($view,["filiere"=>$filieres]);
}

function ajouter(){
    $view = "Views/etudiant/vAjouter.php";
    if($_SERVER["REQUEST_METHOD"]=="POST"){
        if(ajouterEtudiant($_POST)){
            $f = $_POST["Filiere"];
            header("location:index.php?action=liste&Filiere=$f");
            exit();
        }
    }
    render($view);
}

function modifier(){
    $view = "Views/etudiant/vAjouter.php";
    $id = $_GET["Code"];
    if($_SERVER["REQUEST_METHOD"]=="POST"){
        if(modifierEtudiant($_POST,$id)){
            $f = $_POST["Filiere"];
            header("location:index.php?action=liste&Filiere=$f");
            //header("location:index.php");
            exit();
        }
    }
    render($view);
}

function supprimer(){
    $c = $_GET["Code"];
    if(supprimerEtudiant($c)){
        $f = $_GET["Filiere"];
        $location = "index.php?action=liste&Filiere=$f";
        header("location:$location");
        exit();
    }
    header("location:index.php?action=detail&id=$c");
}

function detail(){
   $e = getEtudiant($_GET["id"]);
   $view = "Views/etudiant/vDetail.php";
   render($view,["etud"=>$e]);
}

function render($vue, array $var=array()){
    ob_start();
    require ($vue);
    $view = ob_get_clean();
    require("Views/needs/template.php");
}


?>