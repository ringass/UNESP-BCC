import java.awt.Color;

import javax.swing.*;

public class BotaoPula extends JFrame {
    JButton b = new JButton("BATE E REBATE");

    BotaoPula() {
        super("Botão");
        setLayout(null);

        b.setSize(135, 30);
        b.setLocation(0, 0);
        b.setBackground(Color.GREEN);
        b.setForeground(Color.BLACK);
        b.setOpaque(true);
        add(b);

        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        int x = 0;
        int y = 0;
        int vx = 6;
        int vy = 6;

        while (true) {
            try {
                x += vx;
                y += vy;

                if (x + b.getWidth() >= getContentPane().getWidth() || x < 0) {
                    vx = -vx;
                }
                if (y + b.getHeight() >= getContentPane().getHeight() || y < 0) {
                    vy = -vy;
                }

                b.setLocation(x, y);

                Thread.sleep(50);
            } catch (Exception e) {}
        }
    }

    public static void main(String[] args) {
        new BotaoPula();
    }
}
