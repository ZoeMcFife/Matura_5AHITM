package com.company;

public class Turtle
{
    private Point location;
    private double angle;

    public Point getLocation()
    {
        return this.location;
    }

    public void setLocation(Point location)
    {
        this.location = location;
    }

    public void setAngle(double angle)
    {
        this.angle = angle;
    }

    public double getAngle()
    {
        return this.angle;
    }

    Turtle()
    {
        this.location = new Point();
        this.angle = 0;
    }

    Turtle(double x, double y)
    {
        this.location = new Point(x, y);
        this.angle = 0;
    }

    Turtle(double x, double y, double angle)
    {
        this.location = new Point(x, y);
        this.angle = angle;
    }

    public void move(double distance)
    {
        //moves turtle a specific distance

        this.location.x += Math.sin(Math.toRadians(this.angle)) * distance;
        this.location.y += Math.cos(Math.toRadians(this.angle)) * distance;
    }

    //converts any given angle to be between 0 and 360. Negative angles counted anti-clockwise i.e. -3 -> 357
    private double convertAngleTo360(double angle)
    {
        double timesGreater;

        if (angle < 0)
        {
            timesGreater = Math.floor(Math.abs(angle) / 360);
            angle = 360 * (timesGreater + 1) + angle;
        }

        timesGreater = Math.floor(Math.abs(angle) / 360);

        return angle - timesGreater * 360;
    }

    public void turn(double angle)
    {
        this.angle = convertAngleTo360(this.angle + angle);
    }

    public void turnLeft()
    {
        turn(90);
    }

    public void turnRight()
    {
        turn(-90);
    }

    @Override
    public String toString()
    {
        return "Position: " + "(" + this.location.x + "\\" + this.location.y + ")" + " Angle: " + this.angle;
    }
}
