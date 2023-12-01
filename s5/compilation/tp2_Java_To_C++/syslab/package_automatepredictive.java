package automatepredictive; 
 
import java.util.Scanner; 
 
public class AutomatePredictive { 
 
    int cont; 
     
    char [] EnFirst;char [] EnFollow; char [] Synch; 
    char [] Vt={'a','b','c','d'}; 
    char [] Vn={'A','B','C','D'}; 
     
    static char [] tampon; 
    static char [] Ftampon; 
    static  char[] partieGauche; 
    static  char [] partieDroite; 
    char [] tabTerm; 
    char [] tabNonTerm; 

    public static void main(String[] args) { 
       AutomatePredictive aut=new AutomatePredictive(); 
        
       Scanner sc=new Scanner(System.in); 
       aut.construireGrammaire(); 
        

        
       System.out.println("1.calcul de first"); 
       int k=0; 
       do 
       {  
           tampon=aut.first(partieGauche[k]); 
           k++; 
            
       }while(partieGauche[k]!='$'); 
       System.out.println("2.calcul de follow"); 
       do 
       {  
           Ftampon=aut.follow(partieGauche[k]); 
           k++; 
            
       }while(partieGauche[k]!='$'); 
        
    } 
    public void construireGrammaire() 
    { 
        int m=0; 
        int noc=0; 
        partieDroite=new char[5]; 
        char affiche; 
        Scanner sk=new Scanner(System.in); 
        remplirTerminal(); 
        remplirNonTerminal(); 
        while(tabNonTerm[m]!='$' ) 
        { 
           System.out.println("Partie gauche:"+tabNonTerm[m]); 
           System.out.println("Partie droite: "); 

           affiche=sk.next().charAt(0);// problème je veux afficher une chaine de caractères 
           partieDroite[noc]=affiche;noc++; // pas sure 
            m++;    
        } 
    } 

     public void remplirNonTerminal() 
    { 
       char aff; 
       int j=0; 
      tabNonTerm=new char[6]; 
       Scanner sc=new Scanner(System.in); 
       do 
       { 
           System.out.println("Saisir un non  terminal:"); 
           aff=sc.nextLine().charAt(0); 
           tabNonTerm[j]=aff; 
           j++; 
       }while(aff!='$'); 
    } 
     public void remplirTerminal() 
    { 
       char aff; 
       int i=0; 
       tabTerm=new char[6]; 
       Scanner sc=new Scanner(System.in); 
       do 
       { 
           System.out.println("Saisir un terminal:"); 
           aff=sc.nextLine().charAt(0); 
           tabTerm[i]=aff; 
           i++; 

       }while(aff!='$'); 
    } 
     
     public boolean XEpsilon() 
     { 
         int m=0; 
         char X='X' ; 
         char eps='μ'; 
         if(partieDroite[m]==X && partieGauche[m]==eps) // déclarer un char X (alternative) m est pour une variables?  
         { 
             m++; 
             return true; 
         } 
         return false; 
     } 
    
   
    
