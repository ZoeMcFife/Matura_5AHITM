package Shoes;

public class Dog extends Animal
{
    Dog(String name)
    {
        this.name = name;
    }

    @Override
    public String toString()
    {
        return "Dog{" +
                "name='" + name + '\'' +
                '}';
    }
}
