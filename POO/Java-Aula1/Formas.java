import java.util.Scanner;

interface FormaGeometrica {
    public double pi = 3.141592;

    double calcularArea();

    double calcularPerimetro();

    void getName();

}

public class Formas {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int i = 0;
        FormaGeometrica[] formas = new FormaGeometrica[5];

        while (i < 5) {
            System.out.println("Deseja inserir um Circulo (1) ou Retangulo(2)?");
            int p = sc.nextInt();

            if (p == 1) {
                System.out.println("Raio do Circulo: ");
                double r = sc.nextDouble();

                Circulo a = new Circulo(r);

                formas[i] = a;

            } else {
                System.out.println("Altura e Largura: ");
                double x = sc.nextDouble();
                double y = sc.nextDouble();

                Retangulo a = new Retangulo(x, y);

                formas[i] = a;
            }

            i++;
        }

        for (int j = 0; j < 5; j++) {
            if (formas != null) {

                formas[j].getName();
                System.out.format("Area: %.4f\n", formas[j].calcularArea());
                System.out.format("Perimetro: %.4f\n", formas[j].calcularPerimetro());
                System.out.println();
            }

        }
        sc.close();

    }
}

class Circulo implements FormaGeometrica {

    public double r;

    Circulo(double r) {
        this.r = r;
    }

    @Override
    public void getName() {
        System.err.println("Forma: Circulo");
    }

    @Override
    public double calcularArea() {
        double x = FormaGeometrica.pi * r * r;

        return x;
    }

    @Override
    public double calcularPerimetro() {
        double x = FormaGeometrica.pi * 2 * r;

        return x;
    }

}

class Retangulo implements FormaGeometrica {
    public double x, y;

    Retangulo(double x, double y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public void getName() {
        System.err.println("Forma: Retangulo");
    }

    @Override
    public double calcularArea() {
        double A = x * y;

        return A;
    }

    @Override
    public double calcularPerimetro() {
        double P = 2 * (x * y);
        return P;
    }
}
