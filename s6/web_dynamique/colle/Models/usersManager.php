<?php

require_once ("Config/config.php");

/* should be use mysql event to delete the old sessions and tokens*/

function saveIntoUsers($user){
    $connexion = openConnexion();
    $passwrod = password_hash($user["password"],PASSWORD_DEFAULT);
    $req = $connexion->prepare("insert into Users(nom,prenom,email,username,password) values(?,?,?,?,?)");
    $req = $req->execute([$user["nom"],$user["prenom"],$user["email"],$user["username"],$passwrod]);
    $connexion = null;
    return isset($req);
}

function deleteFromUsers($username){
    return openConnexion()->query("delete from Users where username = '$username'");
}

function getFromUsers($fieldName,$fieldValue){
    $req = "select * from Users where " .$fieldName. " = " ."'$fieldValue'";
    return openConnexion()->query($req)->fetch();
}

function updatUser($user){
    $passwrod = password_hash($user["password"],PASSWORD_DEFAULT);
    $req = openConnexion()->prepare("update Users set nom=?,prenom=?,email=?,username=?,password=? where id = ?");
    return $req->execute([$user["nom"],$user["prenom"],$user["email"],$user["username"],$passwrod,$user["id"]]);
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

function saveIntoSessions($login, $token, $time){
    $req = openConnexion()->prepare("insert into Sessions (login,token,expire) values (?,?,?)");
    $req->execute([$login,$token,$time]);
    //return isset($req);
}

function deleteFromSessions($token){
    return openConnexion()->query("delete from Sessions where token='$token'");
}

function saveIntoTokens($token, $email){
    //$req = openConnexion()->prepare("insert into Tokens values(?,?)");
    $req = openConnexion()->prepare("insert into Tokens values(?,?,?)");
    //$req->execute([$token,time() + 30]);//30 second
    //$req->execute([$token,time()+(3600)]);// 1 hour
    $req->execute([$token,$email,time()+(3600 * 24)]);//1 day

}

function getFromTokens($token){
    $req = openConnexion()->prepare("select * from Tokens where token = ?");
    $req->execute([$token]);
    return  $req->fetch();
}

function deleteFromToken($key){
    return openConnexion()->query("delete from Tokens where email = '$key'");
    //return openConnexion()->query("delete from Tokens where token = '$token'");
}

function deleteFromExceptToken($token){
    //return openConnexion()->query("delete from Tokens where token != '$key'");
    return openConnexion()->query("delete from Tokens where token != '$token'");
}

function deleteOldTokens(){
    $time = time();
    return openConnexion()->query("delete from Tokens where expire < '$time'");
}

?>
