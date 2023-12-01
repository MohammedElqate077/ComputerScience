
<?php
//$filiere = $_GET["Filiere"]?:$_POST["Filiere"];
//$liste = isset($_GET["reussite"])?getListeReuissite($filiere):getListeEtudiantFromDb($filiere);

//$liste = getListeEtudiant();

$liste = $var["etudiant"];
$isAll = $var["isAll"];
$filiere = $var["filiere"];
$max = $var["max"];
$nombre = count($liste);


if(!empty($max)) echo"<h2><i><li>Le majorant : $max[CodeE], $max[Nom] $max[Prenom], $max[Note]</li><i></h2>";

if(!$isAll){
    echo"<h2><i><li>Listes des etudiants $filiere :</li><i></h2>";

}else echo"<h2><i><li>Tous les etudiants :</li><i></h2>";
?>

<pre>

</pre>

<table border='1' align="center" width="60%">
    <tr>
        <th>Code</th>
        <th>Nom</th>
        <th>Prenom</th>
        <th>Note</th>
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
               <td> <a href=\"../index.php?action=detail&id=$code\">$code</a></td>
               <td> <a href=\"../index.php?action=detail&id=$code\">$nom  </a></td>
               <td> <a href=\"../index.php?action=detail&id=$code\">$prenom </a></td>
               <td>$note</td>
            </tr> ";
    }

    echo "<tr><td colspan='5' > <a href=\"../index.php?action=ajouter&Filiere=$filiere\">Ajouter un Etudiant</a> </td></tr>";

    ?>
</table>

