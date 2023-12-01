package codes.td.ex6;
import java.util.Scanner;

public class Point implements Forme {
   private double x, y;

   public Point() {
      Scanner input = new Scanner(System.in);
      System.out.print("x = ");
      x = input.nextInt();
      System.out.print("y = ");
      y = input.nextInt();
   }

   public Point(double x, double y) {
      this.x = x;
      this.y = y;
   }

   // point not have any aire or volume;

   @Override
   public double calculeAire() {
      return 0; 
   };

   @Override
   public double calculeVolume() {
      return 0;
   };

   @Override
   public String toString(){
      return "x=" + ",y="+y;
   }
}
