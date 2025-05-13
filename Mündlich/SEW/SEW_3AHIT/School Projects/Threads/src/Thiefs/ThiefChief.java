package Thiefs;

public class ThiefChief extends Thief implements Runnable
{
    ThiefChief(String name)
    {
        super(name);
    }

    @Override
    public void letsDoABankRobbery(Thief thief)
    {
        System.out.printf("%s: I am the chief - let's go!\n", this.getName());
    }

    @Override
    public void run()
    {
        this.letsDoABankRobbery(this);
    }

}
