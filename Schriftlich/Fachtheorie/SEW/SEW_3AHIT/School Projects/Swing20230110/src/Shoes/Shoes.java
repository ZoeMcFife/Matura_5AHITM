package Shoes;

import java.util.Objects;

public class Shoes
{
    private int size;
    private String color;

    public Shoes(int size, String color)
    {
        this.size = size;
        this.color = color;
    }

    @Override
    public String toString()
    {
        return size + " " + color;
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Shoes shoes = (Shoes) o;
        return size == shoes.size && Objects.equals(color, shoes.color);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(size, color);
    }

    public String getColor()
    {
        return color;
    }

    public int getSize()
    {
        return size;
    }
}
