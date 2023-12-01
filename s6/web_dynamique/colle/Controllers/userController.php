<?php
//session_start();
//require_once ("userController.php");
require_once ("Models/usersManager.php");

function index(array $t){
    $view = "Views/needs/vHome.php";
    render($view);
}

function login(){
    $view = "Views/user/vLogin.php";
    $var = null;
    if($_SERVER["REQUEST_METHOD"]==="POST" && !isset($_POST["delete"])){
        $erreur =  checkFields($_POST);
        if(isset($erreur)) {
            $var["erreur"] = $erreur;
            $var["user"] = $_POST["LoginUsername"];
            $var["pass"] = $_POST["LoginPassword"];
            $var["rester"] = isset($_POST["rester"])?"checked":"";
        }else verfier();
    }
    //render($view);
    !isset($var) ? render($view):render($view,$var);
}

function checkFields($user){
    if(empty($user["LoginUsername"]))  $erreur["user"] ="Le login est vide !...";
    if(empty($user["LoginPassword"]))  $erreur["pass"] ="Le mot de passe est vide !...";
    if(!isset($erreur) && !isUserExists($user["LoginUsername"],$user["LoginPassword"])) $erreur["login"]= "Login ou mot de passe incorrect!...";
    return !isset($erreur)?null:$erreur;
}

function verfier(){
    //if($_POST["LoginUsername"]=="simo" && $_POST["LoginPassword"]=="smi"){
    if(isset($_POST["rester"])){
            $userToken = password_hash($_POST["LoginUsername"].$_POST["LoginPassword"].time(),PASSWORD_DEFAULT);
            $time = time()+(3600 * 24 * 15);
            setcookie("userToken",$userToken,$time);
            saveIntoSessions($_POST["LoginUsername"],$userToken,$time);
    }
    $_SESSION["LoginUsername"] = $_POST["LoginUsername"];
    header("location:index.php");
    exit();
}

function verifer2(){

}

function logout(){
    session_destroy();
    //setcookie("Login","",time() - (86400 * 30));
    deleteFromSessions($_COOKIE["userToken"]);
    setcookie("userToken","",time() - (86400 * 30));
    header("location:index.php");
    exit();
}

function register(){
    $view = "Views/user/vRegister.php";
    $var = null;
    if($_SERVER["REQUEST_METHOD"]=="POST" && !isset($_POST["delete"])){
        $user = $_POST;

        //echo getFromUsers("email",$user["email"]);
        if(empty($user["nom"]))  $erreur["nom"] ="Le nom est vide !...";
        if(empty($user["prenom"]))  $erreur["prenom"] ="Le prenom est vide !...";

        if(empty($user["email"]))  $erreur["email"] ="L'email est vide !...";
        else if( getFromUsers("email", $user["email"]) != null) $erreur["email"] ="L'email est deja existe !...";

        if(empty($user["username"]))  $erreur["user"] ="Le username est vide !...";
        else if(getFromUsers("username",$user["username"]) != null ) $erreur["user"] ="username est deja existe !...";

        if(empty($user["password"]))  $erreur["pass"] ="Le mot de passe est vide !...";

        if(!isset($erreur) && saveIntoUsers($user)){
           header("location:index.php");
           exit();
        }else {
            $var = $user;
            $var ["erreur"] = $erreur??"";
        }
    }
    !isset($var) ? render($view):render($view,$var);
}

function resetPassword(){
    $view = "Views/user/vResetPassword.php";
    $var = null;
    if($_SERVER["REQUEST_METHOD"]=="POST" && !isset($_POST["delete"])){
        $user = $_POST;
        if(empty($user["email"]))  $erreur["email"] ="L'email est vide !...";
        else if( getFromUsers("email", $user["email"]) == null) $erreur["email"] ="L'email n'existe pas !...";
        if(!isset($erreur)) {
            $token = sha1($user["email"].time().bin2hex(random_bytes(5)),false); // or use hash() function
            if(saveIntoTokens($token,$user["email"]) != true){
                /*as normale execute statement return true on succes and false on failer as php documentation said
                but here a problem even the query work and save data and all correctly she return false
                this my be a bugs in php or pdo or mysql*/
                deleteFromExceptToken($token);
                $link = "http://fsdm2022.me?action=newPass&token=".$token;
                //echo $link; //just to test
                $var["sendStatus"] = sendTokenToEmail($user,$link); //I config /etc/php.in but not work look at smpt server
                $var["link"] = $link;
            }else $var["sendStatus"] = "probleme de genere nouveau token";
            //deleteFromExceptToken($token);
            // use insted locahost or setup the domaine or just in hosts file to work without problem
            //echo $mail["msg"];
        }else{
            $var = $user;
            $var["erreur"] = $erreur??"";
        }
    }
    !isset($var) ? render($view):render($view,$var);
}

function newPass(){
    $view = "Views/user/vSetNewPass.php";
    $token = getFromTokens($_GET["token"]??"");
    if(!($token != null && $token["expire"] > time())) {
        $var["erreur"]["token"] = true;
        deleteOldTokens();
    }

    if($_SERVER["REQUEST_METHOD"]=="POST" && !isset($_POST["delete"])){
        $data = $_POST;
        if(empty($data["password"]))  $erreur["pass"] ="Le mot de passe est vide !...";
        else if($data["password"] !== $data["confirm"]) $erreur["conf"] = "n'a pas le meme mot de passe !...";
        if(!isset($erreur)){
            $user = getFromUsers("email",$token["email"]);
            if(isset($user)){
                $user["password"] = $data["password"];
                if(updatUser($user)) // or you can delete and then add user
                    deleteFromToken($token["email"]);//deleteFromToken($token["token"]);to delete delete only this token; but use token in BD
                    header("location:index.php");
            }
        }else {
            $var = $data;
            $var["erreur"]["pass"] = $erreur["pass"]??"";
            $var["erreur"]["conf"] = $erreur["conf"]??"";
        }
    }

    !isset($var) ? render($view):render($view,$var);
}

function sendTokenToEmail($user,$link){
    $mail["to"] = $user["email"];
    $mail["subject"] = "retourner votre mot de passe";
    $mail["msg"] = 'vous avez oublier votre mot de passe? acces a votre compte is easy.<br/><br/> cliquer sur le bouton Rester Le Mot De Pass.<br/><br/><br/>&nbsp;&nbsp; 
                            <a style="color: white; background: red " target="_blank" href="'.$link.'">Rester Le Mot De Pass</a><br/><br/>';
    $mail["header"] = "From:" . "fsdm2022@mail.com";
    //echo $mail["msg"];

    return sendMailt($mail)? "check your email for link":"the email not send";
}

?>
