<?php
//$_SESSION[""]
include 'haut.php';

?>

<h1>Authentification</h1>

<form name="login" action="verfier.php" method="post">
    <pre>
   <input type="text" name="LoginUsername" value="" placeholder="username" required/> (indication simo)<br/>
   <input type="password" name="LoginPassword" value="" placeholder="mot de passe" required/> (indication smi)<br/>
   <input type="submit" value="Envoyer"/>  <input type="reset" value="Annuler"/>
    </pre>
</form>
