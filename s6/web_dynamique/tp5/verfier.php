<?php
session_start();
//$_SESSIOIN["sessiontStatus"] = false;
function verfier():bool{
    //$_SESSIOIN["sessionStatus"] = true;
    if($_POST["LoginUsername"]=="simo" && $_POST["LoginPassword"]=="smi"){
        $_SESSIOIN["sessionStatus"] = true;
        $_SESSION["LoginUsername"] = $_POST["LoginUsername"];
        $_SESSION["LoginPassword"] = $_POST["LoginPassword"];
        return true;
    }
    return false;
}

if(verfier()){
    $location = $_SESSION["fileName"];
    //sprintf($locations,$_SESSION["fileName"]);
    header("location:$location");// or use localhost hada fsdm2022 deja definie dans /etc/hosts
    //header("location:index.php");// or use localhost hada fsdm2022 deja definie dans /etc/hosts
    //header($locations);
}else header("Location:login.php");
?>
