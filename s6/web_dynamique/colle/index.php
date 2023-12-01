<?php
try{
    //session_start();

    error_reporting(E_ALL);
    ini_set('display_errors', 1);

    if(!isset($_SESSION)) {
        session_start();
    }

    require_once("Controllers/etudiantController.php");
    require_once ("Controllers/userController.php");

    $action = !empty($_GET["action"])?$_GET["action"]:"index";

    if(!empty($_COOKIE["userToken"]) && isSessionExists($_COOKIE["userToken"])){
        $_SESSION["LoginUsername"] = isSessionExists($_COOKIE["userToken"]);
    }

    if(empty($_SESSION["LoginUsername"]) && $action!="register" && $action!="resetPassword" && $action!="newPass"){
        login();
        exit();
    }

    if(is_callable($action)) {
        $action($_REQUEST);
    }else{
        throw new Exception("cette action n'est pas autorise");
    }

}catch(Exception $e) {
    $view = "Views/vError.php";
    $var = ["message" => $e->getMessage()];
    render($view, $var);
}
?>