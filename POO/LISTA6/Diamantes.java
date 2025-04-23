import java.util.*;

public class Diamantes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for (int i = 0; i < n; i++) {
            String frase = sc.next();
            int qtConjunto = 0, chave = 0;
            
            for (int j = 0; j < frase.length(); j++) {
                if (frase.charAt(j) == '<') {
                    chave++;
                } else if (frase.charAt(j) == '>' && chave > 0) {
                    chave--;
                    qtConjunto++;
                }
            }
            
            System.out.println(qtConjunto);
        }
        sc.close();
    }
}
