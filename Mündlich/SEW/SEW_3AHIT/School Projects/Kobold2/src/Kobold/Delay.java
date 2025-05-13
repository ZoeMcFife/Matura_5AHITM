package Kobold;

public class Delay implements Behaviour
{
    private int delay;

    Delay(int delay)
    {
        this.delay = Math.max(0, Math.min(10, delay));
    }

    @Override
    public int modify(int n)
    {
        try
        {
            Thread.sleep(this.delay * 1000);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        return n;
    }
}
