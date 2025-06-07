package com.example.demo.data;

import static org.junit.Assert.assertThrows;

import junit.framework.TestCase;

public class CalculatorTest extends TestCase {

    public void testAdd()
    {
        assertEquals(4, new Calculator().add(2, 2));
    }

    public void testSub()
    {
        assertEquals(0, new Calculator().sub(2, 2));
    }

    public void testMul()
    {
        assertEquals(4, new Calculator().mul(2, 2));
    }

    public void testDiv()
    {
        assertEquals(1, new Calculator().div(2, 2));
    }

    public void testDivByZero()
    {
        assertThrows(ArithmeticException.class, () -> new Calculator().div(2, 0));
    }
}