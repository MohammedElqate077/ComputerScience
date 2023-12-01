


<?php

if(!isset($var["erreur"]["token"])){ ?>
    <h2>Entrer Le Nouveau Mot De Passe</h2>
    <form action="" method="POST">
    <pre>
    <input type="password" name="password" value="<?=$var["password"]??""?>" placeholder="nouveau mot de passe" /> <span class="Err" id="ErrPass"><?=$var["erreur"]["pass"]??""?></span><br/>
    <input type="password" name="confirm" value="<?=$var["confirm"]??""?>" placeholder="confirmer le mot de passe" /> <span class="Err" id="ErrPass"><?=$var["erreur"]["conf"]??""?></span><br/>
    <input type="submit" name="send" value="Envoyer"/>  <input type="submit" name="delete" value="Annuler"/><span class="Err" id="ErrLogin"><?=$var["erreur"]["login"]??""?></span>
    </pre>
    </form>
<?php }else echo "<h2>Invalide Or Expire Token</h2><br/> ";


?>

