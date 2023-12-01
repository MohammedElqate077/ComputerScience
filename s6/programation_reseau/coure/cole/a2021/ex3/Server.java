package coure.cole.a2021.ex3;


import java.net.ServerSocket;
import java.net.Socket;



public class Server {

    public static void main(String []args)throws Exception{
        int counter = 1;
        try{
            ServerSocket serverSocket = new ServerSocket(19009);
            while(true){
                Socket socket = serverSocket.accept();
                System.out.println(counter+ " Connexion etablie");
                new Thread(new clientHandler(socket)).start();
                counter++;
            }
        }catch (Exception e){}
    }


}
