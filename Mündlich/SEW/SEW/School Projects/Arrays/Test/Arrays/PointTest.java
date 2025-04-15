package Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class PointTest
{
    @Test
    void PointTest()
    {
        Point p = new Point();

        Assertions.assertEquals(0, p.getX());
        Assertions.assertEquals(0, p.getY());
    }

    @Test
    void PointTest2()
    {
        Point p = new Point(1, 2);

        Assertions.assertEquals(1, p.getX());
        Assertions.assertEquals(2, p.getY());
    }

    @Test
    void PointTest3()
    {
        Point p1 = new Point(1, 2);
        Point p2 = new Point(p1);

        Assertions.assertEquals(p1, p2);
    }

    @Test
    void PointTest4()
    {
        Exception exception = Assertions.assertThrows(IllegalArgumentException.class, () ->
        {
            Point p = new Point(null);
        });

        String expected = "Point must not be null!";
        String actual = exception.getMessage();

        Assertions.assertTrue(actual.contains(expected));
    }

    @Test
    void shortestDistanceTest()
    {
        Point[] points = { new Point (10, 20), new Point (12 ,2), new Point (44 , 4) };

        Assertions.assertEquals(Math.sqrt(Math.pow(12,2) + Math.pow(2,2)), Point.shortestDistance(points, points.length));
    }

    @Test
    void closestPointTest()
    {
        Point[] points = { new Point (10, 20), new Point (12 ,2), new Point (44 , 4) };

        Assertions.assertEquals(new Point(12, 2), Point.closestPoint(points));

    }
}
