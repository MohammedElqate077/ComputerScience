
<h1>Ajouter un étudiant</h1>
<hr/>

<form id="myForm" name="myForm" action="" method="post">
         <pre>
Entrez le Code:
<input type="text" name="CodeE" value=""/><span class="Err" id="ErrNom"></span> <span class="Err"><?=$var["erreur"]["CodeE"]?></span>

Entrez le nom:
<input type="text" name="Nom" value=""/><span class="Err" id="ErrNom"></span> <span class="Err"><?=$var["erreur"]["Nom"]?></span>

Entrez le prénom:
<input type="text" name="Prenom" value=""/><span class="Err" id="ErrPrenom"></span> <span class="Err"><?=$var["erreur"]["Prenom"]?></span>

Entrez la note:
<input type="text" name="Note" value""/><span class="Err" id="ErrNote"></span> <span class="Err"><?=$var["erreur"]["Note"]?></span>

Filière:
<select name="Filiere">
    <?php
        foreach ($var["filieres"] as $f){
            echo "<option value=".$f["CodeF"].">".$f["IntituleF"]."</option>";
        }
    ?>
</select><span class="Err"><?=$var["erreur"]["Filiere"]?></span>

<input type="submit" value="Envoyer"/> <input type="reset" value="Annuler"/>

         </pre>
</form>

