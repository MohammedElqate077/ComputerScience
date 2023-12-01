package coure.exames.e2021;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class ClientSocket {
    Socket socket;
    DataOutputStream outputStream;
    DataInputStream inputStream;

    public ClientSocket(String addresse, int port){
        try{
            socket = new Socket(addresse,port);
            outputStream = new DataOutputStream(socket.getOutputStream());
            inputStream = new DataInputStream(socket.getInputStream());
            System.out.println(inputStream.readUTF());
        } catch (Exception e) {}
    }

    public void calucleN(int N){
        try{
            outputStream.writeInt(N);
            System.out.println(inputStream.readDouble());
        }catch (Exception e){}
    }

    public static void main(String []args) throws IOException {
        ClientSocket clientSocket = new ClientSocket("localhost",50000);
        Scanner input = new Scanner(System.in);
        System.out.print("entrer un entier : ");
        clientSocket.calucleN(input.nextInt());
        clientSocket.socket.close();
    }

}
