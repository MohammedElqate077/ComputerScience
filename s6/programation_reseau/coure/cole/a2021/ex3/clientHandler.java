package coure.cole.a2021.ex3;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;

public class clientHandler implements Runnable{
    Socket socket;
    DataOutputStream output ;
    DataInputStream input ;
    private  String nom;
    private   int nbArticle;
    private   double []prixHorTax;
    private   double []TVA;
    private   double []TTC;

    public  double getPrixHorTax(){
        double sum = 0;
        for(int i = 0; i < nbArticle; ++i) {
            sum += prixHorTax[i];
        }
        return sum;
    }

    public  double getTVA(){
        TVA = new double [nbArticle];
        double sum = 0;
        for(int i = 0; i < nbArticle; ++i) {
            TVA[i] = 0.2 * prixHorTax[i];
            sum += TVA[i];
        }

        return sum;
    }
    public double getTTC(){
        TTC = new double [nbArticle];
        double sum = 0;
        for(int i = 0; i < nbArticle; ++i){
            TTC[i] = TVA[i]+prixHorTax[i];
            sum += TTC[i];
        }
        return sum;
    }
    public clientHandler(Socket socket){
        this.socket = socket;
    }

    public void run(){
        try {
            output = new DataOutputStream(socket.getOutputStream());
            input = new DataInputStream(socket.getInputStream());
            output.writeUTF("Enrez votre nom : ");
            nom = input.readUTF();
            System.out.println(nom);

            output.writeUTF("Enrez le nombre des article : ");
            nbArticle = input.readInt();
            System.out.println(nbArticle);


            prixHorTax = new double[nbArticle];

            for(int i = 0; i < nbArticle; ++i){
                output.writeUTF("\nEnrez prix hors tax de l'article "+(i)+" : ");
                prixHorTax[i] = input.readDouble();
            }

            output.writeDouble(getPrixHorTax());
            output.writeDouble(getTVA());
            output.writeDouble(getTTC());

            socket.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }


}


