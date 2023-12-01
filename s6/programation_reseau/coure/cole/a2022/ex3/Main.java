package coure.cole.a2022.ex3;


public class Main {
    public static void main(String []args){
        MagServeur magServeur = new MagServeur(50000);
        MagClient magClient = new MagClient("localhost",50000);

        magServeur.start();
        magClient.start();
    }
}
