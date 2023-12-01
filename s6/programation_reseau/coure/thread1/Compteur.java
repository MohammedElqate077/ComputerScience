package coure.thread1;

public class Compteur extends Thread{
    protected int count, inc, delay, Nit;

    public Compteur(int count, int inc, int delay, int Nit){
        this.count = count;
        this.inc = inc;
        this.delay = delay;
        this.Nit = Nit;
    }

    public void run(){
        try{
            for(int i = 0; i < Nit; ++i){
                System.out.print(count+" ");
                count +=inc ;
                sleep(delay);
            }
        }catch (InterruptedException e){}
    }

    public static void main (String []args){
        new Compteur(0,1,10,1000).start();
        new Compteur(0,-1,30,1000).start();
    }

}
