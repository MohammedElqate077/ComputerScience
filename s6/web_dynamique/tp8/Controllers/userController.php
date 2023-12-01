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
            saveIntoSession($_POST["LoginUsername"],$userToken,$time);
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
    deleteFromSession($_COOKIE["userToken"]);
    setcookie("userToken","",time() - (86400 * 30));
    header("location:index.php");
    exit();
}

function addUser(){
    //just  create users to test;
    $username = "simo";//any thing you want
    $password = "smi";// ths same
    $passwordHash = password_hash($password,PASSWORD_DEFAULT);
    $operation = saveIntoUsers($username, $passwordHash) !== null ?"succes":"failure";
    echo "adding user with $operation";
}
?>
