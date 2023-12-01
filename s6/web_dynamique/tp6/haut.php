<?php session_start() ?>
<!doctype html>
<html lang="fr">

<head>
    <title>list</title>

</head>
<title>liste</title>
<meta charset="UTF-8"/>
<link rel="stylesheet" type="text/css" href="public/style.css"/>
<script type="text/javascript" src="public/JS.js"></script>
</html>

<body>
<div class="top">
    <img src="public/images/fsdm.jpg" alt="fsdm logo" border='0' hspace='20' vspace="20" align="left">
    <span class="top">SMI6</span><br/>
    faculté Des Sience Dhar Mahraz, Fés
</div>

<h4><span id="LaDate"></span></h4>



<span align="right"><h3>
    <?php
        $loginUsername = $_SESSION["LoginUsername"];
        if(isset($_SESSION["LoginUsername"])==0){
    //if(isset($_SESSION["LoginUserName"])==0 || $_SESSION["LoginUserName"]==""){
        echo "<b id=\"conectInfo\">Non Connecté</b> || ";
        }else{
            echo "<a href=\"logout.php\"> <b id=\"conectInfo\"><u><i>Connecté as $loginUsername (out)<i></u></b></a> || ";
        }
        ?>
        <a href="option.php">Option</a>
    </h3>
</span>
<br/><br/>
