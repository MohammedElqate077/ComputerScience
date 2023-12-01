package coure.cole.a2022.ex3;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Date;

public class ClientHandler implements Runnable{
    Socket socket;
    DataInputStream inputStream;
    DataOutputStream outputStream;

    String nom, prenom;
    int n;
    int []n_k;
    double []pht_k;
    double p_ttc;

    public ClientHandler(Socket socket){
        this.socket = socket;
        try{
           inputStream = new DataInputStream(socket.getInputStream()) ;
           outputStream = new DataOutputStream(socket.getOutputStream());
        }catch (Exception e){}
    }

    public void action() throws IOException {
        outputStream.writeUTF("Entrer Le Nom : ");
        nom = inputStream.readUTF();
        outputStream.writeUTF("Entrer Le Prenom : ");
        prenom = inputStream.readUTF();
        outputStream.writeUTF("Entrer Le Nombre Des Articles : ");
        n = inputStream.readInt();
        n_k = new int[n];
        pht_k = new double[n];
        for(int i = 0; i < n; ++i) {
            outputStream.writeUTF("Entrer Le Piece De L'article " + i +" : ");
            n_k[i] = inputStream.readInt();
            outputStream.writeUTF("Entrer Le Prix Hors Tax : ");
            pht_k[i] = inputStream.readDouble();
        }
    }
    
    public double calcule(){
        double sum = 0;
        for (int i = 0; i < n; i++) {
           sum += 1.2 * n_k[i] * pht_k[i];
        }
        return sum;
    }

    public void Result() throws IOException {
        p_ttc = calcule();
        String msg = "\n\t** " + nom + " " +prenom +" **\n";
        msg += "Prix_TTC : "+p_ttc +"DH";
        msg += "\nDate : " + new Date();
        outputStream.writeUTF(msg);
    }

    @Override
    public void run() {
        try {
            action();
            calcule();
            Result();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
