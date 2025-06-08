//Murilo Tomaz Gonzaga - BCC 024

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Servidor {

    private static final int PORT = 1234;
    private static final String[][] tabuleiro = {
            { "-", "-", "-" },
            { "-", "-", "-" },
            { "-", "-", "-" }
    };

    private static ObjectOutputStream Out2;
    private static ObjectOutputStream Out1;
    private static boolean P1Time = true;

    public static void main(String[] args) {

        try (ServerSocket sv = new ServerSocket(PORT)) {

            System.out.println("Esperando jogadores:");

            Socket Player1 = sv.accept();
            System.out.println("Player 1 conectado: X");
            Out1 = new ObjectOutputStream(Player1.getOutputStream());
            ObjectInputStream InPlayer1 = new ObjectInputStream(Player1.getInputStream());
            Out1.writeObject("X");

            Socket Player2 = sv.accept();
            System.out.println("Player 2 conectado: O");
            Out2 = new ObjectOutputStream(Player2.getOutputStream());
            ObjectInputStream InPlayer2 = new ObjectInputStream(Player2.getInputStream());
            Out2.writeObject("O");

            Envia();

            new Thread(() -> Servindo(InPlayer1, "X")).start();
            new Thread(() -> Servindo(InPlayer2, "O")).start();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void Servindo(ObjectInputStream in, String simbolo) {
        try {
            while (true) {
                int[] jogada = (int[]) in.readObject();
                int l = jogada[0];
                int c = jogada[1];

                synchronized (tabuleiro)  {
                    if (tabuleiro[l][c].equals("-") &&
                            ((simbolo.equals("X") && P1Time) || (simbolo.equals("O") && !P1Time))) {

                        tabuleiro[l][c] = simbolo;

                        System.out.println("" + tabuleiro[l][c]);

                        P1Time = !P1Time;

                        Envia();

                        if (Win(simbolo)) {
                            String msgVitoria = "Voce venceu!";
                            String msgDerrota = "Voce perdeu!";

                            Out1.writeObject(simbolo.equals("X") ? new String[][] { { msgVitoria } }
                                    : new String[][] { { msgDerrota } });
                            Out2.writeObject(simbolo.equals("O") ? new String[][] { { msgVitoria } }
                                    : new String[][] { { msgDerrota } });
                            Out1.flush();
                            Out2.flush();
                            break;
                        } else if (verificarEmpate()) {
                            Out1.writeObject(new String[][] { { "Empate!" } });
                            Out2.writeObject(new String[][] { { "Empate!" } });
                            Out1.flush();
                            Out2.flush();
                            break;
                        }
                    }
                }
            }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static void Envia() throws IOException {
        Out1.reset();
        Out1.writeObject(tabuleiro);
        Out1.flush();

        Out2.reset();
        Out2.writeObject(tabuleiro);
        Out2.flush();

    }

    private static boolean Win(String simbolo) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[i][0].equals(simbolo) && tabuleiro[i][1].equals(simbolo) && tabuleiro[i][2].equals(simbolo))
                return true;
            if (tabuleiro[0][i].equals(simbolo) && tabuleiro[1][i].equals(simbolo) && tabuleiro[2][i].equals(simbolo))
                return true;
        }
        return (tabuleiro[0][0].equals(simbolo) && tabuleiro[1][1].equals(simbolo) && tabuleiro[2][2].equals(simbolo))
                ||
                (tabuleiro[0][2].equals(simbolo) && tabuleiro[1][1].equals(simbolo) && tabuleiro[2][0].equals(simbolo));
    }

    private static boolean verificarEmpate() {
        for (String[] linha : tabuleiro) {
            for (String cell : linha) {
                if (cell.equals("-")) {
                    return false;
                }
            }
        }
        return true;
    }
}