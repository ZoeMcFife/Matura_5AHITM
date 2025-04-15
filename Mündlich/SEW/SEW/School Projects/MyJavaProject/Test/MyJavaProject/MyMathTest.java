package MyJavaProject;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MyMathTest
{
    @Test
    void testMinimum()
    {
        int[] x = {12, 53, 8, 45};

        Assertions.assertEquals(9, MyMath.minimum(x));
    }
}
