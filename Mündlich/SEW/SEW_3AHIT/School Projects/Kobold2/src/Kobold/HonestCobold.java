package Kobold;

import java.sql.Timestamp;

public class HonestCobold extends Cobold
{
    private long honestyEnds;

    HonestCobold(String name, Behaviour... behaviours)
    {
        super(name, behaviours);
    }

    public void beHonestFor(int time)
    {
        long currentTime = System.currentTimeMillis() / 1000;

        this.honestyEnds = currentTime + time;
    }

    @Override
    public int messUp(int value)
    {
        if ((System.currentTimeMillis() / 1000) > this.honestyEnds)
        {
            return super.messUp(value);
        }

        return value;
    }
}
