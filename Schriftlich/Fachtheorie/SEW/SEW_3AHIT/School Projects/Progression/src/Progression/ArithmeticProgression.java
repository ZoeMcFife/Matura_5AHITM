package Progression;

public class ArithmeticProgression extends Progression
{
    private long step;

    ArithmeticProgression()
    {
        this.step = 1;
        this.current = 0;
    }

    ArithmeticProgression(long step)
    {
        this.step = step;
        this.current = 0;
    }

    ArithmeticProgression(long step, long start)
    {
        this.step = step;
        this.current = start;
    }

    @Override
    protected void advance()
    {
        this.current += step;
    }
}
