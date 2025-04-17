package Arithmetic;

public class Calculator
{
    public static void main(String[] args)
    {
        System.out.println(compute(4, Operator.PLUS, 2));
        System.out.println(compute(4, Operator.MINUS, 2));
        System.out.println(compute(4, Operator.DIVIDE, 2));
        System.out.println(compute(4, Operator.MULTIPLY, 2));

    }

    public static int compute(int x, Operator operator, int y)
    {
        int result = 0;

        switch (operator)
        {
            case PLUS -> result = x + y;
            case MINUS -> result = x - y;
            case DIVIDE -> result = (x / y);
            case MULTIPLY -> result = x * y;
        }

        return result;
    }
}
