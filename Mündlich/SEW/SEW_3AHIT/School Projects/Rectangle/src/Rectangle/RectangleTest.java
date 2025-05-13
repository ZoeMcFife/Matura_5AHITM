package Rectangle;

import java.awt.*;

public class RectangleTest
{
    public static void main(String[] args)
    {
        Rectangle r1 = new Rectangle(2,2,7,5);
        Rectangle r2 = new Rectangle(3, 4, 0, 6);

        System.out.println("Intersecting ");
        System.out.println("Disjoint     " + testDisjoint(r1, r2, false));
        System.out.println("Same         " + testSame(r1, r2, false));
        System.out.println("Contained    " + testContained(r1, r2, false));
        System.out.println("Aligned      " + testAligned(r1, r2, false));
        System.out.println("Touching     " + testTouching(r1, r2, false));
        System.out.println("Intersecting " + testIntersecting(r1, r2, true));

        System.out.println("");

        r1 = new Rectangle(3,2,8,5);
        r2 = new Rectangle(3, 4, 0, 6);

        System.out.println("Aligned");
        System.out.println("Disjoint     " + testDisjoint(r1, r2, false));
        System.out.println("Same         " + testSame(r1, r2, false));
        System.out.println("Contained    " + testContained(r1, r2, false));
        System.out.println("Aligned      " + testAligned(r1, r2, true));
        System.out.println("Touching     " + testTouching(r1, r2, false));
        System.out.println("Intersecting " + testIntersecting(r1, r2, false));

        System.out.println("");

        r1 = new Rectangle(2,3, 7,6);
        r2 = new Rectangle(1, 1, 4, 3);

        System.out.println("Aligned");
        System.out.println("Disjoint     " + testDisjoint(r1, r2, false));
        System.out.println("Same         " + testSame(r1, r2, false));
        System.out.println("Contained    " + testContained(r1, r2, false));
        System.out.println("Aligned      " + testAligned(r1, r2, true));
        System.out.println("Touching     " + testTouching(r1, r2, false));
        System.out.println("Intersecting " + testIntersecting(r1, r2, false));

        System.out.println("");

        r1 = new Rectangle(4,2,9,5);
        r2 = new Rectangle(3, 4, 0, 6);

        System.out.println("Disjoint");
        System.out.println("Disjoint     " + testDisjoint(r1, r2, true));
        System.out.println("Same         " + testSame(r1, r2, false));
        System.out.println("Contained    " + testContained(r1, r2, false));
        System.out.println("Aligned      " + testAligned(r1, r2, false));
        System.out.println("Touching     " + testTouching(r1, r2, false));
        System.out.println("Intersecting " + testIntersecting(r1, r2, false));

        System.out.println("");

        r1 = new Rectangle(2,2,4,4);
        r2 = new Rectangle(2, 2, 4, 4);

        System.out.println("Same");
        System.out.println("Disjoint     " + testDisjoint(r1, r2, false));
        System.out.println("Same         " + testSame(r1, r2, true));
        System.out.println("Contained    " + testContained(r1, r2, false));
        System.out.println("Aligned      " + testAligned(r1, r2, false));
        System.out.println("Touching     " + testTouching(r1, r2, false));
        System.out.println("Intersecting " + testIntersecting(r1, r2, false));

        System.out.println("");

        r1 = new Rectangle(2,2,4,4);
        r2 = new Rectangle(4,4, 5, 5);

        System.out.println("Touching");
        System.out.println("Disjoint     " + testDisjoint(r1, r2, false));
        System.out.println("Same         " + testSame(r1, r2, false));
        System.out.println("Contained    " + testContained(r1, r2, false));
        System.out.println("Aligned      " + testAligned(r1, r2, false));
        System.out.println("Touching     " + testTouching(r1, r2, true));
        System.out.println("Intersecting " + testIntersecting(r1, r2, false));

        System.out.println("");

        r1 = new Rectangle(2,2,6,6);
        r2 = new Rectangle(4, 3, 5, 5);

        System.out.println("Contained");
        System.out.println("Disjoint     " + testDisjoint(r1, r2, false));
        System.out.println("Same         " + testSame(r1, r2, false));
        System.out.println("Contained    " + testContained(r1, r2, true));
        System.out.println("Aligned      " + testAligned(r1, r2, false));
        System.out.println("Touching     " + testTouching(r1, r2, false));
        System.out.println("Intersecting " + testIntersecting(r1, r2, false));

        System.out.println("");

        r1 = new Rectangle(4,6,1,4);
        r2 = new Rectangle(1, 6, 9, 1);

        System.out.println("Contained");
        System.out.println("Disjoint     " + testDisjoint(r1, r2, false));
        System.out.println("Same         " + testSame(r1, r2, false));
        System.out.println("Contained    " + testContained(r1, r2, true));
        System.out.println("Aligned      " + testAligned(r1, r2, false));
        System.out.println("Touching     " + testTouching(r1, r2, false));
        System.out.println("Intersecting " + testIntersecting(r1, r2, false));

    }

    public static String testDisjoint(Rectangle r1, Rectangle r2, boolean expectedResult)
    {
        return Rectangle.isDisjoint(r1, r2) == expectedResult ? "Passed" : "Failed";
    }

    public static String testSame(Rectangle r1, Rectangle r2, boolean expectedResult)
    {
        return Rectangle.isSame(r1, r2) == expectedResult ? "Passed" : "Failed";
    }

    public static String testContained(Rectangle r1, Rectangle r2, boolean expectedResult)
    {
        return Rectangle.isContained(r1, r2) == expectedResult ? "Passed" : "Failed";
    }

    public static String testAligned(Rectangle r1, Rectangle r2, boolean expectedResult)
    {
        return Rectangle.isAligned(r1, r2) == expectedResult ? "Passed" : "Failed";
    }

    public static String testTouching(Rectangle r1, Rectangle r2, boolean expectedResult)
    {
        return Rectangle.isTouching(r1, r2) == expectedResult ? "Passed" : "Failed";
    }

    public static String testIntersecting(Rectangle r1, Rectangle r2, boolean expectedResult)
    {
        return Rectangle.isIntersecting(r1, r2) == expectedResult ? "Passed" : "Failed";
    }
}
