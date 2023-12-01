<?php
?>

<h1>Ajouter un étudiant</h1>
<hr/>

<form id="myForm" name="myForm" action="" method="post">
         <pre>
Entrez le Code:
<input type="text" name="CodeE" value=""/><span class="Err" id="ErrNom"></span>

Entrez le nom:
<input type="text" name="Nom" value=""/><span class="Err" id="ErrNom"></span>

Entrez le prénom:
<input type="text" name="Prenom" value=""/><span class="Err" id="ErrPrenom"></span>

Entrez la note:
<input type="text" name="Note" value""/><span class="Err" id="ErrNote"></span>

Filière:
<select name="Filiere">
      <option value="SMI" "selected">Sciences Mathématiques et Informatique</option>
    <option value="SMA">Sciences Mathématiques et Application</option>
      <option value="SMP">Sciences de la Matière Physique</option>
</select> <span class="Err"> </span>

<input type="submit" value="Envoyer"/> <input type="reset" value="Annuler"/>

         </pre>
</form>
