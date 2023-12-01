
<?php
include 'haut.php';

$filiere[]=["codeFiliere"=>"SMI","intituleFiliere"=>"Sciences Mathématiques et Informatique"];
$filiere[]=["codeFiliere"=>"SMA","intituleFiliere"=>"Sciences Mathématiques et Appliquation"];
$filiere[]=["codeFiliere"=>"SMP","intituleFiliere"=>"Sciences de la Matière Physique"];
?>

<h1 align="center">Afficher Des Resultas</h1>
<hr/> <br/>

<?php
function printFiliere(){
    $filiere = $GLOBALS["filiere"] ;
    for ($i = 0; $i < count($filiere); $i++){   ?>
        <li>
           <a href ="liste.php?codeFiliere=<?= $filiere[$i]["codeFiliere"]?>"> <?= $filiere[$i]["intituleFiliere"] ?></a>
        </li>    <?php
    }
}

printFiliere();
?>




<?php include 'bas.php'; ?>