package Shoes;

public class Farm<Evil>
{
    public Evil habitant;

    Farm()
    {
        this.habitant = null;
    }

    Farm(Evil habitant)
    {
        this.habitant = habitant;
    }

    @Override
    public String toString()
    {
        return "Farm{" +
                "habitant=" + habitant +
                '}';
    }
}
