package tp.tp4.ex2;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String []args) throws IOException {

        Socket client = new Socket("localhost",19009);
        DataInputStream inputStream = new DataInputStream(client.getInputStream());
        DataOutputStream outputStream = new DataOutputStream(client.getOutputStream());
        Scanner scannerInput = new Scanner(System.in);
        while(true){
            System.out.print("nom de client : ");
            String clientName = scannerInput.nextLine();
            outputStream.writeUTF(clientName);
            System.out.println(inputStream.readUTF());
        }
    }
}
