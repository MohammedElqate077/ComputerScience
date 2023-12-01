package codes.td.ex6;

public class FormeTest {
   public static void main(String[] args) {

      Point p = new Point(1, 1);
      Disque d = new Disque(p, 20);

      Forme[] f = new Forme[3];
      f[0] = new Point(3, 6);
      f[1] = new Disque(p, 10);
      f[2] = new Cylindre(5.0, d);

      for (int i = 0; i < 3; i++) {
         System.out.println(f[i].toString());
         System.out.println(f[i].calculeVolume());
      }
   }
}
