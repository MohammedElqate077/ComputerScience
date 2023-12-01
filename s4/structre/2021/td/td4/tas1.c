//Les tasse
// indice i, a comme pere (i - 1)/2;fils gauche 2i + 1; fils droite 2i + 2;
// 2i + 1 >= n  --> case d'indice i est une feuille;
// 2i + 2 >= n ,case d'indice i n'a pas de fils droit;
//  POUR LE TAS MIN EST SUPRIMER MIN C'EST LE MEME PRINCIPE ;
//
typedef struct
{
    int tab[max];
    int taille;
}tas;

//fct sert a cree une tas
tas* cree_tas()
{
    tas* t = (tas*)malloc(sizeof(tas));
    t->taille = 0;
    return t;
}

//fait l'echange entre 2 valeurs entier
void echanger(int *a,int *b)
{
    int temp;
    temp = *a;*a = *b;*b = temp;
}

//iiserer ui elemeit ei respectait le priicipe des tas
void inserer_tas(tas* t,int val)
{
    int i = t->taille++;
    t->tab[i] = val;
    while(i > 0)
    {
        if(t->tab[i] > t->tab[(i-1)/2] )
        {
            echanger(&t->tab[i],&t->tab[(i-1)/2]);
            i = (i-1)/2;
        }else return;
    }
}
//entasser_max version recursive , non recurcive est utilser ds suprimer max;
void entasser_max(tas *t,int i){
    int k;
    if(2*i+1>n || 2*i+2>n) return; 

    if(t->tab[2*i+1] > t->tab[2*i+2] ) //on chosit le plus grand entre les 2 fils
	    k = 2*i + 1;
    else k = 2*i + 2;

    if(t->tab[i] < t->tab[k]){ //indice pere est petit que son fils,donc on fait l'echange
        echanger(&t->tab[i],&t->tab[k]);
	entasser_max(t,k);
    }
    
}

//suprimer max entulisan entasser_max;
tas *suprimer_max(tas *t){
	//on supose que le tas t est nom vide;
	t->taille--;
	t->tab[0]=t->tab[t->taille];
	entasser_max(t,0);
	return t;
}

//supprime un element en respectant le principe des tas // comme version iteratif;
void supprimer_max(tas* t)
{
    int n = --t->taille,k,i = 0;
    int* tab = t->tab;
    tab[0] = tab[n];
    while(2*i + 1 < n) //tanque on n'a pas arriver a une feuille
    {
        if( (2*i + 2 == n) || (tab[2*i+1] >= tab[2*i+2]) ) k = 2*i + 1;//on chosit le plus grand entre les 2 fils
        else k = 2*i + 2;
        if(tab[i] < tab[k])//indice pere est petit que son fils,donc on fait l'echange
        {
            echanger(&tab[i],&tab[k]);
            i = k;
        }
        else return;// rien a echanger,donc on quite la fct
    }
}

// pour trasnformer un tableau en tas /ou bien ajouter_en_tas(TAS,i) ds une new tas apar origine tas;
tas* construire(tas *t){
	for(int i=t->(taille-1)/2;i>=1;i++){
		entasser_max(t,i);
	}
	return t;
}

void tri_par_tass(tas *t){
	//on construire le tas puis en trie par tas;
	t=construire(t);
	for(int i=t->(taille-1)/2;i>=1;i++){
        	echanger(&tab[0],&tab[i]);
		t->taille--;
		entasser_max(t,0);
	}
	return t;
}
}

void afficher_tas(tas* t)
{
    for(int i = 0;i < t->taille;i++)
    {
        printf("%7d",t->tab[i]);
    }
    printf("\n");
}
