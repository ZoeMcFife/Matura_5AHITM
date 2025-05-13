package com.company;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class DemoFrame extends Frame implements ActionListener
{
    Button b1;
    Button b2;
    Button b3;
    TextField tf1;

    public DemoFrame() // Konstruktor
    {
        super("TestFrame"); // Konstruktor von Frame
        addWindowListener(new CustomWindowAdapter());
        this.setSize(300, 200);

        setLayout(null); // Layout null -> Positionen selber festlegen

        b1 = new Button("rot"); // Buttons erzeugen
        b1.setBounds(10, 40, 100, 20); // Position und Größe festlegen
        b2 = new Button("grün");
        b2.setBounds(10, 70, 100, 20);
        b3 = new Button("blau");
        b3.setBounds(10, 100, 100, 20);

        tf1= new TextField();
        tf1.setBounds(10, 130, 250, 20);
        tf1.setText("Info: ");

        add(b1); // Buttons in Frame einhängen
        add(b2);
        add(b3);
        add(tf1); // Textfeld einfügen

        b1.addActionListener(this); // Button dem ActionListener bekannt geben
        b2.addActionListener(this);
        b3.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e)
    {

        String cmd = e.getActionCommand();
        if (cmd.equals("rot"))
            this.setBackground(Color.RED);
        else if (cmd.equals("grün"))
            this.setBackground(Color.GREEN);
        else if (cmd.equals("blau"))
            this.setBackground(Color.BLUE);

        /* oder
        if (e.getSource()==b1)
            this.setBackground(Color.RED);
        else if (e.getSource()==b2)
            this.setBackground(Color.GREEN);
        else if (e.getSource()==b3)
            this.setBackground(Color.BLUE);
        */

        tf1.setText(tf1.getText() + " Klick");
    }
}
