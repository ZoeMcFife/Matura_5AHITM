package myvehicles;

public class Truck extends Vehicle
{
    Truck(double speed)
    {
        super(speed);
    }

    @Override
    public void drive()
    {
        System.out.println("Truck with speed " + this.speed);
    }

    @Override
    public String toString()
    {
        return "(Truck " + this.speed + ")";
    }
}
