import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int p = scanner.nextInt();
            int a = scanner.nextInt();
            int r = scanner.nextInt();
           
            if (p == 0 && a == 0 && r == 0) {
                break;
            }

            scanner.nextLine();  

            Set<String> perolas = new HashSet<>();
            for (int i = 0; i < p; i++) {
                perolas.add(scanner.nextLine().trim());
            }

            Map<String, Integer> alunosPerola = new HashMap<>();

            for (int i = 0; i < a; i++) {
                String nome = scanner.nextLine().trim();
                int CountPel = 0;

                for (int j = 0; j < r; j++) {
                    String ans = scanner.nextLine().trim();
                    if (perolas.contains(ans)) {
                        CountPel++;
                    }
                }

                alunosPerola.put(nome, CountPel);
            }

            int maxPerolas = Collections.max(alunosPerola.values());

            List<String> alunosComMaisPerolas = new ArrayList<>();
            for (Map.Entry<String, Integer> entry : alunosPerola.entrySet()) {
                if (entry.getValue() == maxPerolas) {
                    alunosComMaisPerolas.add(entry.getKey());
                }
            }

            Collections.sort(alunosComMaisPerolas);

            System.out.println(String.join(", ", alunosComMaisPerolas));
        }

        scanner.close();
    }
}