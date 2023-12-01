<?php
try{

    include 'Controllers/EtudiantController.php';
    $action = !empty($_GET["action"])?$_GET["action"]:"index";
    if(is_callable($action)) {
        $action();
    }else{
        throw new Exception("cette action n'est pas autorise");
    }

}catch(Exception $e) {
    $view = "Views/vError.php";
    $variables = ["message" => $e->getMessage()];
    render($view, $variables);
}
?>