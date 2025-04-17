package Art;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class WireTest {
    @Test
    void testWeightOfWire() {
        Star s1 = new Star(4);
        Star s2 = new Star(2);
        Wire s12 = new Wire(s1,s2,9);
        s12.balance();
        Assertions.assertEquals("Mobile[3.0:Star[4.0], 6.0:Star[2.0]]",s12.toString());
    }
}