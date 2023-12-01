package codes.cour.ex6;

abstract class Figure2D {
   protected double x, y;
   protected StringBuffer couleur;

   protected Figure2D() {
      x = y = 0;
      couleur = new StringBuffer();
   }

   protected Figure2D(double x, double y, StringBuffer couleur) {
      this.x = x;
      this.y = y;
      this.couleur = new StringBuffer(couleur);
   }

   public String toString() {
      return "x=" + x + ", y=" + y + ", couleur=" + couleur;
   }

   public abstract void changeEchelle(int x);
}

class Cercle extends Figure2D {
   private double rayon;

   public Cercle() {
      super();
   };

   public Cercle(double x, double y, StringBuffer couleur, double rayon) {
      super(x, y, couleur);
      this.rayon = rayon;
   };

   public void changeEchelle(int x) {
      rayon *= x;
   }

   public String toString() {
      String str = super.toString();
      return str + ", rayon =" + rayon;
   }
}

class Rectengle extends Figure2D {
   private double largeure, longeur;

   public Rectengle() {
      super();
      largeure = longeur = 0;
   }

   public Rectengle(double x, double y, StringBuffer couleur, double largeure, double longeur) {
      super(x, y, couleur);
      this.largeure = largeure;
      this.longeur = longeur;
   }

   public void changeEchelle(int x) {
      largeure *= x;
      longeur *= x;
   }

   public String toString() {
      String str = super.toString();
      return str + ", largeure=" + largeure + ", longeur=" + longeur;
   }
}

public class Ex6 {
   public static void main(String[] args) {
      StringBuffer couleur = new StringBuffer("rouge");
      Cercle cer = new Cercle();
      Cercle cer1 = new Cercle(2, 3, couleur, 3);
      Rectengle rec = new Rectengle();
      Rectengle rec1 = new Rectengle(2, 3, couleur, 3, 5);
      System.out.println(cer.toString());
      System.out.println(cer1.toString());
      System.out.println(rec.toString());
      System.out.println(rec1.toString());
      cer1.changeEchelle(10);
      rec1.changeEchelle(10);
      System.out.println(cer1.toString());
      System.out.println(rec1.toString());
   }
}