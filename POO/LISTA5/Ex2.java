import java.awt.event.*;
import java.util.ArrayList;
import java.awt.*;
import javax.swing.*;

public class Ex2 extends JFrame implements ActionListener {

    JTextField campo1, campo2;
    JLabel igualLabel, resultadoLabel;
    JButton soma, subtrai, multiplica, divide;

    public Ex2() {
        super("Ex2uladora");

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
        resultadoLabel = new JLabel("0 ");

        painelCampos.add(campo1);
        painelCampos.add(painelBotoes);
        painelCampos.add(campo2);
        painelCampos.add(igualLabel);
        painelCampos.add(resultadoLabel);

        add(painelCampos, BorderLayout.CENTER);

        soma.addActionListener(this);
        multiplica.addActionListener(this);
        subtrai.addActionListener(this);
        divide.addActionListener(this);

        pack();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent evt) {
        Double v1, v2, ans = 0.0;
        v1 = Double.parseDouble(campo1.getText());
        v2 = Double.parseDouble(campo2.getText());

        if (evt.getSource() == soma) {
            ans = v1 + v2;
        } else if (evt.getSource() == multiplica) {
            ans = v1 * v2;
        } else if (evt.getSource() == subtrai) {
            ans = v1 - v2;
        } else if (evt.getSource() == divide) {
            ans = v1 / v2;
        }

        resultadoLabel.setText(Double.toString(ans));
    }

    public static void main(String[] args) {
        new Ex2();
    }
}
