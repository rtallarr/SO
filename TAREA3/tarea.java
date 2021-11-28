import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

// Java code for thread creation by extending
// the Thread class
class SimpleThread extends Thread {
    public long tiempo;
    public SimpleThread(String name){
        super(name);
    }

    public void setTime(long time){
        this.tiempo = time;
    }

    public void run() {
        if (getName() == "t1"){ //hebra 1
            try {
                File myObj = new File("palabras.txt");
                Scanner myReader = new Scanner(myObj);
                boolean flag = true;
                while (myReader.hasNextLine() && flag) {
                    String[] data = myReader.nextLine().split(" ");
                    for (String a : data){
                        if (a.equals("eiffel")){
                            System.out.println(a);
                            flag = false;
                        }
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
            long fin1 = java.lang.System.nanoTime();
            long duracion = fin1 - tiempo;
            System.out.println("Hebra 1 terminó en " + duracion + "[ns]");
        }

        if (getName() == "t2"){ //hebra 2
            System.out.println("hebra 2");
            long fin2 = java.lang.System.nanoTime();
            long duracion = fin2 - tiempo;
            System.out.println("Hebra 2 terminó en " + duracion + "[ns]");
        }
        
        if (getName() == "t3"){ //hebra 3
        String[] code = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                        "....", "..", ".---", "-.-", ".-..", "--", "-.",
                        "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
                        "...-", ".--", "-..-", "-.--", "--.."};

        String[] abc = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
                        "j", "k", "l", "m", "n", "o", "p", "q", "r",
                        "s", "t", "u", "v", "w", "x", "y", "z"};

        String traduccion = "";
            try {
                File myObj = new File("morse.txt");
                Scanner myReader = new Scanner(myObj);
                while (myReader.hasNextLine()) {
                    String[] data = myReader.nextLine().split("\n");
                    for (String word : data){
                        String letras[] = word.split(" ");
                        for (int j = 0; j < letras.length; j++){
                            for (int i = 0; i < code.length; i++){
                                if (code[i].equals(letras[j])){
                                    traduccion += abc[i];
                                }
                            }
                        }
                    traduccion += " ";
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
            System.out.println("traduccion: " + traduccion);
            long fin3 = java.lang.System.nanoTime();
            long duracion = fin3 - tiempo;
            System.out.println("Hebra 3 terminó en " + duracion + "[ns]");
        }
    }
}
 
// Main Class
public class tarea {
    public static void main(String[] args) {
        long inicio1 = java.lang.System.nanoTime();
        SimpleThread t1 = new SimpleThread("t1");
        t1.start();
        t1.setTime(inicio1);

        long inicio2 = java.lang.System.nanoTime();
        SimpleThread t2 = new SimpleThread("t2");
        t2.start();
        t2.setTime(inicio2);

        long inicio3 = java.lang.System.nanoTime();
        SimpleThread t3 = new SimpleThread("t3");
        t3.start();
        t3.setTime(inicio3);
    }
}