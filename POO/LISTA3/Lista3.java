import java.io.*;
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

    public static void waitkk() {
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        Clear.clrscr();
        return;
    }
}

class Input {

    public static double DoubleReceive(String mensagem, Scanner sc) {
        double valor = 0.0;
        boolean valido = false;

        while (!valido) {
            System.out.print(mensagem);
            String entrada = sc.nextLine();

            try {
                valor = Double.parseDouble(entrada);
                valido = true;
            } catch (NumberFormatException e) {
                System.out.println("Entrada invalida. Digite um numero com ponto decimal (ex: 10.5).");
            }
        }

        return valor;
    }

    public static int IntReceive(String mensagem, Scanner sc) {
        int valor = 0;
        boolean valido = false;

        while (!valido) {
            System.out.print(mensagem);
            String entrada = sc.nextLine();

            try {
                valor = Integer.parseInt(entrada);
                valido = true;
            } catch (NumberFormatException e) {
                System.out.println("Entrada invalida. Digite um numero inteiro.");
            }
        }
        return valor;

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

class Item {
    String nome;
    Double preco;
    int quantidade;

    Item(String nome, Double preco, int quantidade) {
        this.nome = nome;
        this.preco = preco;
        this.quantidade = quantidade;
    }

    public double getTotal() {
        return preco * quantidade;
    }

    @Override
    public String toString() {
        return String.format("- %s: R$ %.2f - Unidades[%d]", nome, preco, quantidade);
    }
}

class Pedido {

    Cliente cliente;
    Restaurante restaurante;
    Entregador entregador;
    public double valor;
    List<Item> itens; // classe para itens ou vector de map;

    int id;

    Pedido(Cliente cliente, Restaurante restaurante, List<Item> itens, double valor, int id) {
        this.cliente = cliente;
        this.restaurante = restaurante;
        this.itens = itens;
        this.valor = valor;
        this.id = id;
    }

    public enum Status {
        REALIZADO("Realizado"),
        EM_PREPARO("Em preparo"),
        ENTREGUE("Entregue");

        private String descricao;

        public String getDescricao() {
            return descricao;
        }

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
        System.out.printf("Nome: %s\n" +
                "Restaurante: %s\n", cliente.nome, restaurante.nomeRestaurante);

        System.out.printf("Itens do Pedido[%d]:\n", id);

        for (Item i : itens) {
            System.out.println("" + i);
        }

        System.out.printf("Valor do Pedido: R$ %.2f\n", valor);
        System.out.println("Entregador: " + entregador.nome);
        System.out.println("Status: " + status);
        System.out.println("\n");
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

            int qt = Input.IntReceive("Quantos itens serao adicionados ao cardapio?: ", sc);

            for (int i = 1; i <= qt; i++) {
                System.out.format("Item[%d] - Nome: ", i);
                String item = sc.nextLine();
                double preco = Input.DoubleReceive(String.format("Item[%d] - Preco: ", i), sc);

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
                        System.out.printf("  Item [%d]: %s = R$ %.2f\n", itemIndex, entry.getKey(),
                                entry.getValue());
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
                if (c.email.equalsIgnoreCase(emailCliente)) {
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
        int numRestaurante = Input.IntReceive("\nDigite o numero do restaurante: ", sc);

        if (numRestaurante < 1 || numRestaurante > restaurantes.size()) {
            System.out.println("Restaurante invalido.");
            Clear.clrscr();
            return;
        }

        Clear.clrscr();
        Restaurante restauranteSelecionado = restaurantes.get(numRestaurante - 1);
        ShowRestaurantes(numRestaurante);

        // Map<String, Double> itensSelecionados = new HashMap<>();

        List<Item> itensSelecionados = new ArrayList<>();
        double valorTotal = 0;
        boolean continuarPedido = true;

        while (continuarPedido) {
            System.out.println();
            int numItem = Input.IntReceive("Digite o numero do item do cardapio para adicionar ao pedido:\n", sc);

            List<String> listaItens = new ArrayList<>(restauranteSelecionado.cardapio.keySet());
            if (numItem < 1 || numItem > listaItens.size()) {
                System.out.println("Item invalido.");
                continue;
            }

            String itemSelecionado = listaItens.get(numItem - 1);
            double precoItem = restauranteSelecionado.cardapio.get(itemSelecionado);

            int quantidade = Input.IntReceive(
                    String.format("Quantas unidades de " + itemSelecionado + " voce deseja?\n"),
                    sc);

            boolean itemExistente = false;
            for (Item item : itensSelecionados) {
                if (item.nome.equals(itemSelecionado)) {
                    item.quantidade += quantidade;
                    valorTotal += precoItem * quantidade;
                    itemExistente = true;
                    break;
                }
            }

            if (!itemExistente) {
                Item novoItem = new Item(itemSelecionado, precoItem, quantidade);
                itensSelecionados.add(novoItem);
                valorTotal += novoItem.getTotal();
            }

            System.out.println("Deseja adicionar mais itens? (s/n)");
            String resposta = sc.nextLine();
            if (resposta.equalsIgnoreCase("n")) {
                continuarPedido = false;
            }
        }

        Entregador teste = verificarDisponibilidade();

        int id = pedidos.size() + 1;

        Pedido novoPedido = new Pedido(clienteSelecionado, restauranteSelecionado, itensSelecionados, valorTotal,
                id);

        if (teste == null || teste.status == false) {
            System.out.println("Nenhum entregador disponivel no momento. O pedido sera criado sem entregador.");
            novoPedido.atribuirEntregador(null);
        } else {
            novoPedido.atribuirEntregador(teste);
        }

        pedidos.add(novoPedido);

        Clear.clrscr();
        System.out.println("Pedido criado com sucesso!");
        novoPedido.resumoDoPedido();

    }

    public Entregador verificarDisponibilidade() {
        for (Entregador e : entregadores) {
            if (!e.status) {
                e.status = true;
                return e;
            }
        }
        return null;
    }

    public void atribuirPedido() {
        for (Pedido p : pedidos) {
            if (p.entregador == null) {
                Entregador entregadorDisponivel = verificarDisponibilidade();
                if (entregadorDisponivel != null) {
                    p.atribuirEntregador(entregadorDisponivel);
                    System.out.printf("Entregador %s atribuido ao pedido do cliente %s\n",
                            entregadorDisponivel.nome,
                            p.cliente);
                    Clear.waitkk();
                    return;
                }
            }
        }

        System.out.println("Todos os pedidos com entregadores");
        Clear.waitkk();
    }

    public void Listarpedidos(int x, Scanner sc) {

        int p;

        Clear.clrscr();
        if (x == 1) {
            int id = Input.IntReceive("Qual o ID do pedido?\n", sc);

            pedidos.get(id - 1).resumoDoPedido();

            p = Input.IntReceive("DIGITE PARA CONTINUAR (1): ", sc);

        } else {

            System.out.println("LISTA DOS PEDIDOS: ");

            for (int i = 0; i < pedidos.size(); i++) {
                System.out.printf("Pedido %d\n", i + 1);
                pedidos.get(i).resumoDoPedido();
            }

            p = Input.IntReceive("DIGITE PARA CONTINUAR (1): ", sc);
        }

        if (p == 1) {
            return;
        }
    }

    public void AtualizarPedido(Scanner sc) {

        int id = Input.IntReceive("Qual o ID do pedido?\n", sc);

        if (id <= 0 || id > pedidos.size()) {
            System.out.println("ID de pedido invalido.");

            return;
        }

        Pedido pedidoSelecionado = pedidos.get(id - 1);

        System.out.println("Digite seu email para confirmar:");
        String ss = sc.nextLine();

        if (!(ss.equalsIgnoreCase(pedidoSelecionado.cliente.email))) {
            System.out.println("Email incorreto, volte ao menu e tente novamente");

            Clear.waitkk();

            return;
        }

        if (pedidoSelecionado.status.getDescricao().equalsIgnoreCase("Realizado")) {
            System.out.println("Esse pedido ja foi realizado");
            Clear.waitkk();
            return;
        }

        System.out.println("Deseja atualizar o status para qual estado?");
        System.out.println("Opcoes de estados = [REALIZADO, EM_PREPARO, ENTREGUE]: ");
        String res = sc.nextLine().toUpperCase();

        try {

            Pedido.Status novoStatus = Pedido.Status.valueOf(res);

            while (pedidoSelecionado.status.getDescricao().equalsIgnoreCase(novoStatus.getDescricao())) {
                System.out.println("Digite um estado que nao seja o atual do pedido: %d");
                res = sc.nextLine().toUpperCase();

                novoStatus = Pedido.Status.valueOf(res);
            }

            pedidoSelecionado.atualizarStatus(novoStatus);

            System.out.println("Status do pedido atualizado para: " + novoStatus);

            if (res.equalsIgnoreCase("REALIZADO")) {
                pedidos.get(id - 1).entregador.status = true;
                System.out.println("Entregador disponivel: " + pedidos.get(id - 1).entregador.nome);
            }

        } catch (IllegalArgumentException e) {
            System.out.println("Status nao reconhecido. Use uma das opçoes validas.");
        }

        Clear.waitkk();
    }

    public boolean verifyAll() {
        if (entregadores.isEmpty() || restaurantes.isEmpty() || clientes.isEmpty()) {
            System.out.println("Erro por falta de informacoes (Restaurantes, Pessoas ou pedidos)");
            System.out.println(
                    "Certifique-se que existe ao menos um cliente, um restaurante e um entregador cadastrados, ou pedidos, no sistema\n"
                            + //
                            "Aguarde para retornar ao menu");
            Clear.waitkk();
            return false;
        }
        Clear.clrscr();
        return true;
    }

    public boolean verifyPedido() {
        if (pedidos.isEmpty()) {
            System.out.println("ERROR: FALTA DE PEDIDOS\nAguarde para retornar ao menu");

            Clear.waitkk();
            return false;
        }
        Clear.clrscr();
        return true;
    }

    public boolean verifyEntregador() {
        if (entregadores.isEmpty()) {
            System.out.println("ERROR: FALTA DE ENTREGADORES\n" + //
                    "Aguarde para retornar ao menu");
            Clear.waitkk();
            return false;
        }
        Clear.clrscr();
        return true;
    }
}

public class Lista3 {

    public static void main(String args[]) {
        Clear.clrscr();

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

            escolha = Input.IntReceive("Digite sua escolha: ", sc);

            while (escolha < 1 || escolha > 8) {
                escolha = Input.IntReceive("As Escolhas vao de 1 ao 8, por favor digite sua escolha: ", sc);
            }

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
                    if (!ss.verifyEntregador()) {
                        break;
                    } else if (!ss.verifyPedido()) {
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
                    Clear.clrscr();
                    break;
                }
                case (7): {// listar pedidos
                    if (!ss.verifyPedido()) {
                        break;
                    }
                    int zz = Input.IntReceive("\nDigite [1] para listar apenas um e [2] para listar todos\n", sc);
                    ss.Listarpedidos(zz, sc);
                    Clear.clrscr();
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
