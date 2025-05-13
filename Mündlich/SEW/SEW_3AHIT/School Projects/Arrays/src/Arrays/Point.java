package Arrays;

import java.util.Arrays;
import java.util.Objects;

public class Point
{
    private double x;
    private double y;

    Point()
    {
        new Point(0, 0);
    }

    Point(double x, double y)
    {
        setX(x);
        setY(y);
    }

    Point(Point point) throws IllegalArgumentException
    {
        if (point == null)
        {
            throw new IllegalArgumentException("Point must not be null!");
        }

        this.x = point.getX();
        this.y = point.getY();
    }

    public void setY(double y)
    {
        this.y = y;
    }

    public void setX(double x)
    {
        this.x = x;
    }

    public double getY()
    {
        return y;
    }

    public double getX()
    {
        return x;
    }

    public static double shortestDistance(Point[] points, int size)
    {
        double distances[] = new double[size];

        for (int i = 0; i < size; i++)
        {
            distances[i] = pythagoras(points[i].getX(), points[i].getY());
        }
        Arrays.sort(distances);

        return distances[0];
    }

    @Override
    public String toString()
    {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return Double.compare(point.x, x) == 0 && Double.compare(point.y, y) == 0;
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(x, y);
    }

    public static Point closestPoint(Point[] points)
    {
        double distance;
        double distanceTemp = 0;
        Point point = new Point();

        for (Point p : points)
        {
            distance = p.pythagoras(p.getX(), p.getY());

            System.out.println(distance);
            if (distance < distanceTemp)
            {
                point = new Point(p);
            }
            else
            {
                distanceTemp = distance;
            }
        }

        return point;
    }

    private static double pythagoras(double a, double b)
    {
        return Math.sqrt(Math.pow(a,2) + Math.pow(b,2));
    }
}
