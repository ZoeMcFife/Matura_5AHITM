package Kobold;

public class Odds implements Behaviour
{
    private Behaviour otherBehaviour;

    Odds(Behaviour otherBehaviour)
    {
        this.otherBehaviour = otherBehaviour;
    }

    @Override
    public int modify(int n)
    {
        if (n % 2 == 0)
            return n;

        return this.otherBehaviour.modify(n);
    }
}
