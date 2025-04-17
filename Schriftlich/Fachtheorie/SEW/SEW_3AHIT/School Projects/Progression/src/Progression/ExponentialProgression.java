package Progression;

/*
    Increases value by raising it to a given exponent
 */

public class ExponentialProgression extends Progression
{
    private long exponent;

    ExponentialProgression()
    {
        this.exponent = 2;
        this.current = 2;
    }

    ExponentialProgression(long exponent)
    {
        this.exponent = exponent;
        this.current = 2;
    }

    ExponentialProgression(long exponent, long start)
    {
        this.exponent = exponent;
        this.current = start;
    }

    @Override
    protected void advance()
    {
        this.current = (long) Math.pow(this.current, this.exponent);
    }
}
