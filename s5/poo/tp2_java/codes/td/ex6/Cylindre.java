package codes.td.ex6;

public class Cylindre implements Forme {
   private Disque disque;
   private double hauteur;

   public Cylindre() {
      disque = new Disque(0, 0, 0);
      hauteur = 0;
   }

   public Cylindre(double h, Disque d1) {
      hauteur = h;
      disque = d1;
   }

   public Cylindre(double h, double r, Point p) {
      hauteur = h;
      disque = new Disque(p, r);
   }

   public Cylindre(double x, double y, double rayon, double hauteur) {
      disque = new Disque(x, y, rayon);
      this.hauteur = hauteur;
   }

   public double calculeAire() {
      return 2 * PI * disque.getRayon() * hauteur;
   }

   public double calculeVolume() {
      return PI * disque.getRayon() * disque.getRayon() * hauteur;
   }

   public String toString() {
      return disque.toString() + ",hauteur=" + hauteur + ",aire=" + calculeAire() + ",volume=" + calculeVolume();
   }

}
