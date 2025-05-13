package Vector;

import java.util.Objects;

public class Vector
{
    int x;
    int y;
    int z;

    Vector()
    {
        this(0, 0, 0);
    }

    Vector(int x, int y, int z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Vector(Vector v)
    {
        this.y = v.y;
        this.x = v.x;
        this.z = v.z;
    }

    public Vector add(int x, int y, int z)
    {
        this.y += y;
        this.x += x;
        this.z += z;

        return this;
    }

    public Vector add(Vector v)
    {
        return add(v.x, v.y, v.z);
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Vector vector = (Vector) o;
        return x == vector.x && y == vector.y && z == vector.z;
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(x, y, z);
    }

    @Override
    public String toString()
    {
        return "(" + this.x + ", " + this.y + ", " + this.z + ")";
    }
}
