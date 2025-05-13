package Thiefs;

public class ThiefCarDriver extends Thief implements Runnable
{
    ThiefCarDriver(String name)
    {
        super(name);
    }

    @Override
    public void letsDoABankRobbery(Thief thief)
    {
        System.out.printf("%s: Let's go!\n", thief.getName());

        try
        {
            System.out.printf("%s: Slowly starting the car ... Don't hurry ...\n", this.getName());

            Thread.sleep(5000);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        System.out.printf("%s: The car started ... We can go!\n", this.getName());
    }


    @Override
    public void run()
    {
        letsDoABankRobbery(this);
    }
}
