import javax.swing.*;
import java.awt.*;

public class PrimeView extends JPanel
{
    /* gui components on instance */
    public JButton btnGenerate;
    public JTextArea txtOutput;
    public JTextField txtInput;

    public PrimeView()
    {
        /* gui construction */
        this.setLayout(new GridLayout(3, 1));
        this.setSize(500, 500);


        txtInput = new JTextField();
        txtInput.setSize(200, 50);


        btnGenerate = new JButton("Generate");
        btnGenerate.setSize(100, 50);

        txtOutput = new JTextArea();
        txtOutput.setSize(200,200);

        this.add(txtInput);
        this.add(btnGenerate);
        this.add(txtOutput);
    }
}
