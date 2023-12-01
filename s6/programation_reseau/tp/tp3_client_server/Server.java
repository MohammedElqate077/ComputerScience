package tp.tp3;


import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;



public class Server {
    public static String nom;
    public static String prenom;
    public static int nbArticle;
    public static double []prixHorTax;
    public static double []TVA;
    public static double []TTC;

    public static double getPrixHorTax(){
        double sum = 0;
        for(int i = 0; i < nbArticle; ++i) {
            sum += prixHorTax[i];
        }
        return sum;
    }

    public static double getTVA(){
        TVA = new double [nbArticle];
        double sum = 0;
        for(int i = 0; i < nbArticle; ++i) {
            TVA[i] = 0.2 * prixHorTax[i];
            sum += TVA[i];
        }

        return sum;
    }
    public static double getTTC(){
        TTC = new double [nbArticle];
        double sum = 0;
        for(int i = 0; i < nbArticle; ++i){
            TTC[i] = TVA[i]+prixHorTax[i];
            sum += TTC[i];
        }
        return sum;
    }

    public static void main(String []args) throws Exception {
        ServerSocket serverSocket = new ServerSocket(64003);
        System.out.println("server lissen for incomming connection");
        Socket socket = serverSocket.accept();
        System.out.println("a connexion established");
        DataOutputStream output = new DataOutputStream(socket.getOutputStream());
        DataInputStream input = new DataInputStream(socket.getInputStream());

            output.writeUTF("Enrez votre nom : ");
            Server.nom = input.readUTF();
            System.out.println(Server.nom);

            output.writeUTF("Enrez votre prenom : ");
            Server.prenom = input.readUTF();
            System.out.println(Server.prenom);

            output.writeUTF("Enrez le nombre des article : ");
            Server.nbArticle = input.readInt();
            System.out.println(Server.nbArticle);


            Server.prixHorTax = new double[Server.nbArticle];

            for(int i = 0; i < Server.nbArticle; ++i){
                output.writeUTF("\nEnrez prix hors tax de l'article "+i+1+" : ");
                prixHorTax[i] = input.readDouble();
            }

            output.writeDouble(getPrixHorTax());
            output.writeDouble(getTVA());
            output.writeDouble(getTTC());


        socket.close();

    }
}
