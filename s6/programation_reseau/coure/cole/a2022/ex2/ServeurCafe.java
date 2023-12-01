package coure.cole.a2022.ex2;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class ServeurCafe extends Thread {
    int port;
    ServerSocket serveur_cafe;
    Socket socket_cafe;
    DataInputStream inputStream;
    DataOutputStream outputStream;

    //public ServeurCafe(){}
    public ServeurCafe(int port){
        this.port = port;
        try{
            serveur_cafe = new ServerSocket(this.port);
        }catch (Exception e){}
    }

    public void accecpt(){
       try{
          socket_cafe = serveur_cafe.accept();
          if(socket_cafe != null) {
              outputStream = new DataOutputStream(socket_cafe.getOutputStream());
              String msg = "Bonjour cher client\n";
              msg += "Pour demander cafe noir, tapez       1\t (12DH)\n";
              msg += "Pour demander The, tapez             2\t (13DH)\n";
              msg += "Pour demander Limonade, tapez        3\t (16DH)\n";
              msg += "Pour demander Jus(au choix), tapez   4\t (18DH)";
              outputStream.writeUTF(msg);
          }
       } catch (Exception e){}
    }

    public void lireChoix(){
        try{
            String name, monton,msg;
            inputStream = new DataInputStream(socket_cafe.getInputStream());
            int choix = inputStream.readInt();
            switch (choix){
                case 1:
                    name = "cafe noir";
                    monton = "(12 DH)";break;
                case 2:
                    name = "The";
                    monton = "(13 DH)";break;
                case 3:
                    name = "Limonade";
                    monton = "(16 DH)";break;
                case 4:
                    name = "Jus (au choix)";
                    monton = "(18 DH)";break;
                default:
                    name = "ce choix n'existe pas";
                    monton = "";
            }
            msg = "Vous avez choisi : "+name;
            msg += "\nVotre facture est de montant : "+monton;
            msg += "\nMercie de votre visite";
            outputStream.writeUTF(msg);
        }catch (Exception e){}
    }


    public void close(){
        try{
            inputStream.close();
            outputStream.close();
            socket_cafe.close();
            serveur_cafe.close();
        }catch (Exception e){}
    }

    public void run(){
        accecpt();
        lireChoix();
        close();
    }

    public static void main(String []args){//this if not use the Main class to test programe
        ServeurCafe serveurCafe = new ServeurCafe(9000);
        serveurCafe.accecpt();
        serveurCafe.lireChoix();
        serveurCafe.close();
    }
}
