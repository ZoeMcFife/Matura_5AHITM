package Threads;

public class Counter implements Runnable
{
    private final int number;

    Counter(int number)
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
}
