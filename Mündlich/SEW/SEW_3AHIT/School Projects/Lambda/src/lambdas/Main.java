package lambdas;

public class Main
{
    public static void main(String[] args)
    {
        Calculator calculator = new Calculator();

        Calculator.IntegerMath addition = Integer::sum;
        Calculator.IntegerMath subtraction = (a, b) -> a - b;

        System.out.println("40 + 2 = " + calculator.operate(40, 2, addition));
        System.out.println("20 - 10 = " + calculator.operate(20, 10, subtraction));
        System.out.println("5 * 10 = " + calculator.operate(5, 10, (a, b) -> a * b));
        System.out.println("20 / 4 = " + calculator.operate(20, 4, (a, b) -> (int) (((double) a) / ((double) b))));
    }
}
