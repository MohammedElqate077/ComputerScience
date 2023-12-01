<?php

require 'Models/EtudiantManager.php';

function index(){
    $view = "Views/vIndex.php";
    //header("locaation:$view");
    $variables = array();
    render($view,$variables);
}

function Filiere(){
    $view = "Views/vFiliere.php";
    $var = ["filiere"=>getListeFiliere()];
    render($view,$var);
}

function Etudiant(){
    $view = "Views/vEtudiant.php";
    $var = ["etudiant"=>getListeEtudiant($_GET["CodeF"])];
    //$var = ["listeMention"=>getListeMention($var["etudiant"])];
    render($view,$var);
}

function ajouter(){
    $etudiant = ["CodeE"=>"","Nom"=>"","Prenom"=>"","Filiere"=>"","Note"=>""];
	if ($_SERVER["REQUEST_METHOD"]=="POST") {
        $etudiant=$_POST;
        if(empty($etudiant["CodeE"]))    $erreur["CodeE"]   ="Le code est vide !..."   ;
        if(empty($etudiant["Nom"]))     $erreur["Nom"]    ="Le Nom est vide !...."   ;
        if(empty($etudiant["Prenom"]))  $erreur["Prenom"] ="Le prénom est vide !..." ;
        if(empty($etudiant["Filiere"])) $erreur["Filiere"]="Sélectionnez une filière !...";

        if(empty($etudiant["Note"]))
            $erreur["Note"]="La Note est vide !...";
        elseif(!is_Numeric($etudiant["Note"]))
            $erreur["Note"]="La Note doit être un un nombre !...";
        elseif($etudiant["Note"] < 0 or $etudiant["Note"] > 20)
            $erreur["Note"]="La Note doit être entre 0 et 20 !...";

        if (!isset($erreur)) {
            addEtudiant($etudiant);
            header ("location: index.php?action=Etudiant");
        }
    }

	$var["etudiant"] = $etudiant;
	$var["filieres"]= getListeFiliere();
	$var["erreur"] = $erreur ?? [] ;


    $view = "Views/vForm.php";
    render($view,$var);
}


function suprimer(){
    $id = $_GET["id"] ?? "";
    if(empty($id)) throw new Exception("id non fournit");
    if(is_numeric($id)) throw new Exception("id fournit non valide");
    supprimerEtudiant($id);
    header("location:index.php?action=Etudiant");
}

function detaill(){
    $id = $_GET["id"] ?? "";
    if(empty($id)) throw new Exception("id non fournit");
    if(is_numeric($id)) throw new Exception("id fournit non valide");

    $var = ["detaillEtudiant"=>getEtudiant($id)];
    $view = "Views/vDetaill.php";

    render($view,$var);
}

function render($vue, array $var=array()){
    ob_start();
    require ($vue);
    $view = ob_get_clean();
    require("Views/template.php");
}
?>
