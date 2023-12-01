<?php
try{
    session_start();

    require_once("Controllers/etudiantController.php");
    require_once ("Controllers/userController.php");

    $action = !empty($_GET["action"])?$_GET["action"]:"index";

    if(!empty($_COOKIE["Login"]) && !empty($_COOKIE["Pass"])){
        $_SESSION["LoginUsername"] = $_COOKIE["Login"];
        $_SESSION["LoginPassword"] = $_COOKIE["Pass"];
    }

    if(empty($_SESSION["LoginUsername"])){
        //$action = "login";
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
    //$variables = ["message" => $e->getMessage()];
    $var = ["message" => $e->getMessage()];
    render($view, $var);
}
?>