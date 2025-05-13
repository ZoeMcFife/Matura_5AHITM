package lambdas;

public class Calculator
{
    interface IntegerMath
    {
        int operation(int a, int b);
    }

    public int operate(int a, int b, IntegerMath operation)
    {
        return operation.operation(a, b);
    }

}
