package Account;

public class SavingsAccount extends Account
{
    SavingsAccount(String accountOwner, int startingBalance) throws IllegalArgumentException
    {
        super(accountOwner, 0);

        if (startingBalance < 0)
            throw new IllegalArgumentException("Starting Balance must be higher than or equal to 0.");
        else
            setBalance(startingBalance);
    }

    @Override
    public void withdraw(int cents)
    {
        if (this.balance - cents < 0)
            System.out.println("Cannot withdraw that amount.");
        else if (cents < 0)
            System.out.println("Cannot withdraw negative amounts.");
        else
            this.balance -= cents;
    }

    @Override
    public void deposit(int cents)
    {
        if (cents < 0)
            System.out.println("Cannot deposit negative amounts.");
        else
            this.balance += cents;
    }
}
