package codes.td.ex3;

import java.util.Scanner;
import java.util.Arrays;

class Vecteur {
    private int N;
    private int[] tab;

    public Vecteur() {
        N = 0;
        tab = new int[0];
    }

    public Vecteur(int N) {
        this.N = N;
        tab = new int[N];
    }

    public Vecteur(int N, boolean input) {
        this.N = N;
        tab = new int[N];
        this.read();
    }

    public void read() {
        Scanner input = new Scanner(System.in);
        for (int i = 0; i < N; ++i) {
            System.out.printf("tab[%d] = ", i + 1);
            tab[i] = input.nextInt();
            System.out.println();
        }
    }

    public int getSize() {
        return N;
    }

    public void setSize(int N) {
        this.N = N;
        tab = new int[N];
    }

    public void setIndex(int index) {
        Scanner input = new Scanner(System.in);
        System.out.printf("tab[", +index + "] = ");
        tab[index] = input.nextInt();
    }

    public void print() {
        // System.out.println("vecteur :"+this);
        //System.out.println(this);
        System.out.println(Arrays.toString(tab));
    }

    public Vecteur some1(Vecteur v2) {
        if (this.N == v2.N) {
            for (int i = 0; i < this.N; i++) {
                this.tab[i] += v2.tab[i];
            }
            return this;
        }
        System.out.println("some imposible");
        return null;
    }

    public static Vecteur some2(Vecteur v1, Vecteur v2) {
        if (v1.N == v2.N) {
            Vecteur vect = new Vecteur(v1.N);
            for (int i = 0; i < vect.N; i++) {
                vect.tab[i] = v1.tab[i] + v2.tab[i];
            }
            return vect;
        }
        System.out.println("some imposible");
        return null;
    }
};

public class ex3 { // ex3 extendes Vecteur

    public static void main(String[] args) {
        Vecteur v1 = new Vecteur();
        Vecteur v2 = new Vecteur(3);
        Vecteur v3 = new Vecteur(3);
        Vecteur v4 = new Vecteur();
        v1.setSize(4);
        v4.setSize(3);
        v1.some1(v4);
        System.out.println("read v2");
        v2.read();
        System.out.println("read v3");
        v3.read();
        Vecteur vect = Vecteur.some2(v3, v2);

        Vecteur vecttt = v3.some1(v2);
        System.out.println("print v1");
        v1.print();
        System.out.println("print v2");
        v2.print();
        System.out.println("print v3");
        v3.print();
        System.out.println("print v4");
        v4.print();
        System.out.println("print some2");
        vect.print();
        System.out.println("print some1");
        vecttt.print();
    }
}
