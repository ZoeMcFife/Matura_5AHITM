package com.company;

public class Student
{
    String name;
    String surname;

    Student()
    {
        this.name = "no";
        this.surname = "name";
    }

    Student(String name, String surname)
    {
        this.name = name;
        this.surname = surname;
    }

    @Override
    public String toString()
    {
        return this.name.substring(0,1) + "." + surname;
    }
}
