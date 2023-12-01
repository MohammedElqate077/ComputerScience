package tp.tp4.ex2;

import tp.tp3.Client;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.lang.ref.Cleaner;
import java.net.Socket;
import java.util.Scanner;

public class ClientHandler implements Runnable{
    Socket socket;
    DataInputStream input;
    DataOutputStream output;
    Scanner scannerInput = new Scanner(System.in);

    public ClientHandler(Socket socket){
        this.socket = socket;
    }

    @Override
    public void run() {
       try{
           while(true) {
               input = new DataInputStream(socket.getInputStream());
               output = new DataOutputStream(socket.getOutputStream());
               String nomClient = input.readUTF();
               System.out.println(nomClient);
               output.writeUTF("Bienvenue " + nomClient);
           }
       } catch (Exception e) {
           throw new RuntimeException(e);
       }
    }
}
