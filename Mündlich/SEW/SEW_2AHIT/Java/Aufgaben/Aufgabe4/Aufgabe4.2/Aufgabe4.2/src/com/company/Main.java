package com.company;

import javax.swing.*;

public class Main
{
    public static void main(String[] args)
    {
        Turtle turtle = new Turtle();

        turtle.move(1);
        turtle.turn(45);
        System.out.println(turtle);

        turtle.move(20);

        System.out.println(turtle);

        Turtle t3 =new Turtle(300,400,90);


        t3.move(100);
        System.out.println(t3);
        t3.turnLeft();
        System.out.println(t3);
        t3.move(100);
        System.out.println(t3);
    }
}
