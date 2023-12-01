<?php
/*
//$filiere = "SMI";
$filiere = $_GET["Filiere"]?:$_POST["Filiere"];// or like C syntaxe
//$liste = getListeParFiliere($filiere);
//$liste = isset($_GET["reussite"])?getListeReuissite($filiere):getListeParFiliere($filiere);
$liste = isset($_GET["reussite"])?getListeReuissite($filiere):getListeEtudiantFromDb($filiere);
/*
if (!empty($_GET["reussite"])){
    $liste = getListeReuissite($filiere);
}else{
    $liste = getListeParFiliere($filiere);
}*/
/*
$nombre = count($liste);
$info = getNote();
//$max = $info[0][1];
//$max = getNotesListe($liste);
$max = getMax(getNotesListe($liste));

*/
?>


<h1>Liste des etudiants de filiere: <?= $filiere ?></h1>
<hr/>
<!--<b>Nombre des étudiants : <?= $info[0][1] ?> </b><br />-->
<b>Nombre des étudiants : <?= $nombre ?> </b><br/>
<b>Meilleure note : <?= $max ?></b> <br/>
<hr/>

<table border='1' align="center" width="60%">
    <tr>
        <th>Code</th>
        <th>Nom</th>
        <th>Prenom</th>
        <th>Note</th>
        <th>Mention</th>
    </tr>
    <?php
    foreach ($liste as $e) {
        //addEtudiant();
        //addEtudiant($e);
        $code = $e["CodeE"];
        $prenom = $e["Prenom"];
        $nom = $e["Nom"];
        $note = $e["Note"];
        echo "
            <tr>
               <td> <a href=\"index.php?action=detaill&Code=$code\">$code</a></td>
               <td> <a href=\"index.php?action=detaill&Code=$code\">$prenom </a></td>
               <td> <a href=\"index.php?action=detaill&Code=$code\">$nom  </a></td>
               <td>$note</td>
            </tr> ";
    }
    echo ">Ajouter un Etudiant</a> </td></tr>";
    //echo "<tr><td colspan='5' > <a href=\"liste.php?Filiere=$filiere&reussite=1\">Ajouter un Etudiant</a> </td></tr>";
    //echo "<tr><td colspan='5' > <a href=\"form.php\">Ajouter un Etudiant</a> </td>
    //<td colspan='5' > <a href=\"liste.php?Filiere=<?= $filiere&reussite=\">Afficher les Etudiants reussites seulment</a> </td></tr>";

    ?>

</table>



