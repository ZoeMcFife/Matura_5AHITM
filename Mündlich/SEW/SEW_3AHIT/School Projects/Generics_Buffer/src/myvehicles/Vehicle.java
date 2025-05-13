package myvehicles;

public abstract class Vehicle
{
    public double speed;

    Vehicle()
    {
        this.speed = 0;
    }

    Vehicle(double speed)
    {
        this.speed = speed;
    }

    public abstract void drive();
}
