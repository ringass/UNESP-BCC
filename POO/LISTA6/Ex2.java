import java.util.*;

public class Ex2 {
    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        TreeSet<String> lista = new TreeSet<>();
        sc.nextLine();

        for(int i = 0; i < n; i++){
            String nome = sc.nextLine();
            lista.add(nome);
        }

       System.out.println("\n\n");
       lista.forEach(s -> {System.out.println(s);});
       
       sc.close();
    }
}
