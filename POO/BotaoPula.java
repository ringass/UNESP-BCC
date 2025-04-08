import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BotaoPula extends JFrame {
    JButton b = new JButton("Pula");

    BotaoPula() {
        super("Botão Swing");
        setLayout(null);

        b.setSize(70, 50);
        b.setLocation(0, 0);
        add(b);

        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        int x = 0;
        int y = 0;
        int dx = 5;
        int dy = 5;

        while (true) {
            try {
                x += dx;
                y += dy;

                if (x + b.getWidth() >= getWidth() || x  < 0) {
                    dx = -dx;
                }else if (y + b.getHeight() >= getHeight() || y  < 0) {
                    dy = -dy;
                }

                b.setLocation(x, y);

                Thread.sleep(50);
            } catch (Exception e) {

            }
        }
    }

    public static void main(String[] args) {
        new BotaoPula();
    }
}
