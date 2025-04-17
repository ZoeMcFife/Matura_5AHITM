package Arrays;

import java.util.ArrayList;

public class AfraidOfFive
{
    public static int[] fiveAtLast(int[] array) throws IllegalArgumentException
    {
        if (array == null)
        {
            throw new IllegalArgumentException("Array must not be null!");
        }

        ArrayList<Integer> sortedList = new ArrayList<Integer>();
        int i = 0;

        for (int a : array)
        {
            if (Integer.toString(a).contains("5"))
            {
                sortedList.add(a);
            }
            else
            {
                sortedList.add(i, a);
                i++;
            }
        }

        for (int j = 0; j < array.length; j++)
        {
            array[j] = sortedList.get(j);
        }

        return array;
    }
}
