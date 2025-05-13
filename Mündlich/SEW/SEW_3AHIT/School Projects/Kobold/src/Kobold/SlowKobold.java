package Kobold;

import java.lang.management.MemoryType;

public class SlowKobold extends Kobold
{
    private int delay;

    SlowKobold(String name, int delay)
    {
       super(name, 0);
       this.delay = Math.max(0, Math.min(10, delay));
    }

    @Override
    public int messUp(int value)
    {
        try
        {
            Thread.sleep(delay * 1000);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        return value;
    }
}
