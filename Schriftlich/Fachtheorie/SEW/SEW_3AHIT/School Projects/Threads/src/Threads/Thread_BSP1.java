package Threads;

public class Thread_BSP1
{
    public static void main(String[] args)
    {
        Thread t1 = new Thread(new Counter(1));
        Thread t2 = new Thread(new Counter(2));

        t1.start();
        t2.start();
    }
}


