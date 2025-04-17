package MoreThreads;

public class Thread_BSP3 implements Runnable
{
    private final Int intObj;

    Thread_BSP3(Int intObj)
    {
        this.intObj = intObj;
    }

    @Override
    public void run()
    {
        int i = 0;

        while (intObj.test(i) && ++i < 1000);

        System.out.println(Thread.currentThread().getName() + ": " + i);
    }

    public static void main(String[] args)
    {
        Int o = new Int();
        Thread[] a = new Thread[80];

        for (int i = 0; i < a.length; i++)
        {
            a[i] = new Thread(new Thread_BSP3(o));
            a[i].start();
        }
    }
}
