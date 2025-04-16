import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class Ex3 extends JFrame implements ActionListener {

    JTextField campo1, campo2;
    JLabel igualLabel, resultadoLabel;
    JButton calcular;
    JComboBox<String> comboBox;

    public Ex3() {
        super("Calculadora");

        setLayout(new BorderLayout());
        setLocationRelativeTo(null);

        JPanel panelCombo = new JPanel();
        panelCombo.setLayout(new BoxLayout(panelCombo, BoxLayout.X_AXIS));

        comboBox = new JComboBox<>();
        comboBox.addItem("Soma");
        comboBox.addItem("Subtrai");
        comboBox.addItem("Multiplica");
        comboBox.addItem("Divide");

        comboBox.addActionListener(this);

        panelCombo.add(comboBox);

        JPanel painelCampos = new JPanel(new FlowLayout());

        campo1 = new JTextField(13);
        campo2 = new JTextField(13);
        igualLabel = new JLabel(" = ");
        resultadoLabel = new JLabel("    0");

        painelCampos.add(campo1);
        painelCampos.add(panelCombo);
        painelCampos.add(campo2);
        painelCampos.add(igualLabel);
        painelCampos.add(resultadoLabel);

        
        JPanel bottom = new JPanel();
        bottom.setLayout(new GridLayout());

        calcular = new JButton("Calcular");

        bottom.add(calcular);
        calcular.addActionListener(this);
        campo1.addActionListener(this);
        campo2.addActionListener(this);
        add(painelCampos, BorderLayout.CENTER);
        add(bottom, BorderLayout.SOUTH);
        pack();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent evt) {
        Double v1, v2, ans = 0.0;
        v1 = Double.parseDouble(campo1.getText());
        v2 = Double.parseDouble(campo2.getText());

        if (evt.getSource() == calcular && comboBox.getSelectedItem() == "Soma") {
            ans = v1 + v2;
        } else if (evt.getSource() == calcular && comboBox.getSelectedItem() == "Multiplica") {
            ans = v1 * v2;
        } else if (evt.getSource() == calcular && comboBox.getSelectedItem() == "Subtrai") {
            ans = v1 - v2;
        } else if (evt.getSource() == calcular && comboBox.getSelectedItem() == "Divide" ) {
            ans = v1 / v2;
        }

        resultadoLabel.setText(Double.toString(ans));
    }

    public static void main(String[] args) {
        new Ex3(); // Corrigido aqui também
    }
}
