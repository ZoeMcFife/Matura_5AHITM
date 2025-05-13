package com.company;

public class Main
{
    public static void main(String[] args)
    {
        classA a = new classA(2);
        classB b = new classB(1, 3);

        classA[] arrayA = new classA[2];

        arrayA[0] = a;
        arrayA[1] = b;

        System.out.println(arrayA[1].a);
    }
}
