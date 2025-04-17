package MyJavaProject;

public class MyMath
{
    public static int minimum(int[] array)
    {
        int min = array[0];

        for (int i : array)
        {
            if (i < min)
            {
                min = i;
            }
        }

        return min;
    }

    public static int maximum(int[] array)
    {
        int max = array[0];

        for (int i : array)
        {
            if (i > max)
            {
                max = i;
            }
        }

        return max;
    }

    public static double average(int[] array)
    {
        int sum = 0;

        for (int i : array)
        {
            sum += i;
        }

        return ((double) sum / array.length);
    }


}
