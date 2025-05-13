package Thiefs;

public class ThiefDeadlockTest
{
    public static void main(String[] args)
    {
        final ThiefChief joe = new ThiefChief("Joe");
        final ThiefCarDriver biden = new ThiefCarDriver("Biden");

        final Thread bidenBLAST = new Thread(() -> biden.visiting(joe));
        final Thread joeThread = new Thread(() -> joe.visiting(biden));

        bidenBLAST.start();
        joeThread.start();
    }
}
