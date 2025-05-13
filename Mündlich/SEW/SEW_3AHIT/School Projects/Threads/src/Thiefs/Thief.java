package Thiefs;

public abstract class Thief
{
    private String name;

    Thief(String name)
    {
        setName(name);
    }

    public abstract void letsDoABankRobbery(Thief thief);

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public synchronized void visiting(Thief thief)
    {
        try
        {
            Thread.sleep(50);
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        System.out.printf("%s: We have met here in my house.\n", this.getName());
        thief.getTheVisit(this);
    }

    public synchronized void getTheVisit(Thief thief)
    {
        System.out.printf("%s: We have met here in my house.\n", this.getName());
    }

    public void letsGoIntoTheStore(Store store)
    {
        System.out.printf("%s: I will be the first!\n", this.getName());

        synchronized (store)
        {
            System.out.printf("%s: I have something to eat YUm!\n", this.getName());
        }
    }
}
