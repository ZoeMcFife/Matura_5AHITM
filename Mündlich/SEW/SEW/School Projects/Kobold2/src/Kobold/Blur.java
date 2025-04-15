package Kobold;

public class Blur implements Behaviour
{
    private int max;

    Blur(int max)
    {
        this.max = Math.max(0, Math.min(10, max));
    }

    @Override
    public int modify(int n)
    {
        int change = (int)(Math.random() * this.max + 1);

        if ( (int) (Math.random() * 100)  % 2 == 0)
            return n - change;

        return n + change;    }
}
