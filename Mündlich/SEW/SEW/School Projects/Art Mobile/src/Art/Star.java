package Art;

public class Star implements Mobile
{
    public double weight;

    Star(double weight) throws IllegalArgumentException
    {
        if (weight <= 0)
        {
            throw new IllegalArgumentException("Weight must be greater than 0");
        }

        this.weight = weight;
    }

    @Override
    public double weight()
    {
        return this.weight;
    }

    @Override
    public void balance()
    {
        // empty
    }

    @Override
    public String toString()
    {
        return "Star[" + this.weight + "]";
    }
}
