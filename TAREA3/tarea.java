import java.util.Scanner;
import java.time.LocalTime;
import java.io.File;
import java.io.FileNotFoundException;

// Java code for thread creation by extending
// the Thread class
class SimpleThread extends Thread {
    public SimpleThread(String name){
        super(name);
    }

    public void run() {
        if (getName() == "t1"){ //hebra 1
            //System.out.println("aki t1. Hebra n° " + Thread.currentThread().getId());
            try {
                File myObj = new File("palabras.txt");
                Scanner myReader = new Scanner(myObj);
                while (myReader.hasNextLine()) {
                    String[] data = myReader.nextLine().split(" ");
                    for (String a : data){
                        if (a.equals("eiffel")){
                            System.out.println(a);
                        }
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
            LocalTime fin1 = java.time.LocalTime.now();
            System.out.println("Hebra 1 terminando a las "+ fin1);
        }

        if (getName() == "t2"){ //hebra 2
            try {
                File myObj = new File("numeros.txt");
                Scanner myReader = new Scanner(myObj);
                while (myReader.hasNextLine()) {
                    String[] data = myReader.nextLine().split(" ");
                    for (String a : data){
                        if (a.equals("eiffel")){
                            System.out.println(a);
                        }
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
            LocalTime fin2 = java.time.LocalTime.now();
            System.out.println("Hebra 2 terminando a las "+ fin2);
        }
        if (getName() == "t3"){ //hebra 3
            try {
                File myObj = new File("morse.txt");
                Scanner myReader = new Scanner(myObj);
                while (myReader.hasNextLine()) {
                    String[] data = myReader.nextLine().split(" ");
                    for (String a : data){
                        if (a.equals("eiffel")){
                            System.out.println(a);
                        }
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
            LocalTime fin3 = java.time.LocalTime.now();
            System.out.println("Hebra 3 terminando a las "+ fin3);
        }
    }
}
 
// Main Class
public class tarea {
    public static void main(String[] args) {
        LocalTime inicio1 = java.time.LocalTime.now();
        System.out.println("\nHebra 1 iniciando a las " + inicio1 + "\n");
        new SimpleThread("t1").start();

        //LocalTime inicio2 = java.time.LocalTime.now();
        //System.out.println("Hebra 2 iniciando a las " + inicio2 + "\n");
        //new SimpleThread("t2").start();
//
        //LocalTime inicio3 = java.time.LocalTime.now();
        //System.out.println("Hebra 3 iniciando a las " + inicio3 + "\n");
        //new SimpleThread("t3").start();
    }
}