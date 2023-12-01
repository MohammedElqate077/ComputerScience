
<?php
//$filiere = $_GET["Filiere"]?:$_POST["Filiere"];
//$liste = isset($_GET["reussite"])?getListeReuissite($filiere):getListeEtudiantFromDb($filiere);

//$liste = getListeEtudiant();

$liste = $var["etudiant"];
$nombre = count($liste);


?>


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
               <td> <a href=\"../index.php?action=detaill&id=$code\">$code</a></td>
               <td> <a href=\"../index.php?action=detaill&id=$code\">$prenom </a></td>
               <td> <a href=\"../index.php?action=detaill&id=$code\">$nom  </a></td>
               <td>$note</td>
            </tr> ";
    }

    echo "<tr><td colspan='5' > <a href=\"../index.php?action=ajouter\">Ajouter un Etudiant</a> </td></tr>";

    ?>
</table>

