package com.company;

public class Main
{

    public static void main(String[] args)
    {
        Point point = new Point(1, 0);
        Point anotherPoint = new Point(2,0);

        point.move(0, 2);

        System.out.println("Distance to 0: " + point.distance());
        System.out.println("Distance to another Point: " + point.distance(anotherPoint));
        System.out.println(point);
    }
}
