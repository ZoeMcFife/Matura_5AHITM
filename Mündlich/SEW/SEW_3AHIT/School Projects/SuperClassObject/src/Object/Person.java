package Object;

import java.util.Objects;

public class Person
{
    public long id;
    public int age;
    public double income;
    public boolean isLord;
    public String name;

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Person person = (Person) o;
        return id == person.id && age == person.age && Double.compare(person.income, income) == 0 && isLord == person.isLord && Objects.equals(name, person.name);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(id, age, income, isLord, name);
    }


}








