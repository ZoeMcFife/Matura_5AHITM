package com.company;

public class Square extends Rectangle
{
    Square(double side)
    {
        super(side, side);
    }

    @Override
    public String toString()
    {
        return "Square with side lengths: " +
                "side=" + this.sideA;
    }
}
