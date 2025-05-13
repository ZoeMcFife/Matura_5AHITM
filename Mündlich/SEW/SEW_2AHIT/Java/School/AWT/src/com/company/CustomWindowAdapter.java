package com.company;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class CustomWindowAdapter extends WindowAdapter
{
    public void windowClosing(WindowEvent e)
    {
        e.getWindow().setVisible(false);
        System.exit(0);
    }
}
