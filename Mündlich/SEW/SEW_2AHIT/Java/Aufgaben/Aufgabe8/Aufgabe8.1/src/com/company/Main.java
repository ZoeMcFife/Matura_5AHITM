package com.company;

import java.util.ArrayList;

public class Main
{
    public static void main(String[] args)
    {
        Class k1 = new Class("2AHIT");
        Student s1, s2, s3;
        s1 = new Student("Anna","Mayer");
        s2 = new Student("Markus","Schuster");
        s3 = new Student();
        k1.addStudent(s1);
        k1.addStudent(s2);
        k1.addStudent(s3);

        Class k2=new Class("2BHIT");
        k2.addStudent(new Student("Sabine","Müller"));
        k2.addStudent(new Student("Markus","Reiterer"));
        k2.addStudent(new Student("Franz","Schmid"));

        ArrayList<Class> classes = new ArrayList<Class>();
        classes.add(k1);
        classes.add(k2);

        for (Class k: classes)
        {
            System.out.println(k);
        }
        System.out.println("Total Students: " + Class.studentCount);

        k2.setDescription("2CHIT");
        k2.removeStudent(0);
        System.out.println(k2.getDescription());
        for (Student s : k2.getStudents() )
        {
            System.out.println(s);
        }
        System.out.println("Total students: " + Class.studentCount);
    }
}
