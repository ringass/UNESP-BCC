import java.awt.*;
import javax.swing.*;

public class EX2 extends JFrame {

    JTextField campo1, campo2;
    JLabel igualLabel, resultadoLabel;
    JButton soma, subtrai, multiplica, divide;

    public EX2() {
        super("Calculadora");

        setLayout(new BorderLayout());
        
        JPanel painelBotoes = new JPanel();
        painelBotoes.setLayout(new BoxLayout(painelBotoes, BoxLayout.Y_AXIS));

        soma = new JButton("Soma");
        subtrai = new JButton("Subtrai");
        multiplica = new JButton("Multiplica");
        divide = new JButton("Divide");
        
        Dimension maxSize = new Dimension(Integer.MAX_VALUE, soma.getPreferredSize().height);
        soma.setMaximumSize(maxSize);
        subtrai.setMaximumSize(maxSize);
        multiplica.setMaximumSize(maxSize);
        divide.setMaximumSize(maxSize);

        painelBotoes.add(soma);
        painelBotoes.add(subtrai);
        painelBotoes.add(multiplica);
        painelBotoes.add(divide);

        JPanel painelCampos = new JPanel(new FlowLayout());

        campo1 = new JTextField(13);
        campo2 = new JTextField(13);
        igualLabel = new JLabel(" = ");
        resultadoLabel = new JLabel("0");

        painelCampos.add(campo1);
        painelCampos.add(painelBotoes);
        painelCampos.add(campo2);
        painelCampos.add(igualLabel);
        painelCampos.add(resultadoLabel);

        add(painelCampos, BorderLayout.CENTER);

        pack();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new EX2();
    }
}
