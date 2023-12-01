package coure.cole.a2022.ex3;

import java.net.ServerSocket;
import java.net.Socket;

public class MagServeur extends Thread {
    int port;
    ServerSocket serverSocket;
    Socket socket;

    public MagServeur(){}

    public MagServeur(int port){
        this.port = port;
        try{
           serverSocket = new ServerSocket(this.port);
        }catch (Exception e){}
    }

    public void accept(){
        try{
            socket = serverSocket.accept();
            new Thread(new ClientHandler(socket)).start();
        }catch (Exception e){}
    }

    public void run(){
        while(true){
            accept();
        }
    }
}
