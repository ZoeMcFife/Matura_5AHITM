package Compare;

import java.awt.*;
import java.util.Comparator;

public class PointComparator implements Comparator<Point>
{
    @Override
    public int compare(Point o1, Point o2)
    {
        Double distance1 = calculateDistanceToCenter(o1);
        Double distance2 = calculateDistanceToCenter(o2);

        return distance1.compareTo(distance2);
    }

    private double calculateDistanceToCenter(Point point)
    {
        return Math.sqrt(point.x * point.x + point.y * point.y);
    }
}
