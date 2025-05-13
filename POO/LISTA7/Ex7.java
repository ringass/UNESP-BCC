import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.util.Random;

public class Ex7 extends JFrame {
    private final JTextField campo1 = new JTextField("0", 3);
    private final JTextField campo2 = new JTextField("0", 3);
    private final JTextField campo3 = new JTextField("0", 3);
    private final JButton btn = new JButton("Jogar");

    public Ex7() {
        setTitle("Caca-niquel");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(900, 250);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        Dimension campoSize = new Dimension(100, 100); 
        Font fonte = new Font("Arial", Font.BOLD, 36); 

        JTextField[] campos = {campo1, campo2, campo3};
        for (JTextField campo : campos) {
            campo.setPreferredSize(campoSize);
            campo.setFont(fonte);
            campo.setHorizontalAlignment(JTextField.CENTER);
            campo.setEditable(false);
            campo.setFocusable(false); 
        }

        JPanel painelCampos = new JPanel();
        painelCampos.add(campo1);
        painelCampos.add(campo2);
        painelCampos.add(campo3);
        
        campoSize = new Dimension(100, 40);
        fonte = new Font("Arial",Font.PLAIN ,20);

        btn.setFont(fonte);
        btn.setPreferredSize(campoSize);
        JPanel painelBotao = new JPanel();
        painelBotao.add(btn);

        add(painelCampos, BorderLayout.CENTER);
        add(painelBotao, BorderLayout.SOUTH);

        btn.addActionListener(this::jogar);

        setVisible(true);
    }

    private void jogar(ActionEvent e) {
        btn.setEnabled(false);

        SlotThread t1 = new SlotThread(campo1);
        SlotThread t2 = new SlotThread(campo2);
        SlotThread t3 = new SlotThread(campo3);

        t1.start();
        t2.start();
        t3.start();

        new Thread(() -> {
            try {
                t1.join();
                t2.join();
                t3.join();

                SwingUtilities.invokeLater(() -> {
                    int v1 = Integer.parseInt(campo1.getText());
                    int v2 = Integer.parseInt(campo2.getText());
                    int v3 = Integer.parseInt(campo3.getText());

                    if (v1 == v2 && v2 == v3) {
                        JOptionPane.showMessageDialog(this, "Voce venceu!");
                    } else {
                        JOptionPane.showMessageDialog(this, "Voce perdeu!");
                    }

                    btn.setEnabled(true);
                });

            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }).start();
    }

    private static class SlotThread extends Thread {
        private final JTextField campo;
        private final Random random = new Random();

        public SlotThread(JTextField campo) {
            this.campo = campo;
        }

        @Override
        public void run() {
            int times= 1 + random.nextInt(150);

            for (int i = 0; i < times; i++) {
                int valor = 1 + random.nextInt(7);
                SwingUtilities.invokeLater(() -> campo.setText(String.valueOf(valor)));
                try {
                    Thread.sleep(50); 
                } catch (InterruptedException ignored) {}
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Ex7::new);
    }
}
