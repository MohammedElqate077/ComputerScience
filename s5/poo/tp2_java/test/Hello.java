import java.io.*;
import java.util.*;

public class Hello {
   private int a = 4;
   class inerClass{
      public inerClass(){
         //Hello.this.print(); 
         print();
         System.out.println("inerclass " +a+4);
      }
   }
   public void print(){
      System.out.println("call out class "+a);
   }
   public static void main(String [] args){
      inerClass h = new Hello().new inerClass();


   }

}
