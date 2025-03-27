
import java.io.IOException;
import java.util.*;

abstract class Usuario {

    public String nome, email;
    public int id;

    public void visualizarPerfil() {
        System.out.format("Nome: %s\nEmail: %s\nId: %d", nome, email, id);
    }
}

class Cliente extends Usuario {

}

class Entregador extends Usuario {

    String meioDeTransporte;
    boolean statusDisponivel;

}

class Restaurante extends Usuario {
    String nomeRestaurante;
    List<String> cardapio[];

}

class Pedido {
    Cliente cliente = new Cliente();
    Restaurante restaurante = new Restaurante();
    Entregador entregador = new Entregador();
    public double valor;
    List<String> cardapio = new ArrayList<String>();

    enum status {
        REALIZADO, EM_PREPARO, ENTREGUE
    };

    public void atualizarStatus() {

    }

    public void atribuirEntregador(Entregador cabrunco) {

    }

    public void resumoDoPedido() {

    }

}

class SistemaDelivery {

    List<Cliente> clientes = new ArrayList<Cliente>();
    List<Entregador> entregadores = new ArrayList<Entregador>();
    List<Restaurante> restaurantes = new ArrayList<Restaurante>();
    List<Pedido> pedidos = new ArrayList<Pedido>();

    public void Cadastrar() {

    }

    public void CriarPedido() {

    }

    public void verificarDisponibilidade() {

    }

    public void pedidos(int x) {

    }

}

public class Lista3 {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        boolean e = true;
        int escolha;
        while (e) {
            System.out.println("----- MENU -----\n");
            System.out.println("[1] - Cadastrar Cliente\n");
            System.out.println("[2] - Cadastrar restaurante\n");
            System.out.println("[3] - Cadastrar entregador\n");
            System.out.println("[4] - Criar novo pedido\n");
            System.out.println("[5] - Atribuir entregador a pedido\n");
            System.out.println("[6] - Atualizar status de pedido\n");
            System.out.println("[7] - Listar pedidos\n");
            System.out.println("[8] - Sair\n\n");

            System.out.println("Digite sua escolha: ");
            escolha = sc.nextInt();

            while (escolha < 1 || escolha > 8) {
                System.out.println("As Escolhas vao de 1 até 8, por favor digite sua escolha: ");
                escolha = sc.nextInt();
            }

            switch (escolha) {

                case (1): {

                }
                case (2): {

                }
                case (3): {

                }
                case (4): {

                }

                case (5): {

                }
                case (6): {

                }
                case (7): {

                }
                case (8): {
                    clrscr();
                    System.out.println("SESSAO FINALIZADA!!");
                    e = false;
                }

            }
        }

        sc.close();
    }


    public static void clrscr(){
        //Clears Screen in java
        try {
            if (System.getProperty("os.name").contains("Windows"))
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            else
                Runtime.getRuntime().exec("clear");
        } catch (IOException | InterruptedException ex) {}
    }
}
