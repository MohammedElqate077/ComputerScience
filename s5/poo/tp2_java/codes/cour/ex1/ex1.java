package codes.cour.ex1;


class Essaai {
   public static int[] raz(int[] tab) {
      int[] tempTab = new int[tab.length];
      for (int i = 0; i < tab.length; ++i) {
         tempTab[i] = tab[i] = 0;
      }
      return tempTab;
   }
   public static void affiche(int[] tab){// or use Object class
      tab.toString();
   }
   public static int [] suite(int length){// or use Object class
      int []tab = new int [length];
      for (int i = 0; i < length; ++i) {
         tab[i] = i;
      }
      return tab;
   }
}

public class ex1 {
   public static void main(String[] args) {
      int [] tab = new int [7];
      tab = Essaai.suite(7);
      Essaai.affiche(tab);
      Essaai.raz(tab);
      Essaai.affiche(tab);
   }
}
