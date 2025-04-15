package Compare;

import java.awt.*;

public class Store
{
    java.awt.Point location;
    String name;

    Store(Point location, String name)
    {
        this.location = location;
        this.name = name;
    }

    @Override
    public String toString()
    {
        return name;
    }
}
