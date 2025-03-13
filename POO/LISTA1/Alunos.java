import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Alunos {

    private Nascimento nascimento;
    private Endereco endereco;
    private Info info;

    public Alunos(int dia, int mes, int ano, String rua, String cidade, String estado, String cep, int ra, String rg,
            double cr, String nome, String telefone) {
        this.nascimento = new Nascimento(dia, mes, ano);
        this.endereco = new Endereco(rua, cidade, estado, cep);
        this.info = new Info(ra, rg, cr, nome, telefone);
    }

    public class Nascimento {
        private int dia, mes, ano;

        public Nascimento(int dia, int mes, int ano) {
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        }

        public int getDia() {
            return dia;
        }

        public int getMes() {
            return mes;
        }

        public int getAno() {
            return ano;
        }
    }

    private class Endereco {
        private String rua, cidade, estado, cep;

        public Endereco(String rua, String cidade, String estado, String cep) {
            this.rua = rua;
            this.cidade = cidade;
            this.estado = estado;
            this.cep = cep;
        }

        public String getRua() {
            return rua;
        }

        public String getCidade() {
            return cidade;
        }

        public String getEstado() {
            return estado;
        }

        public String getCep() {
            return cep;
        }
    }

    public class Info {
        private int ra;
        private double cr;
        private String nome, telefone, rg;

        public Info(int ra, String rg, double cr, String nome, String telefone) {
            this.ra = ra;
            this.rg = rg;
            this.cr = cr;
            this.nome = nome;
            this.telefone = telefone;
        }

        public int getRa() {
            return ra;
        }

        public String getNome() {
            return nome;
        }

        public double getCr() {
            return cr;
        }

        public String getRg() {
            return rg;
        }

        public String getTelefone() {
            return telefone;
        }
    }

    public Nascimento getNascimento() {
        return nascimento;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public Info getInfo() {
        return info;
    }

    public void ShowDados() {
        System.out.println("-------------------------");
        System.out.println("Nome: " + info.getNome());
        System.out.println(
                "Data de Nascimento: " + nascimento.getDia() + "/" + nascimento.getMes() + "/" + nascimento.getAno());
        System.out.println("RG: " + info.getRg());
        System.out.println("Endereço: " + endereco.getRua() + ", " + endereco.getCidade() + ", " + endereco.getEstado()
                + ", CEP: " + endereco.getCep());
        System.out.println("Telefone: " + info.getTelefone());
        System.out.println("RA: " + info.getRa());
        System.out.println("CR: " + info.getCr());
        System.out.println("-------------------------");
    }
}

class Cadastro {
    private Alunos[] alunos;
    private int qt;

    public Cadastro(int qt) {
        alunos = new Alunos[qt];
        this.qt = 0;
    }

    public void Inserir(Alunos a) {
        if (qt < alunos.length) {
            alunos[qt] = a;
            qt++;
            System.out.println("Cadastro efetuado.");
        } else {
            System.out.println("Vaga indisponível por superlotação.");
        }
    }

    public void BuscaRa(int ra) {
        boolean encontrado = false;
        for (int i = 0; i < qt; i++) {
            if (alunos[i].getInfo().getRa() == ra) {
                alunos[i].ShowDados();
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            System.out.println("Não há aluno com o RA: " + ra);
        }
    }

    private void ShowAll() {
        for (int i = 0; i < qt; i++) {
            alunos[i].ShowDados();
        }
    }

    public void ShowByName() {
        Arrays.sort(alunos, 0, qt, Comparator.comparing(b -> b.getInfo().getNome()));
        ShowAll();
    }

    public void ShowByRa() {
        Arrays.sort(alunos, 0, qt, Comparator.comparingInt(b -> b.getInfo().getRa()));
        ShowAll();
    }

    public void ShowByCr() {
        Arrays.sort(alunos, 0, qt, Comparator.comparingDouble(b -> -b.getInfo().getCr()));
        ShowAll();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Cadastro cad = new Cadastro(100);

        while (true) {
            System.out.println("Exercicio 5");
            System.out.println("[1] - Cadastrar aluno");
            System.out.println("[2] - Buscar por RA");
            System.out.println("[3] - Imprimir aluno por ordem de RA");
            System.out.println("[4] - Imprimir aluno por ordem de CR");
            System.out.println("[5] - Imprimir aluno por ordem de nome");
            System.out.println("[0] - Sair");

            int esc = sc.nextInt();
            sc.nextLine();

            switch (esc) {
                case 1: {
                    System.out.print("Nome: ");
                    String nome = sc.nextLine();
                    System.out.print("Dia de Nascimento: ");
                    int dia = sc.nextInt();
                    System.out.print("Mês de Nascimento: ");
                    int mes = sc.nextInt();
                    System.out.print("Ano de Nascimento: ");
                    int ano = sc.nextInt();
                    sc.nextLine();
                    System.out.print("RG: ");
                    String rg = sc.nextLine();
                    System.out.print("Rua: ");
                    String rua = sc.nextLine();
                    System.out.print("Cidade: ");
                    String cidade = sc.nextLine();
                    System.out.print("Estado: ");
                    String estado = sc.nextLine();
                    System.out.print("CEP: ");
                    String cep = sc.nextLine();
                    System.out.print("Telefone: ");
                    String telefone = sc.nextLine();
                    System.out.print("RA: ");
                    int ra = sc.nextInt();
                    System.out.print("CR: ");
                    double cr = sc.nextDouble();
                    sc.nextLine();

                    Alunos aluno = new Alunos(dia, mes, ano, rua, cidade, estado, cep, ra, rg, cr, nome, telefone);

                    cad.Inserir(aluno);
                    break;
                }

                case 2: {

                    System.out.println("Digite o RA do aluno que deseja procurar: ");
                    int ra = sc.nextInt();

                    cad.BuscaRa(ra);
                }
                case 3: {
                    System.out.println("LISTA ORDENADA POR RA\n");
                    cad.ShowByRa();
                    break;
                }
                case 4: {
                    System.out.println("LISTA ORDENADA POR CR\n");
                    cad.ShowByCr();
                    break;
                }
                case 5: {
                    System.out.println("LISTA ORDENADA POR NOME\n");
                    cad.ShowByName();
                    break;
                }
                case 0: {
                    System.out.println("Saindo...");
                    sc.close();
                    return;
                }
                default:
                    System.out.println("Opção inválida.");
            }
        }
    }
}