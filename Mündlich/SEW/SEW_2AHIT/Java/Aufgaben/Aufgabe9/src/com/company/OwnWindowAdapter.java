package com.company;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class OwnWindowAdapter extends WindowAdapter
{
    public void windowClosing(WindowEvent e)
    {
        e.getWindow().setVisible(true);
        e.getWindow().dispose();
        System.exit(0);
    }

}
