package Progression;

import java.sql.SQLOutput;

public class TestProgression
{
    public static void main(String[] args)
    {
        Progression prog;

        System.out.println("Arithmetic progression with default increment:");
        prog = new ArithmeticProgression();
        prog.printProgression(10);

        System.out.println("\n\nArithmetic progression with increment 5:");
        prog = new ArithmeticProgression(5);
        prog.printProgression(10);

        System.out.println("\n\nArithmetic progression with start 2:");
        prog = new ArithmeticProgression(5, 2);
        prog.printProgression(10);

        System.out.println("\n\nGeometric progression with default base:");
        prog = new GeometricProgression();
        prog.printProgression(10);

        System.out.println("\n\nGeometric progression with base 3:");
        prog = new GeometricProgression(3);
        prog.printProgression(10);

        System.out.println("\n\nGeometric progression with base 4 and start 27:");
        prog = new GeometricProgression(4, 27);
        prog.printProgression(10);

        System.out.println("\n\nExponential progression with default exponent:");
        prog = new ExponentialProgression();
        prog.printProgression(10);

        System.out.println("\n\nExponential progression with exponent 3:");
        prog = new ExponentialProgression(3);
        prog.printProgression(10);

        System.out.println("\n\nExponential progression with exponent 2 and start 5:");
        prog = new ExponentialProgression(2, 5);
        prog.printProgression(10);
    }
}
