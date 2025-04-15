package Rectangle;

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

    public void setPoint(Point point)
    {
        this.x = point.getX();
        this.y = point.getY();
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return x == point.x && y == point.y;
    }

    public boolean isGreater(Point point)
    {
        if (this.getX() < point.getX() && this.getY() < point.getY())
            return true;

        return false;
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
