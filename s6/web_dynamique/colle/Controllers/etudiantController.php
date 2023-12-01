<?php
//session_start();
require_once("Models/etudiantManager.php");



function liste(){
    //$f = !empty($_GET["Filiere"])? $_GET["Filiere"]: "";
    $isAll = false;
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
    $var["filiere"] = getListeFiliere();
    if($_SERVER["REQUEST_METHOD"]=="POST"){
        $etudiant = $_POST;
        if(empty($etudiant["CodeE"]))   $erreur["CodeE"]   ="Le code est vide !..."   ;
        if(empty($etudiant["Nom"]))     $erreur["Nom"]    ="Le Nom est vide !...."   ;
        if(empty($etudiant["Prenom"]))  $erreur["Prenom"] ="Le prénom est vide !..." ;
        if(empty($etudiant["Filiere"])) $erreur["Filiere"]="Sélectionnez une filière !...";
        if(empty($etudiant["Note"])) $erreur["Note"]="La Note est vide !...";
        else if(!is_Numeric($etudiant["Note"])) $erreur["Note"]="La Note doit être un un nombre !...";
        else if($etudiant["Note"] < 0 or $etudiant["Note"] > 20) $erreur["Note"]="La Note doit être entre 0 et 20 !...";


        if(!isset($erreur) && ajouterEtudiant($_POST)){
            $f = $_POST["Filiere"];
            header("location:index.php?action=liste&Filiere=$f");
            exit();
        }

        $var["erreur"]["CodeE"] =   $erreur["CodeE"]??"";
        $var["erreur"]["Nom"] =     $erreur["Nom"]??"";
        $var["erreur"]["Prenom"] =  $erreur["Prenom"]??"";
        $var["erreur"]["Filiere"] = $erreur["Filiere"]??"";
        $var["erreur"]["Note"] =    $erreur["Note"]??"";
        $var["etud"] = $etudiant;
    }
    else $var["etud"]["Filiere"] = $_GET["Filiere"]??"";
    render($view,$var);
}

function modifier(){
    $view = "Views/etudiant/vAjouter.php";
    $id = $_GET["Code"];
    $var["filiere"] = getListeFiliere();
    if($_SERVER["REQUEST_METHOD"]=="POST"){
        $etudiant = $_POST;
        if(empty($etudiant["CodeE"]))   $erreur["CodeE"]   ="Le code est vide !..."   ;
        if(empty($etudiant["Nom"]))     $erreur["Nom"]    ="Le Nom est vide !...."   ;
        if(empty($etudiant["Prenom"]))  $erreur["Prenom"] ="Le prénom est vide !..." ;
        if(empty($etudiant["Filiere"])) $erreur["Filiere"]="Sélectionnez une filière !...";
        if(empty($etudiant["Note"])) $erreur["Note"]="La Note est vide !...";
        else if(!is_Numeric($etudiant["Note"])) $erreur["Note"]="La Note doit être un un nombre !...";
        else if($etudiant["Note"] < 0 or $etudiant["Note"] > 20) $erreur["Note"]="La Note doit être entre 0 et 20 !...";

        if(!isset($erreur) && modifierEtudiant($_POST,$id)){
            $c = $_POST["CodeE"];
            header("location:index.php?action=detail&id=$c");
            exit();
        }

        $var["erreur"]["CodeE"] =   $erreur["CodeE"]??"";
        $var["erreur"]["Nom"] =     $erreur["Nom"]??"";
        $var["erreur"]["Prenom"] =  $erreur["Prenom"]??"";
        $var["erreur"]["Filiere"] = $erreur["Filiere"]??"";
        $var["erreur"]["Note"] =    $erreur["Note"]??"";
        $var["etud"] = $etudiant;
    }else {
        $var["etud"] = getEtudiant($id);
    }
    render($view,$var);
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




?>