package com.company;

public class Main
{
    public static void main(String[] args)
    {
        Rectangle r1 = new Rectangle(3, 4);
        Rectangle r2 = new Rectangle(1, 2);

        Square s1 = new Square(42);
        Square s2 = new Square(23);
        Square s3 = new Square(34);

        Square[] sArr = new Square[3];
        sArr[0] = s1;
        sArr[1] = s2;
        sArr[2] = s3;

        for (Square sq : sArr)
        {
            System.out.println(sq);
        }

        System.out.println("-----------------------------------");

        Rectangle[] rArr = new Rectangle[5];
        rArr[0] = s1;
        rArr[1] = s2;
        rArr[2] = s3;
        rArr[3] = r1;
        rArr[4] = r2;

        for (Rectangle r : rArr)
        {
            System.out.println(r);
        }
    }
}
