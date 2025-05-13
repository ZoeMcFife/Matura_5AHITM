package Compare;

import java.awt.*;
import java.util.Arrays;

public class SortingPointsCenter
{
    public static void comparing()
    {
        java.awt.Point[] points = {
                new Point(9,3),
                new Point(3,4),
                new Point(4,3),
                new Point(1,3)
        };

        Arrays.sort(points, new PointComparator());

        System.out.println(Arrays.toString(points));
    }
}
