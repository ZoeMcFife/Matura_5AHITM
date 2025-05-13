package com.company;

import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

public class OwnComponentAdapter extends ComponentAdapter
{
    @Override
    public void componentResized(ComponentEvent e)
    {
        e.getComponent().repaint();
    }
}
