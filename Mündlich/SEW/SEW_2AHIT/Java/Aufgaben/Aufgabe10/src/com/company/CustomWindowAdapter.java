package com.company;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class CustomWindowAdapter extends WindowAdapter
{
    @Override
    public void windowClosing(WindowEvent e)
    {
        e.getWindow().setVisible(false);
        e.getWindow().dispose();
        System.exit(0);
    }
}
