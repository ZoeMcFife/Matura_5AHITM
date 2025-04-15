package Progression;

public abstract class Progression
{
    protected long current;

    public long nextValue()
    {
        advance();
        return current;
    }

    public void printProgression(int n)
    {
        for (int i = 0; i < n; i++)
        {
            System.out.print(current + " ");
            advance();
        }
    }

    protected abstract void advance();


}
