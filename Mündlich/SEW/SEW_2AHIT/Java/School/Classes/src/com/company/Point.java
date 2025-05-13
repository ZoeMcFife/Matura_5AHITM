package com.company;

public class Point
{
    double xCoordinate;
    double yCoordinate;

    Point()
    {
        xCoordinate = 0;
        yCoordinate = 0;
    }

    Point(double xCoordinate, double yCoordinate)
    {
        this.xCoordinate = xCoordinate;
        this.yCoordinate = yCoordinate;
    }

    public void print()
    {
        System.out.println("X: " + this.xCoordinate);
        System.out.println("Y: " + this.yCoordinate);
    }

    @Override
    public String toString()
    {
        return "Point{" +
                "xCoordinate=" + xCoordinate +
                ", yCoordinate=" + yCoordinate +
                '}';
    }
}
