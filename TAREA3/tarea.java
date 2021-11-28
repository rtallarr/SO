import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

import java.util.*;
import java.util.stream.*;

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

    //SOLVER SUM
    public static void search_pair(List<Integer> numeros,List<Integer> indices, int size, int current){
        int temp_value;
        for (int i=0; i < size-1; i+=1) {
          temp_value=numeros.get(i)+numeros.get(current);
          if (temp_value == 65) {
            if ( i + current < indices.get(0)+ indices.get(1) && i < current){
                if (i < indices.get(0))
                  indices.set(0, i);
                  indices.set(1, current);
            }
          }
        }if (current < size-1) {
             search_pair(numeros,indices,size,current+=1);
        }
        return;
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
                            break;
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
            try {
                File myObj = new File("numeros.txt");
                Scanner myReader = new Scanner(myObj);
                List<Integer> data=new ArrayList<Integer>();
                List<Integer> index=new ArrayList<Integer>();
                while (myReader.hasNextLine()) {
                    List<String> data_tmp =Arrays.asList(myReader.nextLine().split(" "));
                    List<Integer> listInteger = data_tmp.stream().map(Integer::parseInt).collect(Collectors.toList());
                    data=Stream.concat(listInteger.stream(), data.stream()).collect(Collectors.toList());
                }
  
                int size = data.size();
                index.add(size);
                index.add(size);
                search_pair(data,index,size,0);
                System.out.println(data.get(index.get(0)));
                System.out.println(data.get(index.get(1)));
                myReader.close();
  
            } catch (FileNotFoundException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
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
        System.out.println("");

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