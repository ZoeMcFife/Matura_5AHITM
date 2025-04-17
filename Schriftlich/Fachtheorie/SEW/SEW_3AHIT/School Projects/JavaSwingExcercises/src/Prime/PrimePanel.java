package Prime;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PrimePanel extends JPanel
{
    PrimePanel()
    {
        this.setSize(500, 500);
        this.setLayout(new GridLayout(2, 2));

        JTextField amountOfPrimeNumbersInput = new JTextField();
        amountOfPrimeNumbersInput.setSize(200, 40);
        this.add(amountOfPrimeNumbersInput);
        JTextArea output = new JTextArea();

        JButton generateButton = new JButton("Generate");
        generateButton.setSize(100, 100);
        generateButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                output.setText("");

                int[] primes = generatePrimes(Integer.parseInt(amountOfPrimeNumbersInput.getText()));

                for (int i = 0; i < primes.length; i++)
                {
                    output.append(Integer.toString(primes[i]));
                    output.append("\n");
                }
            }
        });
        this.add(generateButton);

        this.add(output);
    }

    public int[] generatePrimes(int n)
    {
        int[] primes = new int[n];

        int i = 1, j = 2, k, l;

        while (i <= n)
        {
            l = 1;

            for (k = 2; k <= j - 1; k++)
            {
                if (j % k == 0)
                {
                    l = 0;
                    break;
                }
            }

            if (l == 1)
            {
                primes[i - 1] = j;
                i++;
            }
            j++;
        }


        return primes;
    }
}