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

function getListFiliereFromDb(){
    $connexion = $GLOBALS["connexion"];
    $req = "select * from Filiere";
    return  $connexion->query($req)->fetchAll();
}

function getListeEtudiantFromDb($filiere){
    $connexion = $GLOBALS["connexion"];
    $req = "select * from Etudiant where Filiere = '$filiere'";
    return $connexion->query($req)->fetchAll();
}



function addEtudiant($e){
    $connexion = $GLOBALS["connexion"];
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
        echo "inserted succes";
    else echo "faild to insert\n";
}

function supprimerEtudiant ($c):bool {
    $connexion = $GLOBALS["connexion"];
    //$req = $connexion->query("delete from Etudiant where CodeE = '$c'");
    $req = $connexion->prepare("delete from Etudiant where CodeE = :code");
    $req->bindParam(':code',$c);
    if($req->execute()){
       return true;
    }
    return false;
}



function printFiliere(){
    $filiere = getListFiliereFromDb();
    for ($i = 0; $i < count($filiere); $i++){   ?>
        <li>
            <a href ="liste.php?Filiere=<?= $filiere[$i]["CodeF"]?>"> <?= $filiere[$i]["IntituleF"] ?></a>
        </li>    <?php
    }
}

const MOY = 10;

function getMax($t){
    $max = $t[0];
    for ($i = 0; $i < count($t); $i++) {
        if ($t[$i] > $max)
            $max = $t[$i];
    }
    return $max;
}


function getMention($note): string{
    if (0 <= $note and $note < MOY)
        return "Ajourné!";
    elseif (MOY <= $note && $note < 12)
        return "PASSABLE";
    elseif (12 <= $note && $note < 14)
        return "ASSEZ BIEN";
    elseif (14 <= $note && $note < 16)
        return "BIEN";
    elseif (16 <= $note && $note <= 20)
        return "TRES BIEN";
    else
        return "Note non valide!";
}

function getNotesListe($liste){
    $notes = array();
    for ($i = 0; $i < count($liste); $i++) {
        $notes [$i] = $liste[$i]["Note"];
    }
    return $notes;
}

function getEtudiant($code){
    $connexion = $GLOBALS["connexion"];
    $req = "select * from Etudiant where CodeE='$code'";
    return $connexion->query($req)->fetch();
}

function getNote(): array{
    $infoFiliere[] = ["code" => "SMI", "val" => 0];
    $infoFiliere[] = ["code" => "SMA", "val" => 0];
    $infoFiliere[] = ["code" => "SMP", "val" => 0];
    for ($i = 0; $i < count($infoFiliere); $i++) {
        $infoFiliere[$i]["val"] = getMax(getListeEtudiantFromDb($infoFiliere[$i]["code"]));
    }
    return $infoFiliere;
}



$connexion = openConnexion();
?>
