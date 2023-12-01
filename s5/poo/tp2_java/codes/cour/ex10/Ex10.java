package codes.cour.ex10;

abstract class Employer {
   StringBuffer nom;
   StringBuffer prenom;
   StringBuffer dateEntrer;
   byte age;

   public Employer() {
      nom = new StringBuffer();
      prenom = new StringBuffer();
      prenom = new StringBuffer();
   }

   public Employer(StringBuffer nom, StringBuffer prenom, StringBuffer dateEntrer, byte age) {
      this.nom = new StringBuffer(nom);
      this.prenom = new StringBuffer(prenom);
      this.dateEntrer = new StringBuffer(dateEntrer);
      this.age = age;
   }

   public String toString() {
      return nom + ", " + prenom + ", " + dateEntrer + "," + age;
   }

   public String toString(boolean t) {
      return nom + ", " + prenom + ", " + dateEntrer + "," + age;
   }

   public abstract double calculerSalaire();
}

abstract class Commercial extends Employer {
   private double chiffreAffaire;

   public Commercial() {
      super();
   }

   public Commercial(double chiffreAffaire, StringBuffer nom, StringBuffer pre, StringBuffer date, byte age) {
      super(nom, pre, date, age);
      this.chiffreAffaire = chiffreAffaire;
   }

   public double getChifreAffaire() {
      return chiffreAffaire;
   }

   public void settChifreAffaire(double chiffreAffaire) {
      this.chiffreAffaire = chiffreAffaire;
   }

   public String toString() {
      return chiffreAffaire + "";
   }

   public String toString(boolean t) {
      return super.toString() + ", " + chiffreAffaire;
   }
}

class Vendeur extends Commercial {
   public final static double pourcent = 0.2;

   public Vendeur() {

   }

   public Vendeur(double chiff, StringBuffer nom, StringBuffer pre, StringBuffer date, byte age) {
      super(chiff, nom, pre, date, age);
   }

   public double calculerSalaire() {
      return (double) (super.getChifreAffaire() * pourcent);
   }

   public String toString() {
      return pourcent + "";
   }

   public String toString(boolean t) {
      return super.toString(true) + ", " + pourcent;
   }

}

class Representant extends Commercial {
   public final static double pourcent = 0.1;

   public Representant() {
   }

   public Representant(double chiff, StringBuffer nom, StringBuffer pre, StringBuffer date, byte age) {
      super(chiff, nom, pre, date, age);
   }

   public double calculerSalaire() {
      return (double) super.getChifreAffaire() * pourcent;
   }

   public String toString() {
      return pourcent + "";
   }

   public String toString(boolean t) {
      return super.toString(true) + ", " + pourcent;
   }
}

class Technicien extends Employer {
   public final static byte salaire_unite = 50;
   public int nbUnite;

   public Technicien() {
   }

   public Technicien(int nbUnite, StringBuffer nom, StringBuffer pre, StringBuffer date, byte age) {
      super(nom, pre, date, age);
      this.nbUnite = nbUnite;
   }

   public Technicien(int nbUnite) {
      this.nbUnite = nbUnite;
   }

   public String toString() {
      return salaire_unite + ", " + nbUnite;
   }

   public String toString(boolean t) {
      return super.toString() + ", " + salaire_unite + ", " + nbUnite;
   }

   public double calculerSalaire() {
      return (double) nbUnite * salaire_unite;
   }

}

class Manutentionnaire extends Employer {
   public final static byte salaireHoraire = 100;
   public int nbHeures;

   public Manutentionnaire() {
   }

   public Manutentionnaire(int nbHeures,StringBuffer nom, StringBuffer pre, StringBuffer date, byte age) {
      super(nom, pre, date, age);
      this.nbHeures = nbHeures;
   }

   public Manutentionnaire(int nbHeures) {
      this.nbHeures = nbHeures;
   }

   public String toString() {
      return salaireHoraire + ", " + nbHeures;
   }

   public String toString(boolean t) {
      return super.toString() + ", " + salaireHoraire + ", " + nbHeures;
   }

   public double calculerSalaire() {
      return (double) nbHeures * salaireHoraire;
   }
}

/*
 * class TechnicienRisque extends Technicien implements Risque {
 * // lien
 * //
 * https://stackoverflow.com/questions/27156987/extend-and-implement-in-the-same
 * -class
 * // ma3rftch lach had lclass zayda wfach katkhdm hiya w l'interface risque
 * // elmohim zdtha wsafi
 * public double risqueReparation;
 * 
 * }
 * 
 * class ManutRisque extends Manutentionnaire implements Risque {
 * public double risqueFabriquation;
 * }
 */

// return to this test somting wrong;
public class Ex10 {
   public static void main(String[] args) {
      Employer[] listEmployer = new Employer[100];
      StringBuffer str0 = new StringBuffer("smi");
      StringBuffer str1 = new StringBuffer("fsdm");
      StringBuffer str2 = new StringBuffer("2022");
      for (int i = 0; i < 30; ++i) {
         if (i < 7) {
            listEmployer[i] = new Vendeur(10, str0, str1, str2, (byte) 10);

         } else if (i < 14) {
            listEmployer[i] = new Representant(20, str0, str1, str2, (byte) 10);

         } else if (i < 21) {
            listEmployer[i] = new Technicien(13,str0, str1, str2, (byte) 10);
         } else {
            listEmployer[i] = new Manutentionnaire(8,str0, str1, str2, (byte) 10);
         }
      }

      for (int i = 0; i < 30; ++i) {
         System.out.println(listEmployer[i].toString(true));
      }
   }
   //tantester el ba9i
}
