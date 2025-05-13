package Prime;

import javax.swing.*;

public class Main
{
    public static void main(String[] args)
    {
        JFrame frame = new JFrame("Primes");
        frame.add(new PrimePanel());
        frame.setSize(500,500);
        frame.setVisible(true);
    }
}
