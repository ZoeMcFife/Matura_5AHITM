package Arithmetics;

import javax.swing.*;
import java.awt.*;

public class TrainerView extends JPanel
{
    public JLabel labelProblem;
    public JLabel labelEquals;
    public JTextField textInput;
    public JLabel labelResult;
    public JButton buttonOK;
    public JButton buttonNext;

    TrainerView()
    {
        GridLayout layout = new GridLayout(3,4);
        layout.setHgap(20);
        layout.setVgap(20);

        this.setLayout(layout);

        JLabel padding = new JLabel();
        padding.setSize(50, 50);
        this.add(padding);

        this.labelProblem = new JLabel("Problem");
        this.labelProblem.setSize(200, 50);
        this.add(labelProblem);

        this.labelEquals = new JLabel("=");
        this.labelEquals.setSize(50, 50);
        this.add(labelEquals);

        this.textInput = new JTextField("Your Input");
        this.textInput.setSize(100, 50);
        this.add(textInput);

        padding = new JLabel();
        padding.setSize(50, 50);
        this.add(padding);

        padding = new JLabel();
        padding.setSize(50, 50);
        this.add(padding);

        padding = new JLabel();
        padding.setSize(50, 50);
        this.add(padding);

        this.labelResult = new JLabel("Result");
        this.labelResult.setSize(100, 50);;
        this.add(labelResult);

        padding = new JLabel();
        padding.setSize(50, 50);
        this.add(padding);

        this.buttonOK = new JButton("OK");
        this.buttonOK.setSize(100, 50);
        this.add(buttonOK);

        this.buttonNext = new JButton("Next");
        this.buttonNext.setSize(100, 50);
        this.add(buttonNext);

        padding = new JLabel();
        padding.setSize(50, 50);
        this.add(padding);


    }
}
