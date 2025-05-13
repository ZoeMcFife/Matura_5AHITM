package Art;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.function.Executable;

public class StarTest {
    @Test
    void testToString() {
        Star star = new Star(4);
        Assertions.assertEquals("Star[4.0]",star.toString());
    }

    @Test
    void testWeightOfStar() {
        Star star = new Star(4);
        Assertions.assertEquals(4, star.weight());
        Assertions.assertThrows(IllegalArgumentException.class,
                new Executable() {
                    @Override
                    public void execute() throws Throwable {
                        Star star1 = new Star(-1);
                    }
                });
    }
}