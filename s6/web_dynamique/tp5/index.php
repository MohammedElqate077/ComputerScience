
<?php
session_start();
//$_SESSION[""]
$_SESSION["fileName"] = "index.php";
if(isset($_SESSION["LoginUsername"])==0){
    require 'login.php';
    exit();
}
include 'haut.php';

?>

<h1>Gestion des étudiants</h1>
<hr/>
<br/><br/>


Bienvenue dans la page d'acceuil de notre application Web. Vous pouvez gérer d'une manière très aisée la base de données
des étudiants.
En accédant à la liste, vous pouvez voir le détail d'un étudiant et le modifier ou le supprimer. A partir du menu, vous
pouvez ajouter un nouveau étudiant ou afficher toute la liste. Testez!!

<?php include 'bas.php'; ?>
