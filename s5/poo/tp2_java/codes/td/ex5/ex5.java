package codes.td.ex5;


class Person {
   private String nom, prenom, profession;
   private int age;

   public Person(String n, String p, int a) {
      nom = n;
      prenom = p;
      profession = "";
      age = a;
   }

   public Person(String n, String p) {
      nom = n;
      prenom = p;
      profession = "";
      age = -1;
   }

   public Person(String nom, String prenom, String profession, int age) {
      this.nom = nom;
      this.prenom = prenom;
      this.age = age;
      this.profession = profession;
   }

   public String toString() {
      // System.out.printf("je m\'appelle %s %s, j\'ai %d ans",prenom,nom,age);
      if (age == -1) {
         return "je m'appelle " + prenom + " " + nom;
      } else
         return "je m'appelle " + prenom + " " + nom + " , j'ai " + age + " ans ";
   }
}

class Chanteur extends Person {
   public Chanteur(String nom, String prenom, int age) {
      super(nom, prenom, age);
   }

   public String toString() {
      return super.toString() + "et je suis un chanteur";
   }
}

class Etudiant extends Person {
   Etudiant(String nom, String prenom) {
      super(nom, prenom);
   }

   public String toString() {
      return super.toString() + " et je suis un etudiant ";
   }
}

public class ex5 {
   public static void main(String[] args) {

      Person p1 = new Person("ahmadi", "ahmed");
      Person p2 = new Person("jillali ", "jalal", 20);
      Person p3 = new Person("allaoui ", "ali", "medecin", 45);
      System.out.println(p1.toString());
      System.out.println(p2.toString());
      System.out.println(p3.toString());

      Chanteur c1 = new Chanteur("n.chanteur1", "p.chanteur1 ", 22);
      System.out.println(c1.toString());

      Etudiant e1 = new Etudiant("n.etudiant1", "p.enom etudiant1 ");
      System.out.println(e1.toString());

   }
}
