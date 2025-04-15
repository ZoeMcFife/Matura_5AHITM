package Threads;

public class Thread_BSP2 extends Thread
{
    private final int number;

    Thread_BSP2(int number)
    {
        this.number = number;
    }

    @Override
    public void run()
    {
        for (int i = 0; i < 100; i++)
        {
            System.out.println("Thread " + this.number + ": " + i);
        }
    }

    public static void main(String[] args)
    {
        Thread_BSP2 t1 = new Thread_BSP2(1);
        Thread_BSP2 t2 = new Thread_BSP2(2);

        t1.start();
        t2.start();
    }
}
