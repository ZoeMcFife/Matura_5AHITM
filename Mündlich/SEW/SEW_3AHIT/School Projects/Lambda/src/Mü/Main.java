package Mü;

import java.util.Arrays;
import java.util.List;

public class Main
{
    @FunctionalInterface
    interface IntCheck
    {
        int checkIt(int a, int b);
    }

    public int operation(int x, int y, IntCheck xy)
    {
        return xy.checkIt(x,y);
    }

    public static void main(String[] args)
    {
        int calc = new Main().operation(20, 10, (x, y) -> x * y);

        System.out.println(calc);

        Integer[] data = {1,2,3};
        List<Integer> lst = Arrays.asList(data);
        lst.forEach(System.out::println);


        lst.forEach(System.out::println);
    }
}
