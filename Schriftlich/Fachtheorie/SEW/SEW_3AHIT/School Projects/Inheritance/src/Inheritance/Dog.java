package Inheritance;

public class Dog extends Animal
{
    public boolean likes(String food)
    {
        return food.equals("bones");
    }

    public void speak()
    {
        System.out.println("woof");
    }

    public void getAngry()
    {
        System.out.println("bite");
    }
}
