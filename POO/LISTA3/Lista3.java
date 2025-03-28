
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

    Cliente(String nome, String email, int id) {
        this.nome = nome;
        this.email = email;
        this.id = id;
    }

    @Override
    public void visualizarPerfil() {
        System.out.println("-- Dados do Cliente --");
        System.out.format("Nome: %s\nEmail: %s\nId: %d", nome, email, id);
    }

}

class Entregador extends Usuario {

    String meioDeTransporte;
    boolean status;

    Entregador(String nome, String email, int id, boolean status, String meioDeTransporte) {
        this.nome = nome;
        this.email = email;
        this.id = id;
        this.status = status;
        this.meioDeTransporte = meioDeTransporte;
    }

}

class Restaurante extends Usuario {
    String nomeRestaurante;
    Map<String, Double> cardapio;

    Restaurante(String nome, String email, int id, String nomeRestaurante, Map<String, Double> cardapio) {
        this.nome = nome;
        this.email = email;
        this.id = id;
        this.nomeRestaurante = nomeRestaurante;
        this.cardapio = cardapio;
    }
}

class Pedido {

    Cliente cliente;
    Restaurante restaurante;
    Entregador entregador;
    public double valor;
    Map<String, Double> itens;

    Pedido(Cliente cliente, Restaurante restaurante, Map<String, Double> itens, int valor) {
        this.cliente = cliente;
        this.restaurante = restaurante;
        this.itens = itens;
        this.valor = 0.0;
    }

    enum Status {
        REALIZADO, EM_PREPARO, ENTREGUE;
    };

    Status status = Status.EM_PREPARO;

    public void atualizarStatus(Status newStatus) {
        status = newStatus;
    }

    public void atribuirEntregador(Entregador cabrunco) {
        entregador = cabrunco;
    }

    public void resumoDoPedido() {
        System.out.printf("Nome: %s" +
                "Restaurante: %s", cliente.nome, restaurante.nomeRestaurante);
        for (String p : itens) {
            System.out.println(p);
        }
        System.out.println("Entregador: " + entregador.nome);
        System.out.println("Valor do Pedido: " + valor);
        System.out.println("Status: " + status);
    }
}

class SistemaDelivery {

    List<Cliente> clientes = new ArrayList<Cliente>();
    List<Entregador> entregadores = new ArrayList<Entregador>();
    List<Restaurante> restaurantes = new ArrayList<Restaurante>();
    List<Pedido> pedidos = new ArrayList<Pedido>();

    public void Cadastrar(int x, Scanner sc) {

        if (x == 1) {
            System.out.println("== CADASTRO DE CLIENTE ==");
            System.out.println("Digite o nome completo: ");
            String newName = sc.nextLine();
            System.out.println("Digite o email: ");
            String newEmail = sc.nextLine();

            int newId = clientes.size() + 1;

            Cliente newCliente = new Cliente(newName, newEmail, newId);

            clientes.add(newCliente);

        } else if (x == 2) {
            Map<String, Double> menu = new HashMap<>();

            int newId = restaurantes.size() + 1;

            System.out.println("== CADASTRO DE RESTAURANTE ==");
            System.out.println("Digite o nome do proprietario: ");
            String newName = sc.nextLine();
            System.out.println("Digite o nome do restaurante: ");
            String newName2 = sc.nextLine();
            System.out.println("Digite o email do restaurante: ");
            String newEmail = sc.nextLine();

            System.out.println("== Insira o Cardápio ==");

            System.out.println("Quantos itens serao adicionados ao cardapio?");
            int qt = sc.nextInt();

            for (int i = 1; i <= qt; i++) {
                sc.nextLine();
                System.out.format("Item[%d] - Nome: ", i);
                String item = sc.nextLine();
                System.out.format("Item[%d] - Preco: ", i);
                double preco = sc.nextDouble();

                menu.put(item, preco);
            }

            Restaurante newRestaurante = new Restaurante(newName, newEmail, newId, newName2, menu);

            restaurantes.add(newRestaurante);

        } else {

            int newId = entregadores.size() + 1;

            System.out.println("== CADASTRO DE ENTREGADOR ==");
            System.out.println("Digite o nome completo: ");
            String newName = sc.nextLine();
            System.out.println("Digite o email: ");
            String newEmail = sc.nextLine();
            System.out.println("Digite o meio de transporte(Carro, Moto, Bicicleta): ");
            String newMeio = sc.nextLine();

            Entregador newEntregador = new Entregador(newName, newEmail, newId, false, newMeio);

            entregadores.add(newEntregador);
        }

    }

