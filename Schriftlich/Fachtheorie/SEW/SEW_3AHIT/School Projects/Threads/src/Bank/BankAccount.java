package Bank;

public class BankAccount
{
    private int bid;
    private String name;
    private long value;

    public static int lastID;

    public BankAccount(String name)
    {
        setBid(lastID + 1);
        lastID++;
        setName(name);
        setValue(10000);
    }

    public void addFunds(long value)
    {
        setValue(getValue() + value);
    }

    public int removeFunds(long value)
    {
        if (getValue() - value < 0)
            return -1;

        setValue(getValue() - value);

        return 0;
    }

    private void setBid(int bid)
    {
        this.bid = bid;
    }

    public int getBid()
    {
        return bid;
    }

    private void setName(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return name;
    }

    public long getValue()
    {
        return value;
    }

    private void setValue(long value)
    {
        this.value = value;
    }
}