    public boolean XAlpha() 
    { 
       int m=0; 
       char X='X'; 
       char alpha='f'; 
         if(partieDroite[m]==X && partieGauche[m]==alpha) 
         { 
             m++; 
             return true; 
         } 
         return false; 
     

         
   } 
    public void add(char [] table,char X) 
    { 
        int n=table.length; 
        table[++n]=X; 
    } 
   public char[]  first(char X) 
    { 
        int n=5; 
        char [] Y=new char[5]; 
        char f='f'; // choisir autre quue ça  
        int i=1; 
        int j=1; 
        int noc=0; 
        tampon=new char[6]; 
       EnFirst[0]='\0';// EnFirst={Ø} // EnFirst est un ensemble qui va contenir les firsts de X 
            if(X==Vt[noc]) 
            { 
                add(EnFirst,X);//EnFirst={X} 
                noc++; 
                 
            }else if( X==Vn[noc]) 
            { 
               if(XEpsilon()) // X→ε est une production)  
                { 
                add(EnFirst,'μ');//EnFirst= EnFirst+{ε} 
                } 
             do 
              { 
                tampon=first(f); 

                for(int m=0;m<tampon.length;m++) 
                { 
                  add(EnFirst,tampon[m]);   
                }//EnFirst= EnFirst+First(α) 
  
              }while(XAlpha() && f != 'μ'); 
             noc++; 
         }else if(List(Y,n))//X=Y1Y2.....Yn) 
             {  
                  tampon=first(Y[i]); 
                while(tampon[i]=='μ' && i<n)  
                   {  
                       if(tampon[j]!='μ') 
                        { 
                         add(EnFirst,tampon[j]); 
                         j++; 
                        }//EnFirst=EnFirst+(First(Yi)\ {ε}); 
                     i++; 
                   } 
                    add(EnFirst,tampon[i]);// EnFirst=EnFirst+FirstYi; 
             } 
         return EnFirst;       
    } 
    public boolean  List(char [] Y,int n) // pas vraii 
    { 
        char X; 
       for(int i=0;i<n;i++) 
       { 
           if(X==Y[i]) 
           { 
               return true; 

           } 
           else  
               return false; 
       } 
      return true;   
    }     
     
     
   public char[] follow(char X) 
    { 
        char beta='b'; // à s'assurer d initialisation 
        tampon=first(beta); 
        int k=0; 
        char A='A'; 
        char S='S'; 
        Ftampon=follow(A); 
        EnFollow[0]='\0';//EnFollow={Ø} // EnFollow est un ensemble qui va contenir les follows de X 
       if( X==axiome(S) )//(avec S est laxiome))  
         { 
           add(EnFollow,'$');//EnFollow=EnFollow+{$} 
         } 
        if(AalphaBeta()) 
             { 
                 if(tampon[k]!='μ') 
                    {add(EnFollow,tampon[k]);k++;}//EnFollow= EnFollow+ (First(β )\{ε}) 
                 else if( tampon[k]=='μ')  
                      {    
                          for(int q=0;q<EnFollow.length;q++) 
                          { 
                              add(EnFollow,Ftampon[q]); 
                          } 

                          k++; 
                      }//EnFollow= EnFollow+ Follow(A) 
             } 
             if( Aalpha()) 
                   { 
                       for(int p=0;p<EnFollow.length;p++) 
                           add(EnFollow,Ftampon[p]);  //EnFollow= EnFollow+ Follow(A); 
                    } 
                   return EnFollow; 
    } 
    public char axiome(char S) 
    { 
       if(S=='A'||S=='B'||S=='C'||S=='D' ) 
       { 
           if(partieGauche[0]=='S') 
           { 
               return S; 
           } 
       } 
       return S; 
    } 
     
    public boolean AalphaBeta() // A->alpha X beta 
    { 
        char A='A'; 
        char alpha='f'; 
        char X='X'; 
        char beta='t'; 
        int n=0; 
        if(partieDroite[n]==A && partieGauche[n]==alpha && partieGauche[n+1]==X && 
partieGauche[n+2]==beta) 

        { 
            n++; 
            return true; 
        } 
        return false;     
    } 
    public boolean Aalpha() // A->alpha X 
    { 
        char A='A'; 
        char alpha='f'; 
        char X='X'; 
         
        int n=0; 
        if(partieDroite[n]==A && partieGauche[n]==alpha && partieGauche[n+1]==X ) 
        { 
            n++; 
            return true; 
        } 
        return false;   
    } 
     
     
   
     
    public char [] synch(char S) 
    { 
        tampon=first(S); 
        Ftampon=follow(S); 
        for(int i=0;i<EnFirst.length;i++) 
        { 
            add(Synch,tampon[i]); 

        } 
        for(int j=0;j<EnFollow.length;j++) 
        { 
            add(Synch,Ftampon[j]); 
        } 
        return Synch; 
    } 
     
     
     
     
     
}