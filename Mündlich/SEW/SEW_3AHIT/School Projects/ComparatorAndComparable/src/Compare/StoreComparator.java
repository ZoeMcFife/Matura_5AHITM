package Compare;

import java.awt.*;
import java.util.Comparator;

public class StoreComparator implements Comparator<Store>
{
    Point center;

    StoreComparator(Point center)
    {
        this.center = center;
    }

    @Override
    public int compare(Store o1, Store o2)
    {
        Double distance1 = calculateDistanceToCenter(o1);
        Double distance2 = calculateDistanceToCenter(o2);

        return distance1.compareTo(distance2);
    }

    private double calculateDistanceToCenter(Store store)
    {
        return Math.sqrt(Math.pow(store.location.x - center.x, 2) + Math.pow(store.location.y - center.y, 2));
    }
}
