import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PrimeController implements ActionListener
{
    private PrimeModel primeModel;
    private PrimeView primeView;

    public PrimeController(PrimeModel primeModel, PrimeView primeView)
    {
       this.primeModel = primeModel;
       this.primeView = primeView;
       this.primeView.btnGenerate.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        this.primeView.txtOutput.setText("");

        int[] primes = this.primeModel.generatePrimes(Integer.parseInt(this.primeView.txtInput.getText()));

        for (int i = 0; i < primes.length; i++)
        {
            if (primes[i] == 0)
                continue;

            this.primeView.txtOutput.append(Integer.toString(primes[i]));
            this.primeView.txtOutput.append("\n");
        }
    }
}


