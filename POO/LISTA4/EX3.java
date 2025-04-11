import java.awt.*;
import javax.swing.*;

public class EX3 extends JFrame {

    JTextField campo1, campo2;
    JLabel igualLabel, resultadoLabel;
    JButton calcular;
    JComboBox<String> comboBox;

    public EX3() {
        super("Calculadora");

        setLayout(new BorderLayout());

        JPanel panelCombo = new JPanel();
        panelCombo.setLayout(new BoxLayout(panelCombo, BoxLayout.X_AXIS));

        comboBox = new JComboBox<>();
        comboBox.addItem("Soma");
        comboBox.addItem("Subtrai");
        comboBox.addItem("Multiplica");
        comboBox.addItem("Divide");

        panelCombo.add(comboBox);

        JPanel painelCampos = new JPanel(new FlowLayout());

        campo1 = new JTextField(13);
        campo2 = new JTextField(13);
        igualLabel = new JLabel(" = ");
        resultadoLabel = new JLabel("0");

        painelCampos.add(campo1);
        painelCampos.add(panelCombo);
        painelCampos.add(campo2);
        painelCampos.add(igualLabel);
        painelCampos.add(resultadoLabel);

        JPanel bottom = new JPanel();
        bottom.setLayout(new GridLayout());

        calcular = new JButton("Calcular");

        bottom.add(calcular);

        add(painelCampos, BorderLayout.CENTER);
        add(bottom, BorderLayout.SOUTH);
        pack();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new EX3(); // Corrigido aqui também
    }
}
