package tp.tp4.ex2;

import java.net.ServerSocket;
import java.net.Socket;

public class ServeurThread {
    public static void main(String []args)throws Exception{
        try{
            ServerSocket serverSocket = new ServerSocket(19009);
            while(true){
                Socket socket = serverSocket.accept();
                System.out.println("Connexion etablie");
                new Thread(new ClientHandler(socket)).start();
            }
        }catch (Exception e){}
    }
}
