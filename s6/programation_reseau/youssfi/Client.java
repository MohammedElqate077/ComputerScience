package youssfi;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String [] args)throws IOException {
        Scanner inputScaner = new Scanner(System.in);
        //System.out.print("enrer l'address : ");
        //String serverAddresse = inputScaner.nextLine();

        Socket socket = new Socket("localhost", 9090);
        while (true) {
            //Socket socket = new Socket(serverAddresse, 9090);
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            System.out.println("anser is " + input.readLine());
        }
        //System.exit(0);
    }
}
