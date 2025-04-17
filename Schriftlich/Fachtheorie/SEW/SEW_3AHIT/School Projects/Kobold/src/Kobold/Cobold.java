package Kobold;

public class Cobold
{
    private final String name;
    private final Behaviour[] behaviours;

    public Cobold(String name, Behaviour... behaviours)
    {
        this.name = name;
        this.behaviours = behaviours.clone(); // New Object gets initialized that has the same contents
    }

    public int messUp(int n)
    {
        for (Behaviour b : behaviours)
        {
            n = b.modify(n);
        }

        return n;
    }
}
