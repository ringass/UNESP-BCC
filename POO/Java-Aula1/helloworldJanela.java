import java.awt.*;
import javax.swing.*;


class helloworldJanela extends JFrame {
    public void paint(Graphics g){
        super.paint(g);
        g.drawString("Hello world!", 40, 100);
    }


public static void main(String args[]){
    helloworldJanela hello=new helloworldJanela();
    hello.setSize(155,150);
    hello.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    hello.setVisible(true);
}
}
