package Kobold;

public class Kobold
{
    private String name;
    private int silliness;

    Kobold(String name, int silliness)
    {
        this.name = name;
        this.silliness = Math.max(0, Math.min(10, silliness));
    }

    public int messUp(int value)
    {
        int change = (int)(Math.random() * silliness * (value / 3) + 1);

        if ( (int) (Math.random() * 100)  % 2 == 0)
            return value - change;

        return value + change;
    }

    @Override
    public String toString()
    {
        return "Kobold{" +
                "name='" + name + '\'' +
                ", silliness=" + silliness +
                '}';
    }
}
