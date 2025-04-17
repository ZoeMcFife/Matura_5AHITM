package Inheritance;

public class Bird extends Animal
{
    public boolean likes(String food)
    {
        return food.equals("corn");
    }

    public void speak()
    {
        System.out.println("beep");
    }
}
