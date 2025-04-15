package Fraction;

import com.sun.source.tree.AssertTree;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class FractionTest
{
    @Test
    void equalTest()
    {
        Fraction f1 = new Fraction(1, 2);
        Fraction f2 = new Fraction(2, 4);

        Assertions.assertTrue(f1.equals(f2));
    }

    @Test
    void equalTest2()
    {
        Fraction f1 = new Fraction(2, 6);
        Fraction f2 = new Fraction(1, 3);

        Assertions.assertTrue(f1.equals(f2));
    }

    @Test
    void addTest()
    {
        Fraction f1 = new Fraction(1, 3);
        Fraction f2 = new Fraction(2, 6);
        Fraction expected = new Fraction(4, 6);
        f1.add(f2);

        Assertions.assertEquals(expected, f1);
    }

    @Test
    void subtractTest()
    {
        Fraction f1 = new Fraction(3, 3);
        Fraction f2 = new Fraction(2, 6);
        Fraction expected = new Fraction(2, 3);
        f1.subtract(f2);

        Assertions.assertEquals(expected, f1);
    }

    @Test
    void multiplyTest()
    {
        Fraction f1 = new Fraction(1, 2);
        Fraction f2 = new Fraction(2, 2);
        Fraction expected = new Fraction(2, 4);

        f1.multiply(f2);

        Assertions.assertEquals(expected, f1);
    }

    @Test
    void divideTest()
    {
        Fraction f1 = new Fraction(2, 4);
        Fraction f2 = new Fraction(3, 2);
        Fraction expected = new Fraction(4, 12);

        f1.divide(f2);

        Assertions.assertEquals(expected, f1);
    }

    @Test
    void divideTest2()
    {
        Fraction f1 = new Fraction(2, 4);
        Fraction f2 = new Fraction(4, 8);
        Fraction expected = new Fraction(1, 1);

        f1.divide(f2);

        Assertions.assertEquals(expected, f1);
    }

    @Test
    void divideTest3()
    {
        Fraction f1 = new Fraction(3, 10);
        Fraction expected = new Fraction(1, 1);

        f1.divide(f1);

        Assertions.assertEquals(expected, f1);
    }

    @Test
    void negateTest()
    {
        Fraction f1 = new Fraction(2, 4);
        Fraction expected = new Fraction(-2, 4);

        f1.negate();

        Assertions.assertEquals(expected, f1);
    }

    @Test
    void invertTest()
    {
        Fraction f1 = new Fraction(2, 4);
        Fraction expected = new Fraction(4, 2);

        f1.invert();

        Assertions.assertEquals(expected, f1);
    }

    @Test
    void toDoubleTest()
    {
        Fraction f1 = new Fraction(1, 2);
        Double expected = 0.5;

        Assertions.assertEquals(expected, f1.toDouble());
    }

    @Test
    void reduceTest()
    {
        Fraction f1 = new Fraction(5, 10);
        Fraction f2 = f1.reduce();

        Assertions.assertTrue(f2.n == 1 && f2.d == 2);
    }


    @Test
    void reduceTest2()
    {
        Fraction f1 = new Fraction(34, 36);
        Fraction f2 = f1.reduce();

        Assertions.assertTrue(f2.n == 17 && f2.d == 18);
    }

    @Test
    void reduceTest3()
    {
        Fraction f1 = new Fraction(10, 2);
        Fraction f2 = f1.reduce();

        Assertions.assertTrue(f2.n == 5 && f2.d == 1);
    }

    @Test
    void reduceTest4()
    {
        Fraction f1 = new Fraction(32, 32);
        Fraction f2 = f1.reduce();

        Assertions.assertTrue(f2.n == 1 && f2.d == 1);
    }

    @Test
    void resetFractionCounterTest()
    {
        Fraction f1 = new Fraction(1, 1);
        Fraction.resetFractionCounter();

        Assertions.assertEquals(0, Fraction.fractionCounter);
    }
}
