package Account;

public abstract class Account
{
    private final int accountID = setAccountID();
    protected String accountOwner;
    protected int balance;

    private static int nextID = 0;

    Account(String accountOwner, int startingBalance)
    {
        setAccountOwner(accountOwner);
        setBalance(startingBalance);
        this.nextID++;
    }

    public abstract void withdraw(int cents);
    public abstract void deposit(int cents);

    public int getAccountID()
    {
        return accountID;
    }

    private int setAccountID()
    {
        return this.nextID;
    }

    public String getAccountOwner()
    {
        return accountOwner;
    }

    protected void setAccountOwner(String accountOwner)
    {
        this.accountOwner = accountOwner;
    }

    public int getBalance()
    {
        return balance;
    }

    protected void setBalance(int balance)
    {
        this.balance = balance;
    }

    public static void resetAccountIDs()
    {
        nextID = 0;
    }

    @Override
    public String toString()
    {
        return "Account Details: Owner: " + this.accountOwner + " Balance: " + this.balance / 100.0 + "€";
    }
}
