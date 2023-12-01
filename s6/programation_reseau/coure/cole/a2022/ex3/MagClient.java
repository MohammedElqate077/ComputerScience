package coure.cole.a2022.ex3;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class MagClient extends Thread{
    int port;
    String ip_serveruSocket;
    Socket socket;
    DataInputStream inputStream;
    DataOutputStream outputStream;
    Scanner input;

    public MagClient(){}
    public MagClient(String ip_serveruSocket, int port){
        this.ip_serveruSocket = ip_serveruSocket;
        this.port = port;
    }

    public void connect(){
        try{
            socket = new Socket(ip_serveruSocket,port);
            inputStream = new DataInputStream(socket.getInputStream());
            outputStream = new DataOutputStream(socket.getOutputStream());
            input = new Scanner(System.in);
        }catch (Exception e){}
    }

    public void action() throws Exception{
        System.out.print(inputStream.readUTF()); //nom
        outputStream.writeUTF(input.nextLine());
        System.out.print(inputStream.readUTF()); //prenom
        outputStream.writeUTF(input.nextLine());
        System.out.print(inputStream.readUTF()); //n
        int n = input.nextInt();
        outputStream.writeInt(n);

        for(int i = 0; i < n; ++i) {
            System.out.print(inputStream.readUTF()); //nom
            outputStream.writeInt(input.nextInt());
            System.out.print(inputStream.readUTF()); //nom
            outputStream.writeDouble(input.nextDouble());
        }
        System.out.println(inputStream.readUTF()); //nom
    }

    public void run(){
        try {
            connect();
            sleep(300);
            action();
        } catch (Exception e) {
            //throw new RuntimeException(e);
        }
    }

}
