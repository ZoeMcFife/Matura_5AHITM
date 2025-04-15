package Thiefs;

public class ThiefTest
{
    public static void main(String[] args)
    {
        ThiefChief chief = new ThiefChief("Sussus Amongus");
        ThiefCarDriver carDriver = new ThiefCarDriver("Joe");

        Thread t1 = new Thread(chief);
        Thread t2 = new Thread(carDriver);

        t2.start();
        t1.start();
    }
}
