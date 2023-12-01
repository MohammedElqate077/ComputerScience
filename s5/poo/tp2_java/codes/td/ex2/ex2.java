package codes.td.ex2;

import java.util.Arrays;
import java.util.Scanner;

public class ex2 {
    public static float[] some(float a[], float b[]) {
        float[] c = new float[a.length];
        if (a.length != b.length) {
            System.out.println("sompe imporsible difrent length");
        } else {
            for (int i = 0; i < c.length; ++i) {
                c[i] = a[i] + b[i];
            }

        }
        return c;
    }

    public static void affiche(float a[]) {
        System.out.println(Arrays.toString(a));
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n;
        System.out.println("entrer length of arry num 1");
        n = input.nextInt();
        float[] a = new float[n];
        System.out.println("donner les valeures de tableau num 1");
        for (int i = 0; i < n; ++i) {
            System.out.printf("value i+1 = " + i);
            a[i] = input.nextFloat();
        }

        System.out.println("entrer length of arry num 2");
        n = input.nextInt();
        float[] b = new float[n];
        System.out.println("donner les valeures de tableau num 2");
        for (int i = 0; i < n; ++i) {
            System.out.printf("value i+1 = " + i);
            b[i] = input.nextFloat();
        }
        input.close();
        System.out.println("a = " + Arrays.toString(a));
        System.out.println("b = " + Arrays.toString(b));
        System.out.print("some = ");
        ex2.affiche(ex2.some(a, b)); // if out of class
        // affiche(some(a, b)); // main in the same class of affiche and some methodes

    }
}