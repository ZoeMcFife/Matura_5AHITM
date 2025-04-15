package MyJavaProject;

public class MyMathTest
{
    public static void main(String[] args)
    {
        int[] x = {12, 53, 8, 45};
        int[] y = {3, 8, 22, 96, 41, 7, 11};
        int[] z = {1, 6, 2, 8};

        System.out.println(MyMath.average(x));
        System.out.println(MyMath.maximum(x));
        System.out.println(MyMath.minimum(x));

        System.out.println(MyMath.average(y));
        System.out.println(MyMath.maximum(y));
        System.out.println(MyMath.minimum(y));

        System.out.println(MyMath.average(z));
        System.out.println(MyMath.maximum(z));
        System.out.println(MyMath.minimum(z));
    }
}
