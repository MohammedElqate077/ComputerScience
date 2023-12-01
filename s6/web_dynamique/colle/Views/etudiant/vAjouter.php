<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
?>

<h1>Ajouter un étudiant</h1>
<hr/>

<form id="myForm" name="myForm" action="" method="post">
         <pre>
Entrez le Code:
<input type="text" name="CodeE" value= "<?=$var["etud"]["CodeE"]??""?>"/><span class="Err" id="ErrNom"> <?=$var["erreur"]["CodeE"]??""?></span>

Entrez le nom:
<input type="text" name="Nom" value="<?=$var["etud"]["Nom"]??""?>"/><span class="Err" id="ErrNom"> <?=$var["erreur"]["Nom"]??""?></span>

Entrez le prénom:
<input type="text" name="Prenom" value="<?=$var["etud"]["Prenom"]??""?>"/><span class="Err" id="ErrPrenom"> <?=$var["erreur"]["Prenom"]??""?></span>

Entrez la note:
<input type="text" name="Note" value="<?=$var["etud"]["Note"]??""?>"/><span class="Err" id="ErrNote"> <?=$var["erreur"]["Note"]??""?></span>

Filière:
<select name="Filiere">

      <?php
      foreach ($var["filiere"] as $f){
            //if($f["CodeF"]==$var["etud"]["Filiere"])
          $selected =  $f["CodeF"]==$var["etud"]["Filiere"] ? "selected" : "";
          echo "<option value=".$f["CodeF"]. " $selected >".$f["IntituleF"]."</option>";
       }
      /*<option value="SMI"  >Sciences Mathématiques et Informatique</option>
          <option value="<?= $f["CodeF"]?>"><?=$f["IntituleF"]?></option>
    <option value="SMA" >Sciences Mathématiques et Application</option>
      <option value="SMP">Sciences de la Matière Physique</option>*/
      ?>
</select> <span class="Err"> <?=$var["erreur"]["Filiere"]??""?> </span>

<input type="submit" value="Envoyer"/> <input type="reset" value="Annuler"/>

         </pre>
</form>
