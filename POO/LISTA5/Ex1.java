import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;

public class Ex1 extends JFrame implements ActionListener {

    JTextArea textArea;
    JButton abrir, salvar, salvarComo, fechar;

    public Ex1() {
        super("Editor de Texto");

        setLayout(new BorderLayout());

        JPanel painelEsquerdo = new JPanel();
        painelEsquerdo.setLayout(new BoxLayout(painelEsquerdo, BoxLayout.Y_AXIS));

        abrir = new JButton("Abrir");
        salvar = new JButton("Salvar");
        salvarComo = new JButton("Salvar Como");
        fechar = new JButton("Fechar");

        Dimension maxSize = new Dimension(Integer.MAX_VALUE, abrir.getPreferredSize().height);
        abrir.setMaximumSize(maxSize);
        salvar.setMaximumSize(maxSize);
        salvarComo.setMaximumSize(maxSize);
        fechar.setMaximumSize(maxSize);

        painelEsquerdo.add(abrir);
        painelEsquerdo.add(salvar);
        painelEsquerdo.add(salvarComo);
        painelEsquerdo.add(fechar);

        textArea = new JTextArea(15, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);

        add(painelEsquerdo, BorderLayout.WEST);
        add(scrollPane, BorderLayout.CENTER);

        abrir.addActionListener(this);
        salvar.addActionListener(this);
        salvarComo.addActionListener(this);
        fechar.addActionListener(this);

        setSize(500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    String nomeArq = null;

    public void actionPerformed(ActionEvent evt) {
    
        if (evt.getSource() == abrir) {

            textArea.setText("");
            try {
                nomeArq = JOptionPane.showInputDialog("Digite o nome do arquivo: ");

                FileInputStream in = new FileInputStream(nomeArq);
                Scanner sc = new Scanner(in);

                while (sc.hasNextLine()) {
                    textArea.append(sc.nextLine());
                    textArea.append("\n");
                }

                in.close();
                sc.close();
            } catch (Exception e) {
                System.out.println("Nenhum arquivo com esse nome");
            }

        } else if (evt.getSource() == salvar) {

            try {

                FileOutputStream out = new FileOutputStream(nomeArq);
                out.write(textArea.getText().getBytes());
                out.close();

            } catch (Exception e) {

                System.out.println("Nenhum arquivo aberto");

            }

        } else if (evt.getSource() == salvarComo) {

            nomeArq = JOptionPane.showInputDialog("Digite o nome do arquivo: ");

            try {

                FileOutputStream out = new FileOutputStream(nomeArq);
                out.write(textArea.getText().getBytes());
                out.close();

            } catch (Exception e) {

                JOptionPane.showMessageDialog(this, "Erro ao salvar o arquivo.");

            }
        } else {
            System.exit(1);
        }

       
    }

    public static void main(String[] args) {
        new Ex1();
    }
}
