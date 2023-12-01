package codes.cour.ex7;

import java.security.DrbgParameters.NextBytes;
import java.util.List;

import javax.print.Doc;

abstract class Etudiant {
   protected StringBuffer nom;
   protected StringBuffer address;
   protected long numero;

   public Etudiant() {
      nom = new StringBuffer();
      address = new StringBuffer();
   }

   public Etudiant(StringBuffer nom, StringBuffer address, long numero) {
      this.nom = new StringBuffer(nom);
      this.address = new StringBuffer(address);
      this.numero = numero;
   }

   public String toString() {// should not be abstracted by me
      return nom + "," + address + "," + numero;
   }
}

class Licence extends Etudiant {
   protected StringBuffer parcours; // or use private;

   public Licence() {
      super();
      parcours = new StringBuffer();
   }

   public Licence(StringBuffer parcours) {
      super();
      this.parcours = new StringBuffer(parcours);
   }

   public Licence(StringBuffer parcours, StringBuffer n, StringBuffer add, long num) {
      super(n, add, num);
      this.parcours = new StringBuffer(parcours);
   }

   @Override
   public String toString() {
      // return parcours + "";// or use return parcours.toString();
      return super.toString() + "," + parcours;// or use return parcours.toString();
   }
}

class Master extends Licence {
   protected StringBuffer specialite;

   public Master() {
      super();
      specialite = new StringBuffer();
   }

   public Master(StringBuffer specialite) {
      super();
      this.specialite = new StringBuffer(specialite);
   }

   public Master(StringBuffer specialite, StringBuffer par, StringBuffer n, StringBuffer add, long num) {
      super(par, n, add, num);
      this.specialite = new StringBuffer(specialite);
   }

   @Override
   public String toString() {
      return super.toString() + "," + specialite;
   }
}

class Doctorat extends Master {
   protected StringBuffer directeurRecherche;

   public Doctorat() {
      super();
      directeurRecherche = new StringBuffer();
   }

   public Doctorat(StringBuffer directeurRecherche) {
      super();
      this.directeurRecherche = new StringBuffer(directeurRecherche);
   }

   public Doctorat(StringBuffer directeurRecherche, StringBuffer spe, StringBuffer par, StringBuffer n,
         StringBuffer add, long num) {
      super(spe, par, n, add, num);
      this.directeurRecherche = new StringBuffer(directeurRecherche);
   }

   @Override
   public String toString() {
      return super.toString() + "," + directeurRecherche;
   }
}

public class ListesEtudiants {
   public final static int maxEtudiants = 20000;
   public Etudiant[] listeEtudiants;
   public static int nombreEturdiant = 0;

   public ListesEtudiants() {
      listeEtudiants = new Etudiant[maxEtudiants];// or use lists
   }

   public ListesEtudiants(int N) {
      listeEtudiants = new Etudiant[N];
      // on peut ajouter plusieur choses;
   }

   public void addEtudiant(String type) {
      StringBuffer nom = new StringBuffer("med");
      StringBuffer add = new StringBuffer("dharMahraz");
      StringBuffer par = new StringBuffer("SMI");
      StringBuffer spe = new StringBuffer("AI");
      StringBuffer dir = new StringBuffer("bnbnbbnbn");
      long num = 7080401;

      if (nombreEturdiant < maxEtudiants) {
         if (type.equals("Licence")) {
            listeEtudiants[nombreEturdiant] = new Licence(par, nom, add, num);
            nombreEturdiant++;
         } else if (type.equals("Master")) {
            listeEtudiants[nombreEturdiant] = new Master(spe, par, nom, add, num);
            nombreEturdiant++;
         } else if (type.equals("Doctorat")) {
            listeEtudiants[nombreEturdiant] = new Doctorat(dir, spe, par, nom, add, num);
            nombreEturdiant++;
         }
      }else
         System.out.println("listeEtudiants est plein");
   }

   public int compteEtudiant(String type) {
      int compteur = 0;
      // for (Etudiant item : listeEtudiants) {
      for (int i = 0; i < nombreEturdiant; ++i) {
         if (listeEtudiants[i].getClass().getSimpleName().compareToIgnoreCase(type) == 0) {
            ++compteur;
         }
      }
      return compteur;
   }

   public void printEtud(String type) {
      for (int i = 0; i < nombreEturdiant; ++i) {
         if (listeEtudiants[i].getClass().getSimpleName().compareToIgnoreCase(type) == 0) {
            System.out.println(listeEtudiants[i].toString());
         }
      }
   }

   public void print() {

      for (int i = 0; i < nombreEturdiant; ++i) {
         System.out.println(listeEtudiants[i].toString());
      }
   }

   public static void main(String[] args) {
      ListesEtudiants li = new ListesEtudiants(10000);
      for (int i = 0; i < 7; ++i) {
         li.addEtudiant("Licence");
         li.addEtudiant("Master");
         li.addEtudiant("Doctorat");
      }

      System.out.println(li.nombreEturdiant);
      System.out.println(li.compteEtudiant("Licence"));
      // li.printEtud("Licence");
      // li.printEtud("Master");
      li.printEtud("Doctorat");
      // li.print();

   }
}