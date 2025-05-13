package Rectangle;

import java.util.ArrayList;
import java.util.List;

public class Rectangle
{
    private Point cornerA;
    private Point cornerB;

    Rectangle()
    {
        setCornerA(new Point(0, 0));
        setCornerB(new Point(1, 1));
    }

    Rectangle(int ax, int ay, int bx, int by)
    {
        this(new Point(ax, ay), new Point(bx, by));
    }

    Rectangle(Point cornerA, Point cornerB)
    {
        if (cornerA.isGreater(cornerB))
        {
            setCornerA(cornerA);
            setCornerB(cornerB);
        }
        else if(cornerA.getX() > cornerB.getX() && cornerA.getY() < cornerB.getY())
        {
            setCornerB(cornerA.translate(0, cornerB.getY() - cornerA.getY()));
            setCornerA(cornerB.translate(0, cornerA.getY() - cornerB.getY()));
        }
        else if(cornerB.getX() > cornerA.getX() && cornerB.getY() < cornerA.getY())
        {
            setCornerA(cornerA.translate(0, cornerB.getY() - cornerA.getY()));
            setCornerB(cornerB.translate(0, cornerA.getY() - cornerB.getY()));
        }
        else
        {
            setCornerA(cornerB);
            setCornerB(cornerA);
        }
    }



    public void setCornerA(Point cornerA)
    {
        this.cornerA = cornerA;
    }

    public void setCornerB(Point cornerB)
    {
        this.cornerB = cornerB;
    }

    public static Boolean isDisjoint(Rectangle r1, Rectangle r2)
    {
        return r1.cornerA.getX() > r2.cornerB.getX() || r1.cornerB.getX() < r2.cornerA.getX() ||
                r1.cornerB.getY() < r2.cornerA.getY() || r1.cornerA.getY() > r1.cornerB.getY();
    }

    public static Boolean isSame(Rectangle r1, Rectangle r2)
    {
        return (r1.cornerA.equals(r2.cornerA) && r1.cornerB.equals(r2.cornerB));
    }

    public static Boolean isContained(Rectangle r1, Rectangle r2)
    {
        if (isSame(r1, r2))
            return false;

        return (((r1.cornerA.getX() <= r2.cornerA.getX()) && (r1.cornerA.getY() <= r2.cornerA.getY()) && (r1.cornerB.getX() >= r2.cornerB.getX()) && (r1.cornerB.getY() >= r2.cornerB.getY()))) ||
                (((r2.cornerA.getX() <= r1.cornerA.getX()) && (r2.cornerA.getY() <= r1.cornerA.getY()) && (r2.cornerB.getX() >= r1.cornerB.getX()) && (r2.cornerB.getY() >= r1.cornerB.getY())));
    }

    public static Boolean isAligned(Rectangle r1, Rectangle r2)
    {
        if (isContained(r1, r2) || isTouching(r1, r2))
            return false;

        if (r1.cornerA.getX() == r2.cornerB.getX() && r2.cornerA.getY() < r1.cornerB.getY())
            return true;
        else if (r2.cornerA.getX() == r1.cornerB.getX() && r1.cornerA.getY() < r2.cornerB.getY())
            return true;
        else if (r1.cornerA.getY() == r2.cornerB.getY() && r2.cornerA.getX() < r1.cornerB.getX())
            return true;
        else if (r2.cornerA.getY() == r1.cornerB.getY() && r1.cornerA.getX() < r2.cornerB.getX())
            return true;

        return false;
    }

    public static Boolean isTouching(Rectangle r1, Rectangle r2)
    {
        if (isSame(r1, r2) || isContained(r1, r2))
            return false;

        List<Point> r1Corners = new ArrayList<>();
        Point r1CornerC = r1.cornerA.translate(0, r1.cornerB.getY() - r1.cornerA.getY());
        Point r1CornerD = r1.cornerB.translate(0, r1.cornerA.getY() - r1.cornerB.getY());

        r1Corners.add(r1CornerC);
        r1Corners.add(r1CornerD);
        r1Corners.add(r1.cornerA);
        r1Corners.add(r1.cornerB);

        Point r2CornerC = r2.cornerA.translate(0, r2.cornerB.getY() - r2.cornerA.getY());
        Point r2CornerD = r2.cornerB.translate(0, r2.cornerA.getY() - r2.cornerB.getY());

        return  (r1Corners.contains(r2.cornerA) ||
                r1Corners.contains(r2.cornerB) ||
                r1Corners.contains(r2CornerC) ||
                r1Corners.contains(r2CornerD));
    }

    public static Boolean isIntersecting(Rectangle r1, Rectangle r2)
    {
        if (!isSame(r1, r2) && !isContained(r1,r2) && !isTouching(r1,r2) && !isAligned(r1,r2))
            return !(r1.cornerA.getX() > r2.cornerB.getX() || r1.cornerB.getX() < r2.cornerA.getX() ||
                    r1.cornerB.getY() < r2.cornerA.getY() || r1.cornerA.getY() > r1.cornerB.getY());

        return false;
    }

    @Override
    public String toString()
    {
        return "Rectangle{" +
                "cornerA=" + cornerA +
                ", cornerB=" + cornerB +
                '}';
    }
}
