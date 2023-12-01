import java.io.*;
//import java.util.*;
import java.util.Scanner;
import java.util.Arrays;
//import java.util.Math;
import javax.swing.*;

class Hello {
	public static void main(String args[]) {
    /* we have this type byte , boolean , float, double ,int ,String , long , short , char + object type*/
      System.out.println("heloo world!");// print mssg;
      String name = "omar khatab";//String using this String class;
      /* print() : whitout return to new line;
      	 println(): the same as above but return to new line;
      	 printf() : this printf() function of c programming the same concept;
      */
      	 System.out.println(name.length());//length() for string and length withou () for arrays;
      	 System.out.println(name.charAt(0));
      	 System.out.println(name.indexOf("x"));
      	 System.out.println(name.indexOf("khatab"));
      	 System.out.println(name.substring(3));
      	 System.out.println(name.substring(4,7));
      	 System.out.println(5 * 5);
      	 System.out.println(10 * 2);
      	 System.out.println(1 + 5 * 5);
      	 System.out.println(10 / 3.5);
      Scanner input = new Scanner(System.in); // 
      /*for input usealy we use Scanner class , we create a object with parameter System.in;
      and use this objectName.nextType(); function to read from user with type you want;
       	* to clear the input stream use objectName.nextLine();
        * to close the input we use objectName.close();
      */
       	System.out.print("inter value ");
       	int intt = input.nextInt();
       	System.out.print("float value ");
       	float floatt = input.nextFloat();
       	System.out.print("double value ");
       	double doublee = input.nextDouble();
      //char charr = input.nextChar();
       	input.nextLine();
       	System.out.print("string value ");
       	String stringg = input.nextLine();
       	System.out.println("int "+ intt);
       	System.out.println("float "+ floatt);
       	System.out.println("double "+ doublee);
      //System.out.println("charr", charr);
       	System.out.println("String "+ stringg);
       	int [] array = {1,2,3,4,5}; 
      /* to create array we use type [] nameArray 
      	we can do do as above;
      	array = new [lengthYouWant];
      	*** to print array use import Arrays class wich in the util libaray; 
      	import java.util.Array ,.Saccaner /// we use all classes in the util  using java.util.*
		
		for printing :: Arrays.toString(arrayName);
          2 dimential :: Arrays.deepToString(matrixName); // 2 dimential arraygg;
		===========================
        to create multidimentil array we use type [][] nameArray  // and more for 3 [][][] array ... 
        array.length(); return nember of elemetn in the array ;
        you can use arrayName[idex] to acces to a element;
        -- int [2][3]array = {{1,2,3},{1,3,3}} // int [][]array = {{2,3},{23,423}}; // array [i][j];
        often like C ;
      */
        System.out.println(Arrays.toString(array));
      /*
		we use math function like this Math.fnct(arg1,arg2,....); // Math is a class;
      */
		System.out.println(Math.pow(2,4));
		System.out.println(Math.sqrt(24));
		System.out.println(Math.round(24));
		input.close();

      //System.out.println(5 / 0);


      ///// =======================  dynamic array  ==================================
      /*
      	// probaly like vector in c++;
		import java.util.ArrayList;
		ArrayList <type you want> arrayName = new ArrayList <typeWichYouSpicific>();
		array.add(args); // to add element to your array;
      */
  ArrayList<String> friends = new ArrayList<String>();
    friends.add("Oscar");
    friends.add("Angela");
    friends.add("Kevin");
    friends.remove("Oscar");
    System.out.println(friends.toString()); // print the array
    System.out.println(friends.get(1));// get element // element start with 0(zero);
    System.out.println(friends.contains("Oscar")); // if the value existe, return ture or false
    System.out.println(friends.contains("Angela"));
    System.out.println(friends.toString());
    System.out.println(friends.size());// print the size of this << vector >> ;


    // to compare 2 string we use "string1".equals("string2")
    ///// ======================== oop ===========================
    /*
      *constractor : if not create a constractor java build default constractor;
    */ 



	}
}
