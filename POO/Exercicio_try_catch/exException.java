package POO;

import java.util.Scanner;

// Exceção personalizada
class SaldoInsuficienteException extends Exception {
    public SaldoInsuficienteException(String message) {
        super(message);
    }
}

class ContaBancaria {
    double dinheiro;

    
    ContaBancaria(double salario) {
        dinheiro = salario;
    }

    
    public double Sacar(double valor) throws SaldoInsuficienteException {
        if (valor > dinheiro) {
            throw new SaldoInsuficienteException("Saldo insuficiente para realizar o saque.");
        }
        dinheiro = dinheiro - valor;
        return dinheiro;
    }

    
    public void ImprimeSaldo() {
        System.out.format("Saldo: R$ %.2f\n", dinheiro);
    }
}

public class exException {

    public static void main(String args[]) {
        ContaBancaria cc = new ContaBancaria(1200.00);
        Scanner sc = new Scanner(System.in);

        cc.ImprimeSaldo();

        while (true) { 
             
            System.out.format("Digite o valor que deseja sacar: ");
            double p = sc.nextDouble();  

            try {
                cc.Sacar(p); 
                cc.ImprimeSaldo();  
            } catch (SaldoInsuficienteException e) {
                System.out.println(e.getMessage());  
            }

            System.out.println("Deseja sacar mais dinheiro? (1/0)");
            int z = sc.nextInt();

            if(z == 0){
                sc.close();
                return;
            }

        } 
    }
}
