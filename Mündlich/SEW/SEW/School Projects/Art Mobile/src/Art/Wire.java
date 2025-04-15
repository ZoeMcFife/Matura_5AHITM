package Art;

public class Wire implements Mobile
{
    public Mobile mobileRight;
    public Mobile mobileLeft;

    public double distanceRight;
    public double distanceLeft;

    public double length;

    Wire(Mobile mobileLeft, Mobile mobileRight, double length)
    {
        this.mobileLeft = mobileLeft;
        this.mobileRight = mobileRight;

        this.length = length;

        this.distanceLeft = length / 2;
        this.distanceRight = length / 2;
    }

    @Override
    public void balance()
    {
        this.mobileRight.balance();
        this.mobileLeft.balance();

        double weightLeft = this.mobileLeft.weight();
        double weightRight = this.mobileRight.weight();

        double shift = (-1 * (this.distanceLeft * weightLeft - this.distanceRight * weightRight)) / (weightLeft + weightRight);

        this.distanceLeft += shift;
        this.distanceRight -= shift;
    }

    @Override
    public double weight()
    {
        return (mobileLeft.weight() + mobileRight.weight());
    }

    @Override
    public String toString()
    {
        return "Mobile[" + this.distanceLeft + ":" + this.mobileLeft + ", " + this.distanceRight + ":" + this.mobileRight + "]";
    }
}
