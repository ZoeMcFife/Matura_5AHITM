package Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AfraidOfFiveTest
{
    @Test
    void fiveAtLastTest()
    {
        int[] array = {1, 55, 2, 5, 53};
        int[] expectedArray = {1, 2, 55, 5, 53};

        Assertions.assertArrayEquals(expectedArray, AfraidOfFive.fiveAtLast(array));
    }

    @Test
    void fiveAtLastTest2()
    {
        Exception exception = Assertions.assertThrows(IllegalArgumentException.class, () ->
        {
            AfraidOfFive.fiveAtLast(null);
        });

        String expected = "Array must not be null!";
        String actual = exception.getMessage();

        Assertions.assertTrue(actual.contains(expected));
    }
}
