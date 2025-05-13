package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class Main {

    public static void main(String[] args)
    {
        JFrame frame = new JFrame();

        JLabel label = new JLabel("Label");
        label.setBounds(100, 160, 100, 20);

        JButton button = new JButton("click");
        button.setBounds(100, 60,100, 50);//x axis, y axis, width, height
        button.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                label.setText("Hello World");

                System.out.println(label.getAlignmentX());

               // label.setHorizontalAlignment(20);
            }
        });




        frame.add(button);//adding button in JFrame
        frame.add(label);

        frame.setSize(300,300);
        frame.setLayout(null);//using no layout managers
        frame.setVisible(true);//making the frame visible
    }
}
