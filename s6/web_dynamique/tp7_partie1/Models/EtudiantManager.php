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
    if(empty($CodeF))
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


function addEtudiant($e){
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
        echo "inserted succes";
    else echo "faild to insert\n";
}

function supprimerEtudiant ($c):bool{
    $connexion = openConnexion();
    $req = $connexion->prepare("delete from Etudiant where CodeE = :code");
    $req->bindParam(':code', $c);
    if ($req->execute()) {
        return true;
    }
    return false;
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

function getListeMention($listeEtudiant){
    $mention = array() ;
    foreach ($listeEtudiant as $e){
        $mention = getMention($e["Note"]);
    }
    return $mention;
}

?>
