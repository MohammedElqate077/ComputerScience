package codes.td.ex6;

public class Disque implements Forme {
   private Point centre;
   private double rayon;

   public Disque() {
      centre = new Point(0, 0);
      rayon = 0;
   }

   public Disque(Point p, double rayon) {
      centre = p;
      this.rayon = rayon;
   }

   public Disque(double x, double y, double rayon) {
      centre = new Point(x, y);
      this.rayon = rayon;
   }

   public double calculeAire() {
      return PI * rayon * rayon;
   }

   public double calculeVolume() {
      // n'a pas d'un volume;
      return 0;
   }

   public String toString() {
      return centre.toString() + ",rayon=" + rayon + ",aire" + calculeAire();
   }

   public Point getCentre() {
      return centre;
   }

   public double getRayon() {
      return rayon;
   }

   public void setCentre(double x, double y) {
      centre = new Point(x, y);
   }

   public void setRayon(double rayon) {
      this.rayon = rayon;
   }
}