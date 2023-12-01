package youssfi;


import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import java.util.Scanner;

public class Server {
    private ServerSocket serverSocket;



    public static void main(String []args) throws IOException {
        ServerSocket ss = new ServerSocket(9090);
        System.out.println("En attend de connexion");
        try {
            while (true) {
                Socket s = ss.accept();
                System.out.println("connexion etalbire");
                Scanner input = new Scanner(System.in);
                try {
                    //DataInputStream in1 = new DataInputStream(s.getInputStream());
                    //String nomClient = in1.readUTF();
                    //String str = "Binevenu +" + nomClient + " , t'es bien connecte";
                    DataOutputStream out = new DataOutputStream(s.getOutputStream());
                    //out.writeUTF(str);
                    //out.writeUTF(new Date().toString());
                    out.writeUTF(input.nextLine());
                } finally {
                    s.close();
                }

            }
        }finally{
            ss.close();
        }
    }
}
