package coure.fact;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class server {
    public static long getFactoriel(int n){
       if(n == 0 || n==1) return 1;
       else return getFactoriel(n-1)*n;
    }


    public static void main(String []args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(9909);
        DataInputStream input ;
        DataOutputStream output;
        int nombre;


        System.out.println("attent de connexion");
        Socket socket = serverSocket.accept();
        System.out.println("connexion etalire");
        input = new DataInputStream(socket.getInputStream());
        output = new DataOutputStream(socket.getOutputStream());

        nombre = input.readInt();
        System.out.println(nombre);
        while(nombre > 0){

            output.writeLong(server.getFactoriel(nombre));
            output.flush();
            nombre = input.readInt();
        }

        socket.close();
        serverSocket.close();
    }
}
