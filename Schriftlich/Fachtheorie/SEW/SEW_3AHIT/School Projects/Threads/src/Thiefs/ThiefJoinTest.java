package Thiefs;

public class ThiefJoinTest
{
    public static void main(String[] args)
    {
        final ThiefChief thiefChief = new ThiefChief("Joe");
        final ThiefCarDriver thiefCarDriver = new ThiefCarDriver("Biden");

        final Thread driverThread = new Thread(() -> thiefCarDriver.letsDoABankRobbery(thiefChief));

        final Thread chiefThread = new Thread(() ->
        {
            try
            {
                driverThread.join(); //chiefThread should wait for the driverThread
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        });

        chiefThread.start();
        driverThread.start();


    }
}
