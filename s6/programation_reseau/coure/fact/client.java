package coure.fact;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class client {
    public static void main(String []args) throws IOException {
        Socket socket = new Socket("localhost",9909);
        DataOutputStream output = new DataOutputStream(socket.getOutputStream());
        DataInputStream input = new DataInputStream(socket.getInputStream());
        Scanner inputScanner = new Scanner(System.in);

        int nombre ;
        long resulta;


        System.out.print("Entrez un nombre : ");
        nombre = inputScanner.nextInt();
        while(nombre > 0) {
            output.writeInt(nombre);
            output.flush();

            resulta = input.readLong();
            System.out.println(nombre+"! = "+resulta+"\n");
            System.out.print("Entrez un nombre : ");
            nombre = inputScanner.nextInt();
        }
        socket.close();

    }
}
