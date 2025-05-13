package Shoes;

public class Cat extends Animal
{
    Cat(String name)
    {
        this.name = name;
    }

    @Override
    public String toString()
    {
        return "Cat{" +
                "name='" + name + '\'' +
                '}';
    }
}
