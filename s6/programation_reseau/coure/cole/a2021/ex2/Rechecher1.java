package coure.cole.a2021.ex2;

public class Rechecher1 extends Thread{
    private int [] T;
    private int val;

    public int existe(int []T, int val){
        for (int i = 0; i < T.length; ++i){
            if(T[i] == val)
                return i;
        }
        return -1;
    }

    public Rechecher1(int []T, int val){
        this.T = T;
        this.val = val;
    }

    public void run(){
        if(existe(T,val)!=-1)
            System.out.println("ok 1");
        else
            System.out.println("NO 1");

    }


}
