package Kobold;

public class Theft implements Behaviour
{
    private int greed;
    private boolean prefersEven;

    Theft(int greed, boolean prefersEven)
    {
        this.greed = Math.max(0, Math.min(100, greed));
        this.prefersEven = prefersEven;
    }

    @Override
    public int modify(int n)
    {
        if (n % 2 == 0 && prefersEven)
            return n - this.greed;
        else if (n % 2 != 0 && !prefersEven)
            return n - this.greed;

        return n;
    }
}
