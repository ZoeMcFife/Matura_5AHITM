package myvehicles;

public class VehicleTest
{
    public static void main(String[] args)
    {
        Buffer<Car> carBuffer = new Buffer<>();
        Buffer<Truck> truckBuffer = new Buffer<>();

        carBuffer.put(new Car(100));
        carBuffer.put(new Car(120));
        carBuffer.put(new Car(140));

        truckBuffer.put(new Truck(20));
        truckBuffer.put(new Truck(40));
        truckBuffer.put(new Truck(60));

        process(carBuffer);
        process(truckBuffer);
    }

    public static void process(Buffer<? extends Vehicle> buffer)
    {
        int size = buffer.bufferSize();

        for (int i = 0; i < size; i++)
        {
            buffer.get().drive();
        }
    }
}
