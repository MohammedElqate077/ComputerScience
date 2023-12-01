<?php

?>

<form name="register" action="" method="POST">
    <pre>
   <input type="text" name="nom" value="<?=$var["nom"]??""?>" placeholder="nom"/> <span class="Err" id="ErrUser"><?=$var["erreur"]["nom"]??""?></span><br/>
   <input type="text" name="prenom" value="<?=$var["prenom"]??""?>" placeholder="prenom" /> <span class="Err" id="ErrUser"><?=$var["erreur"]["prenom"]??""?></span><br/>
   <input type="email" name="email" value="<?=$var["email"]??""?>" placeholder="email" /> <span class="Err" id="ErrUser"><?=$var["erreur"]["email"]??""?></span><br/>
   <input type="text" name="username" value="<?=$var["username"]??""?>" placeholder="username" /> <span class="Err" id="ErrUser"><?=$var["erreur"]["user"]??""?></span><br/>
   <input type="password" name="password" value="<?=$var["password"]??""?>" placeholder="mot de passe" /> <span class="Err" id="ErrPass"><?=$var["erreur"]["pass"]??""?></span><br/>
   <input type="submit" name="send" value="Envoyer"/>  <input type="submit" name="delete" value="Annuler"/><span class="Err" id="ErrLogin"><?=$var["erreur"]["login"]??""?></span>
    </pre>
</form>
