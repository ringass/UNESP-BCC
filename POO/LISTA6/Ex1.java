import java.util.*;

public class Ex1 {
    
    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Vector<String> lista = new Vector<>();
        sc.nextLine();

        for(int i = 0; i < n; i++){
            String nome = sc.nextLine();
            lista.add(nome);
        }

        Collections.sort(lista);

       System.out.println("\n\n");
       lista.forEach(s -> {System.out.println(s);});
       
       sc.close();
    }
}
