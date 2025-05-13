import java.util.Scanner;

public class Ex2 {

    int[][] matriz1;
    int[][] resultado;
    int[][] matriz2;
    int n;

    public static void main(String args[]){
        Ex2 programa = new Ex2(); 
        programa.executar();
    }

    public void executar() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite o tamanho das matrizes: ");
        n = sc.nextInt();

        matriz1 = new int[n][n];
        matriz2 = new int[n][n];
        resultado = new int[n][n];

        System.out.println("Matriz 1:");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                System.out.printf("M1[%d][%d]: ", i, j);
                matriz1[i][j] = sc.nextInt();
            }
        }

        System.out.println("\nMatriz 2:");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                System.out.printf("M2[%d][%d]: ", i, j);
                matriz2[i][j] = sc.nextInt();
            }
        }

        Thread t1 = new Thread(new SomaQuadrante(0, 0, n / 2, n / 2));         
        Thread t2 = new Thread(new SomaQuadrante(0, n / 2, n / 2, n));         
        Thread t3 = new Thread(new SomaQuadrante(n / 2, 0, n, n / 2));         
        Thread t4 = new Thread(new SomaQuadrante(n / 2, n / 2, n, n)); 

        t1.start();
        t2.start();
        t3.start();
        t4.start();

        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        }catch (InterruptedException e){
            e.printStackTrace();
        }
        
        System.out.println("\nMatriz Resultante");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                System.out.print(resultado[i][j] + " ");
            }      
            System.out.println();
        }

        sc.close();
    }

    class SomaQuadrante implements Runnable {

        int li, lf, cf, ci;

        public SomaQuadrante(int li, int ci, int lf, int cf){
            this.li = li;
            this.ci = ci;
            this.cf = cf;
            this.lf = lf;
        }

        @Override
        public void run(){
            for(int i = li; i < lf; i++){
                for(int j = ci; j < cf; j++){
                    resultado[i][j] = matriz1[i][j] + matriz2[i][j];
                }
            }
        }
    }
}
