package Progression;

public class GeometricProgression extends Progression
{
    private long base;

    GeometricProgression()
    {
        this.base = 2;
        this.current = 1;
    }

    GeometricProgression(long base)
    {
        this.base = base;
        this.current = 1;
    }

    GeometricProgression(long base, long start)
    {
        this.base = base;
        this.current = start;
    }

    @Override
    protected void advance()
    {
        this.current *= base;
    }
}
