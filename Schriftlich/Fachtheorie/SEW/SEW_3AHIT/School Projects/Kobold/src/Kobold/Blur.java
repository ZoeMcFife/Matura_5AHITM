package Kobold;

public class Blur implements Behaviour
{
    private int silliness;

    public Blur(int silliness)
    {
        this.silliness = Math.max(0, Math.min(10, silliness));;
    }

    @Override
    public int modify(int value)
    {
        int change = (int)(Math.random() * this.silliness * (value / 3) + 1);

        if ( (int) (Math.random() * 100)  % 2 == 0)
            return value - change;

        return value + change;
    }
}
