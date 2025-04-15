package Kobold;

public class TestType<T>
{
    public T a;

    TestType(T a)
    {
        this.a = a;
    }

    public void print()
    {
        System.out.println("a is a " + a.getClass() + ".");
    }
}
