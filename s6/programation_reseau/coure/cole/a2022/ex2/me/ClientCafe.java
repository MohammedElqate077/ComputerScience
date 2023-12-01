package coure.cole.a2022.ex2.me;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class ClientCafe extends Thread{
    int port;
    String ip_serveur_cafe;
    Socket socket_client;

    Scanner input;
    DataInputStream inputStream;
    DataOutputStream outputStream;

    public ClientCafe(int port){
        this.port = port;
        try{
            input = new Scanner(System.in);
        }catch (Exception e){}
    }
    public void connect(String ip){
        ip_serveur_cafe = ip;
        try{
           socket_client = new Socket(ip_serveur_cafe,this.port);
        }catch(Exception e){}
    }

    public void choix(){
       try{
          //inputStream = new DataInputStream(socket_client.getInputStream());
          outputStream = new DataOutputStream(socket_client.getOutputStream());
          //System.out.println(inputStream.readUTF());
          System.out.print(" --> votre choix : ");
          outputStream.writeInt(input.nextInt());
          //System.out.println(inputStream.readUTF());
       }catch (Exception e){}
    }

    public void close(){
        try{
            input.close();
            inputStream.close();
            outputStream.close();
            socket_client.close();
        }catch (Exception e){}
    }

    public void run(){
        try {
            while (true) {
                sleep(300);
                connect("localhost");
                sleep(300);
                choix();
                //sleep(300);
                close();
            }
        }catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String []args){
        ClientCafe clientCafe = new ClientCafe(9000);
        clientCafe.connect("localhost");
        clientCafe.choix();
        clientCafe.close();
    }
}
