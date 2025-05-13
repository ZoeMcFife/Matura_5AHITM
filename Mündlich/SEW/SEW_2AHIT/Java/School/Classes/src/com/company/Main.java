package com.company;

public class Main
{

    public static void main(String[] args)
    {
    	Point point1 = new Point(4, 3);

        point1.print();
        System.out.println(point1);

        Point[] points = new Point[10];

        for (Point point : points)
        {
            point = new Point();
        }
    }
}
