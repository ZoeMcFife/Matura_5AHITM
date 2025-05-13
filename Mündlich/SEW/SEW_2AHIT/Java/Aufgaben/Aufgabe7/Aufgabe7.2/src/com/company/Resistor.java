package com.company;

public class Resistor
{
    private Color ring1Color;
    private Color ring2Color;
    private Color ring3Color;
    private Color ring4Color;

    Resistor(Color ring1Color, Color ring2Color, Color ring3Color, Color ring4Color) throws Exception
    {
        setRing1Color(ring1Color);
        setRing2Color(ring2Color);
        setRing3Color(ring3Color);
        setRing4Color(ring4Color);
    }

    public void setRing1Color(Color ring1Color) throws Exception
    {
        if (ring1Color == Color.GOLD || ring1Color == Color.SILVER || ring1Color == Color.NONE)
        {
            throw new Exception("Ring 1 can't be Gold, Silver or None!");
        }
        else
        {
            this.ring1Color = ring1Color;
        }
    }

    public void setRing2Color(Color ring2Color) throws Exception
    {
        if (ring2Color == Color.GOLD || ring2Color == Color.SILVER || ring2Color == Color.NONE)
        {
            throw new Exception("Ring 2 can't be Gold, Silver or None!");
        }
        else
        {
            this.ring2Color = ring2Color;
        }
    }

    public void setRing3Color(Color ring3Color) throws Exception
    {
        if (ring3Color == Color.NONE)
        {
            throw new Exception("Ring 3 can't be None!");
        }

        this.ring3Color = ring3Color;
    }

    public void setRing4Color(Color ring4Color) throws Exception
    {
        if (ring4Color == Color.BLACK || ring4Color == Color.ORANGE || ring4Color == Color.YELLOW || ring4Color == Color.WHITE)
        {
            throw new Exception("Ring 4 can't be Black, Orange, Yellow or White!");
        }
        else
        {
            this.ring4Color = ring4Color;
        }
    }

    public double getResistance()
    {
        double digit1 = 0;
        double digit2 = 0;
        double multiplier = 0;

        switch (ring1Color)
        {
            case BLACK -> digit1 = 0;
            case BROWN -> digit1 = 1;
            case RED -> digit1 = 2;
            case ORANGE -> digit1 = 3;
            case YELLOW -> digit1 = 4;
            case GREEN -> digit1 = 5;
            case BLUE -> digit1 = 6;
            case PURPLE -> digit1 = 7;
            case GREY -> digit1 = 8;
            case WHITE -> digit1 = 9;
        }

        switch (ring2Color)
        {
            case BLACK -> digit2 = 0;
            case BROWN -> digit2 = 1;
            case RED -> digit2 = 2;
            case ORANGE -> digit2 = 3;
            case YELLOW -> digit2 = 4;
            case GREEN -> digit2 = 5;
            case BLUE -> digit2 = 6;
            case PURPLE -> digit2 = 7;
            case GREY -> digit2 = 8;
            case WHITE -> digit2 = 9;
        }

        switch (ring3Color)
        {
            case BLACK -> multiplier = 1;
            case BROWN -> multiplier = 10;
            case RED -> multiplier = Math.pow(10, 2);
            case ORANGE -> multiplier = Math.pow(10, 3);
            case YELLOW -> multiplier = Math.pow(10, 4);
            case GREEN -> multiplier = Math.pow(10, 5);
            case BLUE -> multiplier = Math.pow(10, 6);
            case PURPLE -> multiplier = Math.pow(10, 7);
            case GREY -> multiplier = Math.pow(10, 8);
            case WHITE -> multiplier = Math.pow(10, 9);
            case GOLD -> multiplier = Math.pow(10, -1);
            case SILVER -> multiplier = Math.pow(10, -2);
        }

         return (digit1 * 10 + digit2) * multiplier;
    }

    public double getTolerance()
    {
        double tolerance = 0;

        switch (ring4Color)
        {
            case BROWN -> tolerance = 1 / 100.0;
            case RED -> tolerance = 2 / 100.0;
            case GREEN -> tolerance = 5 / 1000.0;
            case BLUE -> tolerance = 25 / 10000.0;
            case PURPLE -> tolerance = 1 / 10000.0;
            case GREY -> tolerance = 5 / 100000.0;
            case GOLD -> tolerance = 5 / 100.0;
            case SILVER -> tolerance = 10 / 100.0;
            case NONE -> tolerance = 20 / 100.0;
        }

        return tolerance;
    }

    @Override
    public String toString()
    {
        return "Resistor: R = " + getResistance() + " Ohm" + " Tolerance: " + getTolerance() * 100 + " %";
    }
}
