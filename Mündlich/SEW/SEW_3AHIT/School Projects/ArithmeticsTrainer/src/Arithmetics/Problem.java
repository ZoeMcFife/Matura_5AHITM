package Arithmetics;

public class Problem
{
    private int num1;
    private int num2;
    private char sign;
    private int result;

    private final int minValue = 1;
    private final int maxValue = 9;

    Problem()
    {
        this.num1 = newNumber();
        this.num2 = newNumber();
        this.sign = newSign();
        this.result = calculateResult();
    }

    private int newNumber()
    {
        return (int) (Math.random() * (this.maxValue - this.minValue + 1) + this.minValue);
    }

    private char newSign()
    {
        char[] signs = {'+', '-', '*'};

        return signs[(int) (Math.random() * 3)];
    }

    private int calculateResult()
    {
        if (this.sign == '+')
        {
            return this.num1 + this.num2;
        }

        if (this.sign == '-')
        {
            return this.num1 - this.num2;
        }

        if (this.sign == '*')
        {
            return this.num1 * this.num2;
        }

        return 0;
    }

    public int getResult()
    {
        return result;
    }

    @Override
    public String toString()
    {
        return this.num1 + " " + this.sign + " " + num2;
    }
}
