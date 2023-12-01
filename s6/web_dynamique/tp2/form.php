<!doctype html>
<html lang="fr">
<head>
    <title>form</title>
    <meta charset="UTF-8"/>
    <link rel="stylesheet" type="text/css" href="public/style.css"/>
    <script type="text/javascript" src="public/JS.js"></script>
</head>

<body>
<div class="top">
    <img src="public/images/fsdm.jpg" border='0' hspace='20' vspace='20' align='left'>
    <span class="top">SMI6</span><br/>
    faculté Des Sience Dhar Mahraz, Fés
</div>

<h4><span id="LaDate"></span></h4>
<br/>

<h1>Ajouter un étudiant</h1>
<hr/>

<form id="myForm" name="myForm" action="liste.php" method="post">
         <pre>
Entrez le nom:
<input type="text" name="Nom" value=""/><span class="Err" id="ErrNom"></span>

Entrez le prénom:
<input type="text" name="Prenom" value=""/><span class="Err" id="ErrPrenom"></span>

Entrez la note:
<input type="text" name="Note" value""/><span class="Err" id="ErrNote"></span>

Filière:
<select name="Filiere">
      <option value="SMI" "selected">Sciences Mathématiques et Informatique</option>
    <option value="SMI">Sciences Mathématiques et Application</option>
      <option value="SMP">Sciences de la Matière Physique</option>
</select> <span class="Err"> </span>

<input type="submit" value="Envoyer"/> <input type="reset" value="Annuler"/>

         </pre>
</form>
﻿
<br/>
<hr/>
<a href="index
      .php">Acceuil</a> |
<a href="liste.php">Liste de étudiants</a> |
<a href="form.php">Ajouter un étudiant</a>
<br/>
<hr/>
<br/>
<div class="bas">&copy; copyright: SMI6 2022<br/>Facult&eacute; des Sciences Dhar El Mahraz</br>smi6@fsdm.usmba.ac.ma
</div>


</body>
</html>
