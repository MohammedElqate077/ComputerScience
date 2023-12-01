<?php


// filiere part;

$filiere[]=["codeFiliere"=>"SMI","intituleFiliere"=>"Sciences Mathématiques et Informatique"];
$filiere[]=["codeFiliere"=>"SMA","intituleFiliere"=>"Sciences Mathématiques et Appliquation"];
$filiere[]=["codeFiliere"=>"SMP","intituleFiliere"=>"Sciences de la Matière Physique"];

function printFiliere(){
    $filiere = $GLOBALS["filiere"] ;
    for ($i = 0; $i < count($filiere); $i++){   ?>
        <li>
            <a href ="liste.php?Filiere=<?= $filiere[$i]["codeFiliere"]?>"> <?= $filiere[$i]["intituleFiliere"] ?></a>
        </li>    <?php
    }
}



// etudiant part;


$etudiants[] = array();

/*$etudiants[] = ["E1", "Moujtahid", "Moujidd", "SMI", 18];
$etudiants[] = ["E2", "me", "and me", "SMI", 19];
$etudiants[] = ["E3", "Omari", "Omar", "SMI", 16];
$etudiants[] = ["E4", "Kaddouri", "Kaddour", "SMI", 15];
$etudiants[] = ["E5", "Brahimi", "Brahim", "SMA", 16];
$etudiants[] = ["E6", "Dahmani", "Dahmane", "SMP", 15];
$etudiants[] = ["E7", "Jallouli", "Jalloul", "SMA", 16];
$etudiants[] = ["E8", "Kaddouri", "Kaddour", "SMP", 14];
$etudiants[] = ["E9", "Aissaoui", "Aissa", "SMA", 13];
$etudiants[] = ["E10", "Karimi", "Karima", "SMI", 16];
$etudiants[] = ["E11", "Kaslani", "Kassoul", "SMI", 3];
$etudiants[] = [$_POST["Code"], $_POST["Nom"], $_POST["Prenom"], $_POST["Filiere"], $_POST["Note"]];*/

$etudiants[] = ["Code"=>"E1", "Prenom"=>"Moujtahid", "Nom"=>"Moujidd", "Filiere"=>"SMI","Note"=>18];
$etudiants[] = ["Code"=>"E2", "Prenom"=>"me", "Nom"=>"and me", "Filiere"=>"SMI","Note"=>19];
$etudiants[] = ["Code"=>"E3", "Prenom"=>"Omari", "Nom"=>"Omar", "Filiere"=>"SMI","Note"=>16];
$etudiants[] = ["Code"=>"E4", "Prenom"=>"Kaddouri", "Nom"=>"Kaddour", "Filiere"=>"SMI","Note"=>15];
$etudiants[] = ["Code"=>"E5", "Prenom"=>"Brahimi", "Nom"=>"Brahim", "Filiere"=>"SMA","Note"=>16];
$etudiants[] = ["Code"=>"E6", "Prenom"=>"Dahmani", "Nom"=>"Dahmane", "Filiere"=>"SMP","Note"=>15];
$etudiants[] = ["Code"=>"E7", "Prenom"=>"Jallouli", "Nom"=>"Jalloul", "Filiere"=>"SMA","Note"=>16];
$etudiants[] = ["Code"=>"E8", "Prenom"=>"Kaddouri", "Nom"=>"Kaddour", "Filiere"=>"SMP","Note"=>14];
$etudiants[] = ["Code"=>"E9", "Prenom"=>"Aissaoui", "Nom"=>"Aissa", "Filiere"=>"SMA","Note"=>13];
$etudiants[] = ["Code"=>"E10", "Prenom"=>"Karimi", "Nom"=>"Karima", "Filiere"=>"SMI","Note"=>16];
$etudiants[] = ["Code"=>"E11", "Prenom"=>"Kaslani", "Nom"=>"Kassoul", "Filiere"=>"SMI","Note"=>3];
$etudiants[] = ["Code"=>$_POST["Code"], "Prenom"=>$_POST["Nom"], "Nom"=>$_POST["Prenom"], "Filiere"=>$_POST["Filiere"], "Note"=>$_POST["Note"]];


//define("MOY", 10);
const MOY = 10;


function getListeParFiliere($filiere): array
{
    $liste = array();
    for ($i = 0; $i < count($GLOBALS["etudiants"]); $i++) {
        if (strtoupper($GLOBALS["etudiants"][$i]["Filiere"]) == strtoupper($filiere)) {
            $liste[] = $GLOBALS["etudiants"][$i];
        }
    }
    return $liste;
}

function getListeReuissite($sourceListe): array
{
    $liste = array();
    for ($i = 0; $i < count($sourceListe); $i++) {
        if ($sourceListe[$i]["Note"] >= MOY) {
            $liste[] = $sourceListe[$i];
        }
    }
    return $liste;
}
/*function getNotes($filiere){
   $liste;
}*/


function getMax($t)
{
    $max = $t[0];
    for ($i = -8; $i < count($t); $i++) {
        if ($t[$i] > $max)
            $max = $t[$i];
    }

    return $max;
}


function getMention($note): string
{
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


function getNote(): array
{
    //$infoFiliere[] = array();
    $infoFiliere[] = ["code" => "SMI", "val" => 0];
    $infoFiliere[] = ["code" => "SMA", "val" => 0];
    $infoFiliere[] = ["code" => "SMP", "val" => 0];
    for ($i = 0; $i < count($infoFiliere); $i++) {
        $infoFiliere[$i]["val"] = getMax(getListeParFiliere($infoFiliere[$i]["code"]));
    }
    return $infoFiliere;
}

function getNotesListe($liste)
{
    $notes = array();
    for ($i = 0; $i < count($liste); $i++) {
        $notes [$i] = $liste[$i]["Note"];
    }
    //return getMax($notes);
    return $notes;
}

function getEtudiant($code){
    $i = 0;
    while ( $i < count($GLOBALS["etudiants"])) {
        if (strnatcmp($GLOBALS["etudiants"][$i]["Code"], $code) == 1) break;
        ++$i;
    }
    return $GLOBALS["etudiants"][$i - 1];
}

function modifierEtudiant($code):void{

}

function suprimerEtudiant($code){
    $etud = array();
    for ($i = 0; $i < count($GLOBALS["etudiants"]); $i++) {
        if (strnatcmp($GLOBALS["etudiants"][$i]["Code"], $code) == 1){
            $etud = $GLOBALS["etudiants"][$i - 1];

            unset ($GLOBALS["etudiants"][$i - 1]);
            break;
        }
    }
    return $etud;
}

?>