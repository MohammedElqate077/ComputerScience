package coure.exames.e2021;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
public class Serversocket {
    ServerSocket serverSocket;
    Socket socket;
    DataOutputStream outputStream;
    DataInputStream inputStream;
    public Serversocket(int port){
        try{
            serverSocket = new ServerSocket(port);
            System.out.println("waiting connection ...");
            socket = serverSocket.accept();
            System.out.println("connection established to host "+socket.getInetAddress()+" on port "+socket.getPort());
            outputStream = new DataOutputStream(socket.getOutputStream());
            outputStream.writeUTF("connextion established");
        }catch (Exception e){}
    }

    public void getHaromnie(){
        Harmonique har = new Harmonique();
        try {
            inputStream = new DataInputStream(socket.getInputStream());
            outputStream.writeDouble(har.sommme(inputStream.readInt()));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String []args) throws Exception{
        Serversocket serversocket = new Serversocket(50000);
        serversocket.getHaromnie();
        serversocket.socket.close();
        serversocket.serverSocket.close();
    }
}
