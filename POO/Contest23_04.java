package POO;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Contest23_04 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        String input = reader.readLine();
        int n = Integer.parseInt(input);

        for (int i = 0; i < n; i++) {
            int m = Integer.parseInt(reader.readLine());
            Map<String, Float> precos = new HashMap<>();

            for (int j = 0; j < m; j++) {
                String nome = reader.readLine();
                float preco = Float.parseFloat(reader.readLine());
                precos.put(nome, preco);
            }

            int p = Integer.parseInt(reader.readLine());
            float total = 0.0f;

            for (int j = 0; j < p; j++) {
                String nome = sc.next();
                int qt =Integer.parseInt(reader.readLine());

                if (precos.containsKey(nome)) {
                    total += precos.get(nome) * qt;
                }
            }

            System.out.printf("R$ %.2f\n", total);
        }

        sc.close();
    }
}
