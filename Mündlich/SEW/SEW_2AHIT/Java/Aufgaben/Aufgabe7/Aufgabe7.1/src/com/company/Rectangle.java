package com.company;

public class Rectangle
{
    double sideA;
    double sideB;

    protected int border;

    Rectangle(double sideA, double sideB)
    {
        if (sideA <= 0)
            this.sideA = 1;
        else
            this.sideA = sideA;

        if (sideB <= 0)
            this.sideB = 1;
        else
            this.sideB = sideB;

        this.border = 5;
    }

    public double getArea()
    {
        return this.sideA * this.sideB;
    }

    public void setBorder(int border)
    {
        if (border < 0)
            this.border = 0;
        else
            this.border = border;
    }

    public int getBorder()
    {
        return border;
    }

    @Override
    public String toString()
    {
        return "Rectangle with side lengths: " +
                "sideA=" + sideA +
                ", sideB=" + sideB;
    }
}
