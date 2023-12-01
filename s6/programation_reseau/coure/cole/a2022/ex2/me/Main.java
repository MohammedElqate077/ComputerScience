package coure.cole.a2022.ex2.me;

public class Main {

    public static void main(String []args){
        ServeurCafe serveurCafe = new ServeurCafe(9000);
        ClientCafe clientCafe = new ClientCafe(9000);
        serveurCafe.start();
        clientCafe.start();
    }

}
