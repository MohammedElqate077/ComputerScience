<?php
session_start();
$location = $_SESSION["fileName"];
session_destroy();
//header("location:index.php");
header("location:$location");
//header("location:index.php");
?>
