package tp.tp4.ex1;

public class Thread0 extends Thread{
    String name;
    public Thread0(String name){
        this.name = name;
    }

    public void run(){
        for(int i = 0; i < 100; ++i){
            try{
                //sleep((long) Math.random() * 100);
                sleep(500);

            }catch(InterruptedException e){
                e.getStackTrace();
            }
            System.out.print(name+" ");
            //System.out.println("");
            if(i == 10)
                System.out.println();
        }
    }

    public static void main(String []args){
        Thread0 a = new Thread0("aaa");
        Thread0 b = new Thread0("bbb");
        Thread0 c = new Thread0("ccc");
        Thread0 d = new Thread0("ddd");
        Thread0 e = new Thread0("eee");
        Thread0 f = new Thread0("fff");
        Thread0 h = new Thread0("hhh");
        Thread0 i = new Thread0("iii");
        Thread0 j = new Thread0("jjj");
        Thread0 k = new Thread0("kkk");
        a.start();
        b.start();
        c.start();
        d.start();
        e.start();
        f.start();
        h.start();
        i.start();
        j.start();
        k.start();
    }

}
