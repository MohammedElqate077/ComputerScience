<?php

require_once ("Config/config.php");

function saveIntoUsers($username, $password){
    $connexion = openConnexion();
    $req = $connexion->prepare("insert into Users(username,password) values(?,?)");

    $req = $req->execute([$username,$password]);
    $connexion = null;
    return isset($req);
}

function deleteFromUsers($username){
    return openConnexion()->query("delete from Users where username = '$username'");
}

function isUserExists($username, $password){
    $hashPassword = openConnexion()->query("select password from Users where username = '$username'")->fetchColumn();
    return password_verify($password,$hashPassword);
}

function isSessionExists($token){
    $req = openConnexion()->prepare("select login from Sessions where token = ? and expire > ?");
    $req->execute([$token,time()]);
    return $req->fetchColumn();
}

function saveIntoSession($login, $token, $time){
    $req = openConnexion()->prepare("insert into Sessions (login,token,expire) values (?,?,?)");
    $req->execute([$login,$token,$time]);
    //return isset($req);
}

function deleteFromSession($token){
    return openConnexion()->query("delete from Sessions where token='$token'");
}

?>
