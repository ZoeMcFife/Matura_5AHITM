package Inheritance;

public abstract class Animal
{
    public boolean likes(String food)
    {
        return false;
    }

    public void getAngry()
    {
        speak();
    }

    public abstract void speak();

}
