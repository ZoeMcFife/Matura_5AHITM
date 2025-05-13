package com.company;

public class Point
{
    double x;
    double y;

    Point(double x, double y)
    {
        this.x = x;
        this.y = y;
    }

    Point()
    {
        this.x = 0;
        this.y = 0;
    }

    public void move(double dx, double dy)
    {
        this.x += dx;
        this.y += dy;
    }

    public double distance()
    {
        return Math.sqrt(Math.pow(this.x, 2) + Math.pow(this.y, 2));
    }

    public double distance(Point point)
    {
       return Math.sqrt(Math.pow(this.x - point.x, 2) + Math.pow(this.y - point.y, 2));
    }

    @Override
    public String toString()
    {
        return "(" + this.x + "/" + this.y + ")";
    }
}
