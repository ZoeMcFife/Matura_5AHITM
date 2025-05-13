package com.company;

public class Main
{
    public static void main(String[] args) throws Exception
    {
        Resistor resistor = new Resistor(Color.BLUE, Color.YELLOW, Color.GREEN, Color.GREEN);
        System.out.println(resistor);

        try
        {
            Resistor resistor1 = new Resistor(Color.BROWN, Color.GOLD, Color.BROWN, Color.GOLD);
            System.out.println(resistor1);
        }
        catch (Exception e)
        {
            System.out.println("Exception caught.");
        }
    }
}
