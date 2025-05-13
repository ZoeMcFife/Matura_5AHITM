package Inheritance;

public class Cat extends Animal
{
    @Override
    public void speak()
    {
        System.out.println("meow");
    }

    @Override
    public boolean likes(String food)
    {
        return food.equals("milk");
    }

    @Override
    public void getAngry()
    {
        System.out.println("hiss");
    }
}
