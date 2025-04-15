package CC;

public class Point
{
    private double x;
    private double y;

    Point(double x, double y)
    {
        this.x = x;
        this.y = y;
    }

    Point(Point point)
    {
        this.setPoint(point);
    }

    public void setX(double x)
    {
        this.x = x;
    }

    public double getX()
    {
        return x;
    }

    public double getY()
    {
        return y;
    }

    public void setY(double y)
    {
        this.y = y;
    }

    public Point translate(double dx, double dy)
    {
        return new Point(this.x + dx, this.y + dy);
    }

    public void add(Point point)
    {
        this.x = point.x;
        this.y = point.y;
    }

    public Point rotateVector(double angle)
    {
        angle = Math.toRadians(angle);

        Point newVector = new Point(0, 0);

        newVector.x = Math.cos(angle) * this.x - Math.sin(angle) * this.y;
        newVector.y = Math.sin(angle) * this.x + Math.cos(angle) * this.y;

        return newVector;
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
