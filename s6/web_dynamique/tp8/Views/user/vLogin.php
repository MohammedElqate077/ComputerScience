<?php
//$_SESSION[""]
// if yout want to check the value of annull reset button then the type shoude be submit to send form to php
?>

<h1>Authentification</h1>

<form name="login" action="" method="POST">
    <pre>
   <input type="text" name="LoginUsername" value="<?=$var["user"]??""?>" placeholder="username (simo)" /> <span class="Err" id="ErrUser"><?=$var["erreur"]["user"]??""?></span><br/>
   <input type="password" name="LoginPassword" value="<?=$var["pass"]??""?>" placeholder="mot de passe (smi)" /> <span class="Err" id="ErrPass"><?=$var["erreur"]["pass"]??""?></span><br/>
   <input  type="checkbox" name="rester" <?=$var["rester"]??""?> /> Rester Connecté <br/>
   <input type="submit" name="send" value="Envoyer"/>  <input type="submit" name="delete" value="Annuler"/><span class="Err" id="ErrLogin"><?=$var["erreur"]["login"]??""?></span><br/>
    </pre>
</form>
