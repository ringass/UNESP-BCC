import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Ex4 extends JFrame implements ActionListener, KeyListener, MouseListener {

    JTextArea textArea;
    JButton confirma;
    JPanel painelEsquerdo;

    public Ex4() {
        super("Exemplo com Todos os Listeners");

        setLayout(new BorderLayout());

        painelEsquerdo = new JPanel();
        painelEsquerdo.setLayout(new BoxLayout(painelEsquerdo, BoxLayout.Y_AXIS));

        confirma = new JButton("Confirmar");
        Dimension maxSize = new Dimension(Integer.MAX_VALUE, confirma.getPreferredSize().height);
        confirma.setMaximumSize(maxSize);
        painelEsquerdo.add(confirma);

        textArea = new JTextArea(15, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);

        add(painelEsquerdo, BorderLayout.WEST);
        add(scrollPane, BorderLayout.CENTER);

        confirma.addActionListener(this);
        textArea.addKeyListener(this);
        painelEsquerdo.addMouseListener(this);

        setSize(500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == confirma) {
            System.out.println("ActionListener: Botão 'Confirmar' clicado!");
        }
    }

    public void keyTyped(KeyEvent e) {
    }

    int i = 15;

    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == 27) {
            System.out.println("esc");
        }else{
            System.out.println("qualquer tecla menos esc");
        }
    }

    public void keyReleased(KeyEvent e) {
    }

    public void mouseClicked(MouseEvent e) {
        
        if (e.getClickCount() <= 15) {
            
            i--;
            System.out.println("faltam " +i+ " cliques");
            
        }
    }

    public void mousePressed(MouseEvent e) {
    }

    public void mouseReleased(MouseEvent e) {
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    public static void main(String[] args) {
        new Ex4();
    }
}
