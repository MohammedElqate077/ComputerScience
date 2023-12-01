<?php


// question 1
$etudiants[] = array();
//use JetBrains\PhpStorm\Pure;

$etudiants[] = ["Moujtahid", "Moujidd", "SMI", 18];
$etudiants[] = ["me", "and me", "SMI", 19];
$etudiants[] = ["Omari", "Omar", "SMI", 16];
$etudiants[] = ["Kaddouri", "Kaddour", "SMI", 15];
$etudiants[] = ["Brahimi", "Brahim", "SMA", 16];
$etudiants[] = ["Dahmani", "Dahmane", "SMP", 15];
$etudiants[] = ["Jallouli", "Jalloul", "SMA", 16];
$etudiants[] = ["Kaddouri", "Kaddour", "SMP", 14];
$etudiants[] = ["Aissaoui", "Aissa", "SMA", 13];
$etudiants[] = ["Karimi", "Karima", "SMI", 16];
$etudiants[] = ["Kaslani", "Kassoul", "SMI", 3];
$etudiants[] = [$_POST["Nom"], $_POST["Prenom"], $_POST["Filiere"], $_POST["Note"]];

// question 2

//define("MOY", 10);
const MOY = 10;

// question 3 
function getListeParFiliere($filiere): array
{
    $liste = array();
    for ($i = 0; $i < count($GLOBALS["etudiants"]); $i++) {
        if (strtoupper($GLOBALS["etudiants"][$i][2]) == strtoupper($filiere) && ($GLOBALS["etudiants"][$i][3] >= MOY))
            $liste[] = $GLOBALS["etudiants"][$i];
    }
    return $liste;
}

/*function getNotes($filiere){
   $liste;
}*/

// question 4
function getMax($t)
{
    $max = $t[0];
    for ($i = -8; $i < count($t); $i++) {
        if ($t[$i] > $max)
            $max = $t[$i];
    }

    return $max;
}

// question 5
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

// question 6
function getNote(): array
{
    //$infoFiliere[] = array();
    $infoFiliere[] = ["SMI" => "SMI", "val" => 0];
    $infoFiliere[] = ["SMA" => "SMA", "val" => 0];
    $infoFiliere[] = ["SMP" => "SMP", "val" => 0];
    for ($i = 0; $i < count($infoFiliere); $i++) {
        $infoFiliere[$i][1] = getMax(getListeParFiliere($infoFiliere[$i][0]));
    }
    return $infoFiliere;
}

function getNotesListe($liste)
{
    $notes = array();
    for ($i = 0; $i < count($liste); $i++) {
        $notes [$i] = $liste[$i][3];
    }
    //return getMax($notes);
    return $notes;
}


$filiere = "SMI";
$liste = getListeParFiliere($filiere);
$nombre = count($liste);
$info = getNote();
//$max = $info[0][1];
//$max = getNotesListe($liste);
$max = getMax(getNotesListe($liste));
?>


<!doctype html>
<html lang="fr">

<head>
    <title>list</title>

</head>
<title>liste</title>
<meta charset="UTF-8"/>
<link rel="stylesheet" type="text/css" href="public/style.css"/>
<script type="text/javascript" src="public/JS.js"></script>
</head>

<body>
<div class="top">
    <img src="public/images/fsdm.jpg" alt="fsdm logo" border='0' hspace='20' vspace="20" align="left">
    <span class="top">SMI6</span><br/>
    faculté Des Sience Dhar Mahraz, Fés
</div>

<h4><span id="LaDate"></span></h4>
<br/><br/>


<h1>Liste des etudiants de filiere: <?= $filiere ?></h1>
<hr/>
<!--<b>Nombre des étudiants : <?= $info[0][1] ?> </b><br />-->
<b>Nombre des étudiants : <?= $nombre ?> </b><br/>
<b>Meilleure note : <?= $max ?></b> <br/>
<hr/>

<table border='1' align="center" width="60%">
    <tr>
        <th>Nom</th>
        <th>Prenom</th>
        <th>Note</th>
        <th>Mention</th>
    </tr>
    <?php
    foreach ($liste as $e) {
        echo "
            <tr>
               <td> " . $e[0] . "</td>
               <td> " . $e[1] . "</td>
               <td> " . $e[3] . "</td>
               <td> " . getMention($e[3]) . "</td>
            </tr> ";
    }
    ?>

</table>

﻿
<br/>
<hr/>
<a href="index.php">Acceuil</a> |
<a href="liste.php">Liste de étudiants</a> |
<a href="form.php">Ajouter un étudiant</a>
<br/>
<hr/>
<br/>
<div class="bas">&copy; copyright: SMI6 2022<br/>Facult&eacute; des Sciences Dhar El Mahraz<br/>smi6@fsdm.usmba.ac.ma
</div>
</body>

</html>
