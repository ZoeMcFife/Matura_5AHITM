package snake.snake.snake;

import java.util.LinkedList;
import java.util.Objects;
import java.util.Random;

public class Point
{
    private int x;
    private int y;

    Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    Point(Point point)
    {
        this.setPoint(point);
    }

    public void setX(int x)
    {
        this.x = x;
    }

    public int getX()
    {
        return x;
    }

    public int getY()
    {
        return y;
    }

    public void setY(int y)
    {
        this.y = y;
    }

    public Point translate(int dx, int dy)
    {
        return new Point(this.x + dx, this.y + dy);
    }
    public void translateThis(int dx, int dy)
    {
        this.x += dx;
        this.y += dy;
    }

    public void setPoint(Point point)
    {
        this.x = point.getX();
        this.y = point.getY();
    }

    public static Point getRandomPoint(int xMax, int yMax, LinkedList<Point> exclude)
    {
        Random random = new Random();
        Point point;

        do
        {
            point = new Point(random.nextInt(xMax), random.nextInt(yMax));
        }
        while (exclude.contains(point));

        return point;
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return x == point.x && y == point.y;
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(x, y);
    }

    @Override
    public String toString()
    {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}
