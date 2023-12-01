<?php include 'haut.php'; ?>

<h1>Ajouter un étudiant</h1>
<hr/>

<!--<form id="myForm" name="myForm" action="liste.php" method="post">-->
<form id="myForm" name="myForm" action="receptionPost.php" method="post">
         <pre>
Entrez le nom:
<input type="text" name="Nom" value=""/><span class="Err" id="ErrNom"></span>

Entrez le prénom:
<input type="text" name="Prenom" value=""/><span class="Err" id="ErrPrenom"></span>

Entrez la note:
<input type="text" name="Note" value=""/><span class="Err" id="ErrNote"></span>

Entrez le mot de passe:
<input type="password" name="Password" value=""/><span class="Err" id="ErrPassword"></span>

Sex:
<input type="radio" name="Sex" class="sex" value="Homme"/><span class="Err" id="ErrSex"></span> Homme
<input type="radio" name="Sex" class="sex" value="Femme"/><span class="Err" id="ErrSex"></span> Femme

Semestres validée:
<input type="checkbox" name="S[1]" class="checkbox" value="S1"/> S1
<input type="checkbox" name="S[2]" class="checkbox" value="S2"/> S2
<input type="checkbox" name="S[3]" class="checkbox" value="S3"/> S3
<input type="checkbox" name="S[4]" class="checkbox" value="S4"/> S4
<input type="checkbox" name="S[5]" class="checkbox" value="S5"/> S5
<input type="checkbox" name="S[6]" class="checkbox" value="S6"/> S6

Filière:
<select name="Filiere">
      <option value="SMI" "selected">Sciences Mathématiques et Informatique</option>
    <option value="SMI">Sciences Mathématiques et Application</option>
      <option value="SMP">Sciences de la Matière Physique</option>
</select> <span class="Err"> </span>

 Saisir ici un commantaire :
 <textarea name="Commentaire" class="commentaire" cols="40" rows="10" ></textarea>

<input type="submit" value="Envoyer"/> <input type="reset" value="Annuler"/>

         </pre>
</form>


<?php include 'bas.php'; ?>
