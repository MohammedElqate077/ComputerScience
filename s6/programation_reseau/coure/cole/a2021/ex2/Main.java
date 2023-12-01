package coure.cole.a2021.ex2;

public class Main {
    public static void main(String []args) throws InterruptedException {
        Rechecher1 rech1;
        Rechecher2 rech2;
        int [] T1 = {1,4,2,5,3,12,40,10};
        int [] T2 = {21,4,32,5,30,12,40,10};
        rech1 = new Rechecher1(T1,100);
        rech2 = new Rechecher2(T2,10);
        Thread t = new Thread(rech2);
        rech1.start();
        t.start();
    }
}
