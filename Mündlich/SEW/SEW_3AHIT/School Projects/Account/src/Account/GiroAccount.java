package Account;

public class GiroAccount extends Account
{
    private int overdraftLimit;

    GiroAccount(String accountOwner, int startingBalance, int overdraftLimit)
    {
        super(accountOwner, startingBalance);
        setOverdraftLimit(overdraftLimit);
    }

    @Override
    public void withdraw(int cents)
    {
        if ((this.balance - cents) < -overdraftLimit)
            System.out.println("Overdraft limit exceeded.");
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

    public void setOverdraftLimit(int overdraftLimit) throws IllegalArgumentException
    {
        if (overdraftLimit < 0)
            throw new IllegalArgumentException("Overdraft limit cannot be below 0.");

        this.overdraftLimit = overdraftLimit;
    }

    public int getOverdraftLimit()
    {
        return overdraftLimit;
    }
}
