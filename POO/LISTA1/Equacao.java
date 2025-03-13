import java.util.Scanner;
import java.lang.Math;

public class Equacao {

    
    private int a;
    private int b;
    private int c;

    
    public Equacao(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    
    private double Delta() {
        return Math.pow(b, 2) - 4 * a * c;
    }

    
    public void calc() {
        double delta = Delta();

        if (delta < 0) {
            System.out.println("Sem raizes reais");
            return;
        }

        double raiz1 = (-b + Math.sqrt(delta)) / (2 * a);
        double raiz2 = (-b - Math.sqrt(delta)) / (2 * a);

        System.out.format("Raiz 1: %.1f, Raiz 2: %.1f%n", raiz1, raiz2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("coeficiente a:");
        int a = sc.nextInt();

        System.out.println("coeficiente b:");
        int b = sc.nextInt();

        System.out.println("coeficiente c:");
        int c = sc.nextInt();

        
        Equacao equacao = new Equacao(a, b, c);

        
        equacao.calc();

        sc.close();
    }
}