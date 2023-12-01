<?php
session_start();
require_once ("userController.php");

function login(){
    $view = "Views/user/vLogin.php";
    if($_SERVER["REQUEST_METHOD"]=="POST"){
        verfier();
    }
    render($view);
}

function checkFields($userPost):bool{
    if(empty($user["Login"]))  $erreur["Login"] ="Le login est vide !..."   ;
    elseif(empty($user["PW"]))  $erreur["PW"] ="Le mot de passe est vide !..."   ;
    elseif(!user_exists($user)) $erreur["User"]= "Login ou mot de passe incorrect!...";
    if(!isset($erreur)) return false;
    return true;
}

function verfier(){
    if($_POST["LoginUsername"]=="simo" && $_POST["LoginPassword"]=="smi"){
        setcookie("Login",$_POST["LoginUsername"],time() + (86400 * 30),"/");
        setcookie("Pass",$_POST["LoginPassword"],time() + (86400 * 30),"/");
        $_SESSION["LoginUsername"] = $_POST["LoginUsername"];
        $_SESSION["LoginPassword"] = $_POST["LoginPassword"];
        header("location:index.php");
        exit();
    }
}

function logout(){
    session_destroy();
    setcookie("Login","",time() - (86400 * 30));
    setcookie("Pass","",time() - (86400 * 30));
    header("location:index.php");
    exit();
}

?>