    public void ShowCardapio() {
        System.out.println("CARDÁPIO:");

        for (int i = 0; i < restaurantes.size(); i++) {
            Restaurante r = restaurantes.get(i);
            System.out.printf("\nRestaurante[%d]: %s", i + 1, r.nomeRestaurante);

            if (r.cardapio.isEmpty()) {
                System.out.println("  Nenhum item cadastrado.");
            } else {
                int itemIndex = 1;
                for (Map.Entry<String, Double> entry : r.cardapio.entrySet()) {
                    System.out.printf("  Item [%d]: %s = R$ %.2f\n", itemIndex, entry.getKey(), entry.getValue());
                    itemIndex++;
                }
            }
        }
    }

    public void CriarPedido(Scanner sc) {

        System.out.println("\n== FORMULÁRIO PARA REALIZAR PEDIDO ==");

        if (clientes.isEmpty()) {
            System.out.println("Nenhum cliente cadastrado.");
            return;
        }

        if (restaurantes.isEmpty()) {
            System.out.println("Nenhum restaurante cadastrado.");
            return;
        }

        boolean encontrado = false;
        int tt = 3, cc;

        while (!encontrado || tt > 1) {
            System.out.println("Selecione o cliente pelo email:");
            String tempMail = sc.nextLine();

            for (cc = 0; cc < clientes.size(); cc++) {
                if (clientes.get(cc).email.equals(tempMail)) {
                    System.out.println("Cliente encontrado!");
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                System.out.println("Cliente não encontrado!");
                System.out.printf("TENTE NOVAMENTE - %d CHANCES\n", tt);
            }
        }


        ShowCardapio();

        System.out.println("Selecione um Restaurante pelo numero:");
        int res = sc.nextInt();

        // while (true) {
        // System.out.println("Selecione um item do caradapio: ");
        // int x = sc.nextInt();

        // }

        Pedido newPedido = new Pedido(clientes.get(cc), restaurantes.get(res), /* */, /* */);
    }

    public boolean verificarDisponibilidade() {

        for (Entregador e : entregadores) {

            if (e.status == false) {
                return false;
            } else {
                return true;
            }

        }

        return false;

    }

    public void pedidos(int x, Scanner sc) {

        if (x == 1) {
            System.out.println("Qual o ID do pedido?");
            int id = sc.nextInt();

            pedidos.get(id).resumoDoPedido();
        } else {

            System.out.println("LISTA DOS PEDIDOS: ");

            for (int i = 0; i < pedidos.size(); i++) {
                System.out.printf("Pedido %d", i);
                pedidos.get(i).resumoDoPedido();
            }
        }
    }

}

public class Lista3 {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        boolean e = true;
        int escolha;

        SistemaDelivery ss = new SistemaDelivery();

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
                System.out.println("As Escolhas vao de 1 ao 8, por favor digite sua escolha: ");
                escolha = sc.nextInt();
            }

            sc.nextLine();

            switch (escolha) {

                case (1): {
                    ss.Cadastrar(1, sc);
                }
                case (2): {
                    ss.Cadastrar(2, sc);
                }
                case (3): {
                    ss.Cadastrar(3, sc);
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

    public static void clrscr() {
        // Clears Screen in java
        try {
            if (System.getProperty("os.name").contains("Windows"))
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            else
                Runtime.getRuntime().exec("clear");
        } catch (IOException | InterruptedException ex) {
        }
    }
}
