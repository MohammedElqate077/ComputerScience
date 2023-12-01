package codes.cour.ex11;

import java.lang.Object;

class Documents {
   public int numero;
   public String titre;// or use StringBuffer;
   public int nbExemplaire;
   public static int nbDocument = 0;

   // public is default accec in java?
   public Documents() {
      nbDocument++;
      numero = nbDocument;
      // if I use encapsulation set ; don't needed
      titre = new String();
   }

   public Documents(String titre, int nbExemplaire) {
      nbDocument++;
      numero = nbDocument;
      this.titre = new String(titre);
      this.nbExemplaire = nbExemplaire;
   }

   public Documents(Documents doc) {
      /*
       * this.titre = new String(doc.titre);
       * this.nbExemplaire = doc.nbExemplaire;
       * nbDocument++;
       */
      this(doc.titre, doc.nbExemplaire);
   }

   public String toString() {
      return numero + ", " + titre + ", " + nbExemplaire;
   }

   public Object getObjectHere() {
      return this;
   }
}

class Livre extends Documents {
   public String auteur;
   public int nbPage;

   public Livre() {
      super();
      this.auteur = new String();
   }

   public Livre(String auteur, int nbPage) {
      // this();
      this.auteur = new String(auteur);
      this.nbPage = nbPage;
   }

   public Livre(String auteur, int nbPage, String tit, int nbEx) {
      super(tit, nbEx);// must be the one intruction in the bloc;
      // this() ;/!! can not call this and super in the same method;
      this.auteur = new String(auteur);
      this.nbPage = nbPage;
   }

   public Livre(Livre livre) {
      this(livre.auteur, livre.nbPage, livre.titre, livre.nbExemplaire);
      // or define all this here
   }

   public String toString() {
      return super.toString() + ", " + auteur + ", " + nbPage;
   }

   public Object getObjectHere() {
      return this;
   }
}

class Dictionnaire extends Livre {
   public String Langue;
   public int nbTome;

   public Dictionnaire() {
      super();
      this.Langue = new String();
   }

   public Dictionnaire(String Lange, int nbTome) {
      this.nbTome = nbTome;
   }

   public Dictionnaire(String Langue, int nbTom, String aut, int nbPage, String tit, int nbEx) {
      super(aut, nbPage, tit, nbEx);
      this.Langue = new String(Langue);
      this.nbPage = nbPage;
   }

   public Dictionnaire(Dictionnaire dic) {
      this(dic.Langue, dic.nbTome, dic.auteur, dic.nbPage, dic.titre, dic.nbExemplaire);
   }

   public String toString() {
      return super.toString() + ", " + Langue + ", " + nbTome;
   }

   public Object getObjectHere() {
      return this;
   }
}

class ListeDocuments {
   Documents[] liDoc;
   static int nbDocument = 0;

   // wach momkin nkhdmo polymorphisme m3a abstract class ou interface ?
   // tan9lb 3liha;
   public ListeDocuments() {
      liDoc = new Documents[100];
   }

   public ListeDocuments(int N) {
      liDoc = new Documents[N];
   }

   public void AjouterDocument(Documents document) {// no const equivalance in java
      if (nbDocument < liDoc.length) {
         // you can pass parametre to constractor to create object
         String str = document.getClass().getSimpleName();
         // if (document instanceof Documents) {// not work ;
         if (str.equals("Documents")) {
            liDoc[nbDocument] = new Documents((Documents) document.getObjectHere());
            liDoc[nbDocument].numero = document.numero;
            ++nbDocument;
         }
         if (str.equals("Livre")) {
            liDoc[nbDocument] = new Livre((Livre) document.getObjectHere());
            liDoc[nbDocument].numero = document.numero;
            ++nbDocument;
         } else { // if(str.equals("Dictionnaire")){
            liDoc[nbDocument] = new Dictionnaire((Dictionnaire) document.getObjectHere());
            liDoc[nbDocument].numero = document.numero;
            ++nbDocument;
         }
      }
   }

   public void listeDocuments() {
      System.out.println("\t** list documents **");
      for (int i = 0; i < liDoc.length && liDoc[i] != null; ++i) {
         System.out.println(liDoc[i].numero + ", " + liDoc[i].titre + ", " + liDoc[i].nbExemplaire);
         /*
          * if ((liDoc[i] instanceof Documents))
          * with this object has refrence to Documents and Livre or other;
          * tanchofha mnba3d;
          */
         /*
          * if ((liDoc[i].getClass().getSimpleName().equals("Documents")))
          * System.out.println(liDoc[i].toString());
          * else if ((liDoc[i].getClass().getSimpleName().equals("Livre")))
          * // System.out.println(liDoc[i].getClass().getSuperclass().toString());
          * // System.out.println(liDoc[i].getClass().getSuperclass().toString());
          * System.out.println(liDoc[i].toString());
          * else
          * System.out.println(liDoc[i].toString());
          */// had chi false ghir twachi masd9atch;

      }
   }

   public int compteDocument(String type) {
      int count = 0;
      for (int i = 0; i < liDoc.length && liDoc[i] != null; ++i) {
         if ((liDoc[i].getClass().getSimpleName()).compareTo(type) == 0)// equals
            ++count;
      }
      return count;
   }
}

public class Ex11 {
   public static void main(String[] args) {
      // if Document class not instanciable , define it abstract class;
      ListeDocuments li = new ListeDocuments(7);
      Livre livre = new Livre("Oussama", 150, "java", 250);
      Livre livre1 = new Livre("Meryem", 180, "c++", 421);
      livre.getClass().getSuperclass().toString();
      Dictionnaire dict = new Dictionnaire("Arab", 207, "Mohammed", 154, "java", 110);
      Dictionnaire dict2 = new Dictionnaire("Arab", 200, "Fatima", 156, "java", 150);
      li.AjouterDocument(livre);
      li.AjouterDocument(livre1);
      li.AjouterDocument(dict);
      li.AjouterDocument(dict2);
      li.listeDocuments();
      System.out.println("\nnbDocument:"+li.compteDocument("Documents"));
      System.out.println("nbLivre:"+li.compteDocument("Livre"));
      System.out.println("nbDictionnaire:"+li.compteDocument("Dictionnaire"));
   }

}
