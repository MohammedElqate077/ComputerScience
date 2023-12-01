package coure.cole.a2021.ex3;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {

    public static void main(String []args) throws Exception{
        Socket socket = new Socket("localhost",19009);
        DataInputStream input = new DataInputStream(socket.getInputStream());
        DataOutputStream output = new DataOutputStream(socket.getOutputStream());

        Scanner scannerInput = new Scanner(System.in);
        int nbArticle = 0;

        System.out.println(socket.getInetAddress());
        System.out.println(socket.getPort());
        System.out.println(input.readUTF());
        output.writeUTF(scannerInput.nextLine());
        System.out.println(input.readUTF());
        nbArticle =  scannerInput.nextInt();
        output.writeInt(nbArticle);
        //nbArticle = scannerInput.nextInt();

        for(int i = 0; i < nbArticle; ++i){
            System.out.print(input.readUTF());
            output.writeDouble(scannerInput.nextDouble());
        }

        System.out.println("prix hors tax "+input.readDouble());
        System.out.println("TVA "+input.readDouble());
        System.out.println("TTC "+input.readDouble());

        socket.close();



    }
}
