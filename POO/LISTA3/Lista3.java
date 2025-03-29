
import java.io.IOException;
import java.util.*;

class Clear {
    public static void clrscr() {
        // limpa
        try {
            if (System.getProperty("os.name").contains("Windows"))
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            else
                Runtime.getRuntime().exec("clear");
        } catch (IOException | InterruptedException ex) {
        }
    }
}

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

    Pedido(Cliente cliente, Restaurante restaurante, Map<String, Double> itens, double valor) {
        this.cliente = cliente;
        this.restaurante = restaurante;
        this.itens = itens;
        this.valor = valor;
    }

    public enum Status {
        REALIZADO("Realizado"),
        EM_PREPARO("Em preparo"),
        ENTREGUE("Entregue");

        private String descricao;

        Status(String descricao) {
            this.descricao = descricao;
        }

        @Override
        public String toString() {
            return descricao;
        }
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

        System.out.println("Itens do Pedido:");
        for (Map.Entry<String, Double> entry : itens.entrySet()) {
            System.out.printf("- %s: R$ %.2f\n", entry.getKey(), entry.getValue());
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
            System.out.printf("Digite o nome completo: ");
            String newName = sc.nextLine();
            System.out.printf("Digite o email: ");
            String newEmail = sc.nextLine();

            int newId = clientes.size() + 1;

            Cliente newCliente = new Cliente(newName, newEmail, newId);

            clientes.add(newCliente);

        } else if (x == 2) {
            Map<String, Double> menu = new HashMap<>();

            int newId = restaurantes.size() + 1;

            System.out.println("== CADASTRO DE RESTAURANTE ==");
            System.out.printf("Digite o nome do proprietario: ");
            String newName = sc.nextLine();
            System.out.printf("Digite o nome do restaurante: ");
            String newName2 = sc.nextLine();
            System.out.printf("Digite o email do restaurante: ");
            String newEmail = sc.nextLine();

            System.out.println("== Insira o Cardapio ==");

            System.out.printf("Quantos itens serao adicionados ao cardapio?: ");
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
            System.out.printf("Digite o nome completo: ");
            String newName = sc.nextLine();
            System.out.printf("Digite o email: ");
            String newEmail = sc.nextLine();
            System.out.printf("Digite o meio de transporte(Carro, Moto, Bicicleta): ");
            String newMeio = sc.nextLine();

            Entregador newEntregador = new Entregador(newName, newEmail, newId, false, newMeio);

            entregadores.add(newEntregador);
        }

        Clear.clrscr();
    }

    public void ShowRestaurantes(int p) {
        if (p == 0) {
            System.out.println("LISTA DE RESTAURANTES");

            for (int i = 0; i < restaurantes.size(); i++) {
                Restaurante r = restaurantes.get(i);
                System.out.printf("\nRestaurante[%d]: %s\n\n", i + 1, r.nomeRestaurante);

                if (r.cardapio.isEmpty()) {
                    System.out.println("Nenhum item cadastrado.\n");
                } else {
                    int itemIndex = 1;
                    for (Map.Entry<String, Double> entry : r.cardapio.entrySet()) {
                        System.out.printf("  Item [%d]: %s = R$ %.2f\n", itemIndex, entry.getKey(), entry.getValue());
                        itemIndex++;
                    }
                }
            }
        } else {

            System.out.println("CARDAPIO");

            if (restaurantes.get(p - 1).cardapio.isEmpty()) {
                System.out.println("Nenhum item cadastrado.");
            } else {
                int itemIndex = 1;
                for (Map.Entry<String, Double> entry : restaurantes.get(p - 1).cardapio.entrySet()) {
                    System.out.printf("Item [%d]: %s = R$ %.2f\n", itemIndex, entry.getKey(), entry.getValue());
                    itemIndex++;
                }
            }
        }

    }

    public void CriarPedido(Scanner sc) {
        System.out.println("\n== FORMULARIO PARA REALIZAR PEDIDO ==");

        if (clientes.isEmpty()) {
            System.out.println("Nenhum cliente cadastrado.\n");
            return;
        }

        if (restaurantes.isEmpty()) {
            System.out.println("Nenhum restaurante cadastrado.\n");
            return;
        }

        // Seleção do Cliente
        Cliente clienteSelecionado = null;
        while (clienteSelecionado == null) {
            System.out.println("Digite o e-mail do cliente:");
            String emailCliente = sc.nextLine();
            for (Cliente c : clientes) {
                if (c.email.equals(emailCliente)) {
                    clienteSelecionado = c;
                    break;
                }
            }
            if (clienteSelecionado == null) {
                System.out.println("Cliente nao encontrado. Tente novamente.");
            }

        }

        // Seleção do Restaurante
        ShowRestaurantes(0);
        System.out.println("\nDigite o numero do restaurante:");
        int numRestaurante = sc.nextInt();
        sc.nextLine();

        if (numRestaurante < 1 || numRestaurante > restaurantes.size()) {
            System.out.println("Restaurante invalido.");
            return;
        }

        Clear.clrscr();
        Restaurante restauranteSelecionado = restaurantes.get(numRestaurante - 1);
        ShowRestaurantes(numRestaurante);

        Map<String, Double> itensSelecionados = new HashMap<>();
        double valorTotal = 0;
        boolean continuarPedido = true;

        while (continuarPedido) {
            System.out.println("Digite o numero do item do cardapio para adicionar ao pedido:");
            int numItem = sc.nextInt();
            sc.nextLine();

            List<String> listaItens = new ArrayList<>(restauranteSelecionado.cardapio.keySet());
            if (numItem < 1 || numItem > listaItens.size()) {
                System.out.println("Item invalido.");
                continue;
            }

            String itemSelecionado = listaItens.get(numItem - 1);
            double precoItem = restauranteSelecionado.cardapio.get(itemSelecionado);
            itensSelecionados.put(itemSelecionado, precoItem);
            valorTotal += precoItem;

            System.out.println("Deseja adicionar mais itens? (s/n)");
            String resposta = sc.nextLine();
            if (resposta.equalsIgnoreCase("n")) {
                continuarPedido = false;
            }
        }

        Entregador teste = verificarDisponibilidade();

        if (teste.status == false || teste == null) {
            System.out.println("Nenhum entregador disponivel no momento. O pedido sera criado sem entregador.");
        }

        Pedido novoPedido = new Pedido(clienteSelecionado, restauranteSelecionado, itensSelecionados, valorTotal);

        if (teste != null) {
            novoPedido.atribuirEntregador(teste);
        }

        pedidos.add(novoPedido);

        Clear.clrscr();
        System.out.println("Pedido criado com sucesso!");
        novoPedido.resumoDoPedido();

    }

    public Entregador verificarDisponibilidade() {
        for (Entregador e : entregadores) {
            if (!e.status)
                e.status = true;
            return e;
        }
        return null;
    }

    public void atribuirPedido() {
        for (Pedido p : pedidos) {
            if (p.entregador == null) {
                Entregador entregadorDisponivel = verificarDisponibilidade();
                if (entregadorDisponivel != null) {
                    p.atribuirEntregador(entregadorDisponivel);
                }
            }
        }
    }

    public void Listarpedidos(int x, Scanner sc) {

        Clear.clrscr();
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

    public void AtualizarPedido(Scanner sc) {
        System.out.println("Qual o ID do pedido?");
        int id = sc.nextInt();

        if (id < 0 || id >= pedidos.size()) {
            System.out.println("ID de pedido invalido.");
            return;
        }

        sc.nextLine();

        Pedido pedidoSelecionado = pedidos.get(id);

        System.out.println("Deseja atualizar o status para qual estado?");
        System.out.println("Opções de estados = [REALIZADO, EM_PREPARO, ENTREGUE]: ");
        String res = sc.nextLine().toUpperCase();

        try {

            Pedido.Status novoStatus = Pedido.Status.valueOf(res);

            pedidoSelecionado.atualizarStatus(novoStatus);

            System.out.println("Status do pedido atualizado para: " + novoStatus);
        } catch (IllegalArgumentException e) {
            System.out.println("Status nao reconhecido. Use uma das opçoes validas.");
        }
    }

    public boolean verifyAll() {
        if (entregadores.isEmpty() || restaurantes.isEmpty() || clientes.isEmpty()) {
            System.out.println("Erro por falta de informacoes (Restaurantes, Pessoas ou pedidos)");
            System.out.println(
                    "Certifique-se que existe ao menos um cliente, um restaurante e um entregador cadastrados, ou pedidos, no sistema");
            try {

                Thread.sleep(6000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
            Clear.clrscr();
            return false;
        }
        Clear.clrscr();
        return true;
    }

    public boolean verifyPedido() {
        if (pedidos.isEmpty()) {
            System.out.println("ERROR: FALTA DE PEDIDOS");

            try {

                Thread.sleep(6000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

            Clear.clrscr();
            return false;

        }
        Clear.clrscr();
        return true;
    }

    public boolean verifyEntregador() {
        if (entregadores.isEmpty()) {
            System.out.println("ERROR: FALTA DE ENTREGADORES");
            return false;
        }
        return true;
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

            Clear.clrscr();
            switch (escolha) {

                case (1): { // cadastrar cliente
                    ss.Cadastrar(1, sc);
                    break;
                }
                case (2): { // cadastrar restaurante
                    ss.Cadastrar(2, sc);
                    break;
                }
                case (3): { // cadastrar entregador
                    ss.Cadastrar(3, sc);
                    break;
                }
                case (4): { // criar pedido

                    if (!ss.verifyAll()) {
                        break;
                    }
                    ss.CriarPedido(sc);
                    break;
                }
                case (5): {// atribuir pedido a entregador
                    if (!ss.verifyPedido()) {
                        break;
                    } else if (!ss.verifyEntregador()) {
                        break;
                    }
                    ss.atribuirPedido();
                    break;
                }
                case (6): {// atualizar status do pedido
                    if (!ss.verifyPedido()) {
                        break;
                    }
                    ss.AtualizarPedido(sc);
                    break;
                }
                case (7): {// listar pedidos
                    if (!ss.verifyPedido()) {
                        break;
                    }
                    System.out.println("\nDigite [1] para listar apenas um e [2] para listar todos");
                    ss.Listarpedidos(escolha, sc);
                    break;
                }
                case (8): {
                    Clear.clrscr();
                    System.out.println("SESSAO FINALIZADA!!");
                    e = false;
                }

            }
        }

        sc.close();
    }

}
