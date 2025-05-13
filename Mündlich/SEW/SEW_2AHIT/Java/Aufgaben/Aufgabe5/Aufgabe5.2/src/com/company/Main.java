package com.company;

public class Main
{
    public static void main(String[] args)
    {
        EuroBanknote a = new EuroBanknote("Z60162200226", 1);
        EuroBanknote b = new EuroBanknote("NA3408351535", 2);

        System.out.println(a.getCheckNumber());
        System.out.println(a.getNzbNumber());
        System.out.println(a.isValid());
        System.out.println(a);

        System.out.println(b.getCheckNumber());
        System.out.println(b.getNzbNumber());
        System.out.println(b.isValid());
        System.out.println(b);
    }
}
