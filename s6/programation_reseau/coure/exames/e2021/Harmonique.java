package coure.exames.e2021;

public class Harmonique implements Runnable{
    int n;
    public Harmonique(){}
    public Harmonique(int n){this.n = n;}
    public double sommme(int n){
        double sum = 0;
        for(int i = 1; i <=n; ++i ){
            sum += 1.0 / i;
        }
        return sum;
    }

    @Override
    public void run() {
       System.out.println("les premier terme de la serie jusqua "+n+" : "+sommme(n));
    }

    public static void main (String []args){
        Harmonique har;
        int a = 3;
        int b = 10;
        Thread thread1 = new Thread(new Harmonique(a));
        Thread thread2 = new Thread(new Harmonique(b));
        thread1.start();
        thread2.start();
    }
}
