package myvehicles;

public class Car extends Vehicle
{
    public Car(double speed)
    {
        super(speed);
    }

    @Override
    public void drive()
    {
        System.out.println("Car with speed " + this.speed);
    }

    @Override
    public String toString()
    {
        return "(Car " + this.speed + ")";
    }
}
