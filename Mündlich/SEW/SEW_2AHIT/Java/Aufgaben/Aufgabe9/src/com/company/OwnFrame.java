package com.company;

import java.awt.*;

public class OwnFrame extends Frame
{
    public OwnFrame()
    {
        super("new frame");
        addWindowListener(new OwnWindowAdapter());
        addComponentListener(new OwnComponentAdapter());

        this.setSize(1000, 300);
    }

    @Override
    public void paint(Graphics g)
    {
        int startingPosX = 80;
        int startingPosY = this.getHeight() / 2;

        double padding = 80;

        g.setColor(Color.GRAY);

        g.drawString("x", this.getWidth() - (int)padding + 3, startingPosY + 3);
        g.drawString("y", (startingPosX - 3), ((int)padding) - 3);

        g.drawLine(startingPosX, (int)padding, startingPosX, this.getHeight() - (int)padding);
        g.drawLine(startingPosX, startingPosY, this.getWidth() - (int)padding, startingPosY);

        g.setColor(Color.MAGENTA);

        double amplitude;
        int width = this.getWidth();
        int height = this.getHeight();

        int spaceUp = startingPosY;
        int spaceDown = height - spaceUp;

        if (spaceDown > spaceUp)
        {
            amplitude = (spaceUp / 2.0);
        }
        else
        {
            amplitude = (spaceDown / 2.0);
        }

        double offset = startingPosY;

        double periodLengthMultiplier = 1 / ((width - padding * 2));

        double phaseShift = 2 * Math.PI * padding;

        for (int i = startingPosX; i < (width - padding); i++)
        {
            g.drawLine(i, getSinValue(i - startingPosX, amplitude, periodLengthMultiplier, phaseShift, offset), i, getSinValue(i - startingPosX, amplitude, periodLengthMultiplier, phaseShift, offset));
        }

    }

    private int getSinValue(double xCoordinate, double amplitude, double periodLengthMultiplier, double phaseShift, double offset)
    {
        return (int) Math.round(Math.sin(xCoordinate * periodLengthMultiplier * 2 * Math.PI + phaseShift) * amplitude + offset);
    }
}

