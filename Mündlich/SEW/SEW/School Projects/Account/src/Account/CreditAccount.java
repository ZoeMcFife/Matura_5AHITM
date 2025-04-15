package Account;

public class CreditAccount extends Account
{
    CreditAccount(String accountOwner, int startingCredit) throws IllegalArgumentException
    {
        super(accountOwner, 0);

        if (startingCredit <= 0)
            throw new IllegalArgumentException("Starting credit cannot be negative.");
        else
            setBalance(-startingCredit);
    }

    @Override
    public void deposit(int cents)
    {
        if (this.balance + cents > 0)
            System.out.println("Cannot deposit that amount.");
        else if (cents < 0)
            System.out.println("Cannot deposit negative amounts.");
        else
            this.balance += cents;
    }

    @Override
    public void withdraw(int cents)
    {
        System.out.println("Cannot withdraw from credit account.");
    }
}
