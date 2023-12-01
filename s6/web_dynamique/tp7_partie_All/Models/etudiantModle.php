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

function getListeFiliere(){
    //$connexion = $GLOBALS["connexion"];
    $connexion = openConnexion();
    $req = "select * from Filiere";
    return  $connexion->query($req)->fetchAll();
}

//function getListeEtudiant($filiere){
function getListeEtudiant($CodeF){
    //$connexion = $GLOBALS["connexion"];
    $connexion = openConnexion();
    if(empty($CodeF) || $CodeF == null)
        $req = "select * from Etudiant";
    else
        $req = "select * from Etudiant where Filiere = '$CodeF'";
    return $connexion->query($req)->fetchAll();
}


function getEtudiant($code){
    $connexion = openConnexion();
    $req = "select * from Etudiant where CodeE='$code'";
    return $connexion->query($req)->fetch();
}

function ajouterEtudiant($e):bool{
    $connexion = openConnexion();
    $code = $e["CodeE"];
    $nom = $e["Nom"];
    $prenom = $e["Prenom"];
    $filiere = $e["Filiere"];
    $note = $e["Note"];

    $req = $connexion->prepare("insert into Etudiant values(:code,:nom,:prenom,:filiere,:note)");
    $req->bindParam(':code',$code);
    $req->bindParam(':nom',$nom);
    $req->bindParam(':prenom',$prenom);
    $req->bindParam(':filiere',$filiere);
    $req->bindParam(':note',$note);
    if($req->execute())
        return true;
    else return false;
}

function supprimerEtudiant ($c):bool {
    $connexion = openConnexion();
    //$req = $connexion->query("delete from Etudiant where CodeE = '$c'");
    $req = $connexion->prepare("delete from Etudiant where CodeE = :code");
    $req->bindParam(':code',$c);
    if($req->execute()){
        return true;
    }
    return false;
}

function modifierEtudiant($e,$id){
    $connexion = openConnexion();
    $code = $e["CodeE"];
    $nom = $e["Nom"];
    $prenom = $e["Prenom"];
    $filiere = $e["Filiere"];
    $note = $e["Note"];
    $req = $connexion->prepare("update Etudiant
     set CodeE=:code, Nom=:nom, Prenom=:prenom, Filiere=:filiere, Note=:note
     where CodeE=:id");
     $req->bindParam(':code',$code);
     $req->bindParam(':id',$id);
     $req->bindParam(':nom',$nom);
     $req->bindParam(':prenom',$prenom);
     $req->bindParam(':filiere',$filiere);
     $req->bindParam(':note',$note);
     if($req->execute())
         return true;
     else return false;
}

function firstInFiliere($CodeF){
    $connextion = openConnexion();
    if(empty($CodeF) || $CodeF == null)
        $req = "select * from Etudiant order by Note desc limit 1";
    else
        $req = "select * from Etudiant where Filiere = '$CodeF' order by Note desc  limit 1";
    return $connextion->query($req)->fetch();
}

?>
