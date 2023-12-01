<?php
?>

<h1> forget password </h1>
<form action="" method="POST" >
    <pre>

    <input type="email" name="email" placeholder="email" value="<?=$var["email"]??""?>"/> <span class="Err"><?=$var["erreur"]["email"]??""?></span><br/>
    <input type="submit" name="send" value="Envoyer"/>  <input type="submit" name="delete" value="Annuler"/> <span class="Err" id="ErrLogin"><?=$var["sendStatus"]??""?></span>
    </pre>
</form>

<?php
if(isset($var["link"]) && $var["sendStatus"]=="the email not send"){ ?>
        <div align="center">
            <h3><i>Email Template</i></h3>
            <div align="center" style="outline: 5px solid red; width: 50%; height: 140px; padding: 40px ">
                vous avez oublier votre mot de passe? acces a votre compte is easy.<br/><br/> cliquer sur le bouton Rester Le Mot De Pass.<br/><br/><br/>&nbsp;&nbsp;
                <a style="color: white; background: red " target="_blank" href="<?= $var["link"]?>">Rester Le Mot De Pass</a><br/><br/>';
            </div>
        </div>
<?php }

?>