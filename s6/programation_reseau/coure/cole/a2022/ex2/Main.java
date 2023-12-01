package coure.cole.a2022.ex2;

public class Main {

    public static void main(String []args){
        ServeurCafe serveurCafe = new ServeurCafe(9000);
        ClientCafe clientCafe = new ClientCafe(9000);
        serveurCafe.start();
        clientCafe.start();
    }
}

/*
*  we set what the test in run methode inside Client and Server and then start main methode in Main Class
*   we use the threads on the client and server to allow execution Parallele of the two instance from
*   main methode , if not using them not work because the execution is not asyncrone is wating until
*   for example the return of accecpt methode and then the next instruction ,but cliendt connect methode not executed so
*   is piege who the prof used.
*/