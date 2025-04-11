import java.awt.*;
import javax.swing.*;

public class EX1 extends JFrame {

    JTextArea textArea;
    JButton abrir, salvar, salvarComo, fechar;

    public EX1() {
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

        setSize(500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new EX1();
    }
}
