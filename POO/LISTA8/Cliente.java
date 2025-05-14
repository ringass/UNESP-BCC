import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.Socket;
import java.io.*;

public class Cliente {

    static final String ADDRESS = "localhost";
    static final int PORT = 1234;
    private static ObjectOutputStream out;
    private static ObjectInputStream in;
    private static String simbol;

      public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            try {
                Socket socket = new Socket(ADDRESS, PORT);
                out = new ObjectOutputStream(socket.getOutputStream());
                in = new ObjectInputStream(socket.getInputStream());

                simbol = (String) in.readObject(); 

                GUI window = new GUI(out, in, simbol);
                window.setVisible(true);

                // Thread para receber atualizações do servidor
                new Thread(() -> {
                    try {
                        while (true) {
                            Object received = in.readObject();
                            
                            if (received instanceof String[][]) {
                                String[][] state = (String[][]) received;
                                
                                if (state.length == 1 && state[0].length == 1) {
                                    // Mensagem de fim de jogo
                                    SwingUtilities.invokeLater(() -> {
                                        window.disableAllButtons();
                                        JOptionPane.showMessageDialog(window, state[0][0]);
                                    });
                                    break;
                                } else {
                                    // Atualização normal do tabuleiro
                                    SwingUtilities.invokeLater(() -> window.Refresh(state));
                                }
                            }
                        }
                    } catch (IOException | ClassNotFoundException e) {
                        e.printStackTrace();
                    }
                }).start();

            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        });
    }
}

class GUI extends JFrame implements ActionListener {

    private final JButton[][] buttons = new JButton[3][3];
    private final ObjectOutputStream out;
    private final ObjectInputStream in;
    private final String simbol;

    public GUI(ObjectOutputStream out, ObjectInputStream in, String simbol) {

        this.out = out;
        this.in = in;
        this.simbol = simbol;

        setTitle("Jogo da Velha - Jogando como " + simbol);
        setSize(600, 500);
        setLayout(new GridLayout(3, 3));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                buttons[i][j] = new JButton("-");
                buttons[i][j].setFont(new Font("Arial", Font.BOLD, 40));
                buttons[i][j].setFocusPainted(false);
                buttons[i][j].addActionListener(this);
                add(buttons[i][j]);
            }
        }

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton) e.getSource();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (buttons[i][j] == button && button.getText().equals("-")) {
                    try {
                        out.writeObject(new int[]{i, j});
                        out.flush();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }
        }
    }

    public void Refresh(String[][] state) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                buttons[i][j].setText(state[i][j]);
            }
        }
    }

    public void disableAllButtons() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                buttons[i][j].setEnabled(false);
            }
        }
    }
}
