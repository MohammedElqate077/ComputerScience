#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>

typedef struct Filme{
	char nom [80];
	char titre [80];
	int anne;
	int duree;
	struct Filme *suiv;
}Film;

typedef struct  {
	Film *tete;
	Film *fin;
	int nb_film;
}List;

int est_vide(List *li){
	//return li->tete==NULL;	
	return li->nb_film;
}

void objet_film(Film *fi){
	printf("\t\t** inserer les donner de filme\n");
	printf("nom : ");fflush(stdin);scanf(" %s",fi->nom);
	printf("titre : ");fflush(stdin);scanf(" %s",fi->titre);
	printf("anne : ");fflush(stdin);scanf(" %d",&fi->anne);
	printf("duree : ");fflush(stdin);scanf(" %d",&fi->duree);
}

Film *create_film(){
	Film *fi=(Film*)malloc(sizeof(Film));
	
	if (fi==NULL){
		printf("faild creation de filme \n");
		exit(-1);
	}

	printf("\t\t** inserer les donner de filme\n");
	printf("nom : ");fflush(stdin);scanf(" %s",fi->nom);
	printf("titre : ");fflush(stdin);scanf(" %s",fi->titre);
	printf("anne : ");fflush(stdin);scanf(" %d",&fi->anne);
	printf("duree : ");fflush(stdin);scanf(" %d",&fi->duree);
	
	//objet_film(fi);
	
	fi->suiv=NULL;
	return fi;
}

void initial_list(List *li){
	li->tete=NULL;
	li->fin=NULL;
	li->nb_film=0;
}

List *create_list(){
	List *li=(List*)malloc(sizeof(List));
	if (li==NULL){
		printf("faild creation de la list \n");
		exit(-1);
	}
	initial_list(li);
	return li;
}


void ajouter_tete_list(List *li,Film *fi){
	//Film *new=create_film();
	//new->suiv=li->tete;
	fi->suiv=li->tete;	
	li->tete=fi;
	if (li->fin==NULL){
		li->fin=fi;
		li->fin->suiv=NULL;
	}
	li->nb_film++;

}

void ajouter_fin_list(List *li,Film *fi){
	//if (est_vide(li)){
	if (li->tete==NULL){
		ajouter_tete_list(li,fi);
		return;
	}
	else{
		//Film *F=create_film();
		fi->suiv=NULL;
		li->fin->suiv=fi;	
		li->fin=fi;
		li->nb_film++;
	}
	return;
}

Film *pos_film(List *li){
	int i=1;
	int pos;
	Film *F=li->tete;
	printf("\t\t** doner la position du film : \n");scanf("%d",&pos);
	if(pos==1){
		return *li->tete;
	}
	else if(pos==li->nb_film){
		return *li->fin;
	}

	while(i<pos && F!=NULL ){
		F=F->suiv;
		i++;
	}
	return *F;
}

List *invers_list(List *li_1){
	List *li_2=create_list();	
	Film *fi=li_1->tete;
	while(fi!=NULL){
		ajouter_tete_list(li_2,fi);
		fi=fi->suiv;
		li_2->nb_film++;
	}
	free(li_1);li_1=NULL;
	return li_2;
}

void inser_par_ordre(List *li,Film *fi){
	if( est_vide(li) || strcmp(li->tete->nom,fi->nom)==0)	{
		ajouter_tete_list(li,fi);
	}else if(strcmp(li->fin->nom,fi->nom)==0){
		ajouter_fin_list(li,fi)	;
	}
	else{
		Film *F=li->tete;	
		while(F->suiv!=NULL && strcmp(F->suiv->nom,fi->nom)<0){
			F=F->suiv;
		}
		fi->suiv=F->suiv;
		F->suiv=fi;
		free(F);
		F=NULL;
		li->nb_film++;
	}

	return;

}

List *suprimer_pos_list(List *li){
	int pos;
	Film *F=li->tete;
	printf("\t\t** doner la position du film : \n");scanf("%d",&pos);
    	if(est_vide(li)) return li;

	if(pos==1){
		li->tete=li->tete->suiv;
		free(F);
		F=NULL;
		li->nb_film--;
		return li;
	}
	
	if(pos==li->nb_film){
    			while(F->suiv->suiv!=NULL) F=F->suiv;
    			free(F->suiv);
    			F->suiv=NULL;
    			li->fin=F;
    			li->nb_film--;
    			return li;
	}
	
	int i=1;
	while(i<pos-1){
		F=F->suiv;
		i++;
	}
	Film *temp=F->suiv;
	F->suiv=F->suiv->suiv;
	free(temp);
	temp=NULL;
	li->nb_film--;
	return li;
}

List *trie_inser_list(List *li){
	List *li_tri=create_list();	
	Film *fi=li->tete;
	while(fi!=NULL){
		inser_par_ordre(li_tri,fi);
		fi=fi->suiv;
	}
	free(li);
	li=NULL;
	return li_tri;

}


void affiche_list(List *li){
    Film *current=li->tete;
    int i=1;
    while(current!=NULL){
		printf("%d %s %s %d %dmin\n",i,current->nom,current->titre,current->anne,current->duree);	
        current=current->suiv;
        i++;
    }
}

int menu()
{
    int c;
    printf("\n\t\t-----------------------------------\n");
    printf("1 - Affichage de la liste tapez 	 .\n");
    printf("2 - Ajouter un film en tete  tapez  .\n");
    printf("3 - Ajouter un film a la fin tapez  .\n");
    printf("4 - Supprimer un film a la postion tapez  .\n");
    printf("5 - Afficher le film a la position : tapez  .\n");
    printf("6 - Trier la liste par ordre alphabitique croissant tapez .\n");
    printf("7 - Inverser l'ordere de la liste tapez  .\n");
    printf("8 - Inserer en ordere dans la liste tapez .\n");
    printf("0 - Pour Quiter tapez \n");
    printf("Votre choix! :");
    scanf("%d",&c);
    printf("\n\n");
    printf("\t\t-----------------------------------\n");
    return c;

}

int main()
{
    int c;
    List* li;
    li = create_list();
    Film *f;
    printf("\t\t-----------------------------------\n");
    printf("\t\t  Bonjour A la list des videoTech \n");
    do
    {
        c=menu();
        if (c==2 || c==3 || c==8){
			f=create_film();
        }
        system("clear");
        switch(c)
        {
            case 1:affiche_list(li);break;
     	    case 2:ajouter_tete_list(li,f);system("clear");break;
            case 3:ajouter_fin_list(li,f);break;
            case 4:suprimer_pos_list(li);system("clear");break;
            case 5:pos_film(li); system("clear");break;
            case 6:li=trie_inser_list(li);system("clear");break;
            case 7:li=invers_list(li);system("clear");break;
            case 8:inser_par_ordre(li,f);system("clear");break;
            case 0:printf("Au revoir .\n");system("clear");break;;
	    default :printf("Erreur de choix .\n");system("clear");break;
        }
    }while(c!=0);
}
