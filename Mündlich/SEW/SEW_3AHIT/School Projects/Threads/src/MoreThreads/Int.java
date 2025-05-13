package MoreThreads;

public class Int
{
    private int i;

    synchronized boolean test(int j)
    {
        this.i = j;

        return i == j;
    }
}
