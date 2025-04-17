package Kobold;

import java.util.Arrays;

public class Cobold
{
    private Behaviour behaviours[];
    public String name;

    Cobold(String name, Behaviour... behaviours)
    {
        this.name = name;
        this.behaviours = behaviours;
    }

    public int messUp(int value)
    {
        for (Behaviour behaviour : this.behaviours)
        {
            value = behaviour.modify(value);
        }

        return value;
    }

    @Override
    public String toString()
    {
        return "Cobold{" +
                "behaviours=" + Arrays.toString(behaviours) +
                ", name='" + name + '\'' +
                '}';
    }
}
