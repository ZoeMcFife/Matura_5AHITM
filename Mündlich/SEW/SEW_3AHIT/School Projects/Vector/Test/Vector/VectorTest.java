package Vector;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class VectorTest
{
    @Test
    void testVector1()
    {
        int x = 1;
        int y = 2;
        int z = 3;

        Vector v = new Vector(x, y, z);

        Assertions.assertEquals(x, v.x);
        Assertions.assertEquals(y, v.y);
        Assertions.assertEquals(z, v.z);
    }

    @Test
    void testVector2()
    {
        int x = 1;
        int y = 2;
        int z = 3;

        Vector v = new Vector(x, y, z);

        Vector v2 = new Vector(v);
        Assertions.assertEquals(v2, v);
    }

    @Test
    void testVector3()
    {
        Vector v = new Vector();

        Assertions.assertEquals(0, v.x);
        Assertions.assertEquals(0, v.y);
        Assertions.assertEquals(0, v.z);
    }

    @Test
    void testAdd1()
    {
        Vector v = new Vector(1, 2, 3);

        int x = 1;
        int y = 2;
        int z = 3;

        Assertions.assertEquals(new Vector(2, 4, 6), v.add(x, y, z));
    }

    @Test
    void testAdd2()
    {
        Vector v = new Vector(1, 2, 3);
        Vector v2 = new Vector(5, -2 ,-3);

        Assertions.assertEquals(new Vector(6, 0, 0), v.add(v2));
    }

    @Test
    void testToString()
    {
        Vector v = new Vector(1, 1, 1);
        Assertions.assertEquals("(1, 1, 1)", v.toString());
    }
}
