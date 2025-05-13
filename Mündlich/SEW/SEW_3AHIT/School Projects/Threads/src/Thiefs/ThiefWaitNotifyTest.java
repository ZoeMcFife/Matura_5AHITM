package Thiefs;

public class ThiefWaitNotifyTest
{
    public static void main(String[] args)
    {
        final ThiefChief joe = new ThiefChief("Joe");
        final ThiefCarDriver biden = new ThiefCarDriver("Biden");
        final Store walmart = new Store();

        final Thread driverThread = new Thread(() ->
        {
            synchronized (walmart)
            {
                System.out.println("Driver is waiting");

                try
                {
                    walmart.wait();
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }
            }

            biden.letsGoIntoTheStore(walmart);
        });

        final Thread chiefThread = new Thread(() ->
        {
            synchronized (walmart)
            {
                System.out.println("Chief is waiting");

                try
                {
                    walmart.wait();
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }
            }

            joe.letsGoIntoTheStore(walmart);
        });

        driverThread.start();
        chiefThread.start();

        try
        {
            Thread.sleep(500);
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        synchronized (walmart)
        {
            System.out.println("Store is opening . . . you can enter!");
            walmart.notifyAll();
        }
    }
}
