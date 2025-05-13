package com.company;

import org.w3c.dom.Text;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class CustomFrame extends Frame implements KeyListener, ActionListener
{
    Button button1;
    Button button2;
    TextField txt1;
    TextField txt2;

    public CustomFrame()
    {
        super("AWT-Program");
        this.setSize(400, 400);
        this.setVisible(true);
        this.setResizable(false);
        this.addWindowListener(new CustomWindowAdapter());
        this.addKeyListener(this);

        this.setLayout(null);



        this.button1 = new Button("Button 1");
        this.button1.setSize(40, 40);
        this.button1.setLocation(120, 200);

        this.add(button1);

        this.button2 = new Button("Button 2");
        this.button2.setSize(40, 40);
        this.button2.setLocation(170, 200);

        this.add(button2);

        button1.addActionListener(this);
        button2.addActionListener(this);

        txt1 = new TextField("TEXT!");
        txt1.setBounds(231, 50, 100, 20);
        this.add(txt1);
    }

    @Override
    public void paint(Graphics g)
    {
        g.drawString("OWO", 40, 40);
    }

    @Override
    public void keyTyped(KeyEvent e)
    {
        if (e.getKeyChar() == 'x')
        {
            System.exit(0);
        }
    }

    @Override
    public void keyPressed(KeyEvent e)
    {

    }

    @Override
    public void keyReleased(KeyEvent e)
    {

    }


    @Override
    public void actionPerformed(ActionEvent e)
    {
        System.out.println(e.getActionCommand());

        if (e.getSource() == this.button2)
        {
            System.out.println("good button");
        }
        else
        {
            System.out.println("CLICK!!!!!!!!!!!!! OWO UWUW RAWRWAR WARAR");
        }
    }
}
