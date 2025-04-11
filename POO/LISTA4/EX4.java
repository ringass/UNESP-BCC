import java.awt.*;
import javax.swing.*;

public class EX4 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Calculadora");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setContentPane(new PainelCalculadora()); 
        frame.pack();
        frame.setLocationRelativeTo(null); 
        frame.setVisible(true);
    }
}

class PainelCalculadora extends JPanel {

    private JTextField campo1, campo2;
    private JLabel igualLabel, resultadoLabel;
    private JButton calcular;
    private JComboBox<String> comboBox;

    public PainelCalculadora() {
        setLayout(new BorderLayout());

        
        JPanel panelCombo = new JPanel();
        panelCombo.setLayout(new BoxLayout(panelCombo, BoxLayout.Y_AXIS));

        comboBox = new JComboBox<>();
        comboBox.addItem("soma");
        comboBox.addItem("subtrai");
        comboBox.addItem("multiplica");
        comboBox.addItem("divide");

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

        
        JPanel bottom = new JPanel(new FlowLayout(FlowLayout.CENTER));
        calcular = new JButton("calcular");
        bottom.add(calcular);

        
        add(painelCampos, BorderLayout.CENTER);
        add(bottom, BorderLayout.SOUTH);
    }
}
