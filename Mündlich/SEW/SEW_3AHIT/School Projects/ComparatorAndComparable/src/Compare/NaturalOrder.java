package Compare;

import java.awt.*;
import java.util.Arrays;

public class NaturalOrder
{
    public static void naturalOrderOrNot()
    {
        String[] strings = {"D", "B", "C"};
        Arrays.sort(strings); // Sorts the Strings alphabetically

        java.awt.Point[] points = {
                new Point(9,3),
                new Point(3,4),
                new Point(4,3),
                new Point(1,3)
        };

        //Arrays.sort(points); // Throws error --> class java.awt.Point cannot be cast to class java.lang.Comparable

        System.out.println(Arrays.toString(strings));
        System.out.println(Arrays.toString(points));
    }
}
