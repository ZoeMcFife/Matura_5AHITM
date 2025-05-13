package com.company;

import java.util.ArrayList;

public class Class
{
    String description;
    ArrayList<Student> students;

    static int studentCount = 0;

    Class(String description)
    {
        this.description = description;
        students = new ArrayList<Student>();
    }

    public void addStudent(Student student)
    {
        students.add(student);
        studentCount++;
    }

    public void setDescription(String description)
    {
        this.description = description;
    }

    public String getDescription()
    {
        return description;
    }

    public ArrayList<Student> getStudents()
    {
        return students;
    }

    public void removeStudent(int index)
    {
        students.remove(index);
        studentCount--;
    }

    @Override
    public String toString()
    {
        String output = "Class: (";

        for (int i = 0; i < students.size(); i++)
        {
            output += students.get(i).toString();

            if (i != students.size() - 1)
                output += ",";
        }

        return output + ")";
    }
}
