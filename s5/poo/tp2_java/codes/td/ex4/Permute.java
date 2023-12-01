import java.io.*;
import java.util.*;


public class Permute{
   public Permute(String str1, String str2){
      String temp = str1;
      str1 = str2;
      str2 = temp;
   }

   public static void permute(String str1, String str2){
      String temp = new String ();
      temp = str1;
      if(str1 != str2){
         str1 = str2;
         str2 = temp;
      }
      else System.out.println("permutation of the same Object");
   }

   /*public static String [] readStrings(int N){
     String []temp = new String [N];
     Scanner input = new Scanner(System.in);
     for(int i = 0; i < N; ++i){
     System.out.printf("string number %d : ",i+1);
     temp [i] = input.nextLine();
     input.nextLine();
     }
     return temp;
     }*/

   public static String [] readStrings(int N){
      String []temp = new String [N];
      Scanner input = new Scanner(System.in);
      for(String element : temp){
         for (int i = 0; i < N; ++i)	{
            System.out.printf("string number %d : ",i+1);
            temp [i] = input.nextLine();
            input.nextLine();
         }	
      }
      return temp;
   }

   public static String [] trier(String []str){
      for(int i = 0; i < str.length - 1; ++i){
         int min = i;
         for(int j = i + 1; j < str.length; ++j){
            if(str[min].compareTo(str[j]) < 0)
               min = j;
         }
         if(min != i){
            permute(str[min],str[i]);
            /*String temp = str[i];
            str[i] = str[min];
            str[min] = temp;*/
         }
      }
      System.out.println("trier");
      System.out.println(Arrays.toString(str));
      return str;
   }



   public static void main(String [] args){
      String [] str = new String [7];
      
       str[0]= new String ("aatome") ;
       str[1]= new String ("Hello") ;
       str[2]= new String ("world") ;
       str[3]= new String ("de") ;
       str[4]= new String ("bike") ;
       str[5]= new String ("zakoura") ;
       str[6]= new String ("algerie") ;

      /*
      String str[0]= new String ("aatome") ;
      String str[1]= new String ("Hello") ;
      String str[2]= new String ("world") ;
      String str[3]= new String ("de") ;
      String str[4]= new String ("bike") ;
      String str[5]= new String ("zakoura") ;
      String str[6]= new String ("algerie") ;
       */

      trier(str);

      System.out.println(Arrays.toString(str));
      //Permute.permute (str1,str2);
      //System.out.println(str1 + " " + str2);
      //Permute.permute (str1,str2);	
      Permute.permute (str[1],str[2]);	
      System.out.println(str[1] + " " + str[2]);
      //String [] testStr = Permute.readStrings(3);
      //Permute a = new Permute();
      //Permute b = new Permute();
      //System.out.prinln(a.getClass().equals(b.getClass()));

   }
}
