function getClientDate() {
		
	var d= new Date();
	var jours = new Array("Dimanche","Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi");
	var mois = new Array("Janvier","Février","Mars", "Avril","Mai","juin","Juillet","Aôut","Septembre","Octobre","Novembre","Décembre");

    return jours[d.getDay()] +" "+ d.getDate() +" "+ mois[d.getMonth()] +" "+ d.getFullYear();

}


function ValiderLeFormulaire() {
var err = false;
document.getElementById("ErrCode").innerHTML ="";
document.getElementById("ErrNom").innerHTML ="";
document.getElementById("ErrPrenom").innerHTML ="";
document.getElementById("ErrNote").innerHTML ="";


	if (document.myForm.Code.value==""){
			err =true;
			document.getElementById("ErrCode").innerHTML="Le code est obligatoire";
	}
	if (document.myForm.Nom.value==""){
			err =true;
			document.getElementById("ErrNom").innerHTML="Le nom est obligatoire";
	}
	if (document.myForm.Prenom.value==""){
			err = true;
			document.getElementById("ErrPrenom").innerHTML="Le prénom est obligatoire";
	}
	if (document.myForm.Note.value==""){
			err = true;
			document.getElementById("ErrNote").innerHTML="La note est obligatoire";
	}
	if (isNaN(document.myForm.Note.value)){
			err = true;
			document.getElementById("ErrNote").innerHTML="La note doit être un nombre";
	}
	else if (eval(document.myForm.Note.value) <0 || eval(document.myForm.Note.value)> 20){
			err = true;
			document.getElementById("ErrNote").innerHTML="La note doit être entre 0 et 20";
	}
	return err;
}

function calculerMention (n) {	
	
	if (0 <= n && n < 10)
		return "Ajourné!";
	else if (10 <= n && n < 12)
		return "PASSABLE";
	else if (12 <= n && n < 14)
		return "ASSEZ BIEN";
	else if (14 <= n && n < 16)
		return "BIEN";
	else if (16 <= n && n <= 20)
		return "TRES BIEN";
	else 
		return "Note non valide!";		
	
}

	
window.addEventListener("DOMContentLoaded", function (event) {
  
	document.getElementById("LaDate").innerHTML =  getClientDate();
 
	document.myForm.addEventListener("submit", (event) => {
		if(ValiderLeFormulaire()) event.preventDefault();
		else {alert("Les données vont être envoyées");}
	});
  
  
});
