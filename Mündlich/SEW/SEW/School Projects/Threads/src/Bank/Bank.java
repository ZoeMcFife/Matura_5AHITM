package Bank;

import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Bank
{
    private List<BankAccount> bankAccounts;
    public long transactions = 0;

    public Bank(BankAccount... bankAccounts)
    {
        this.bankAccounts = new ArrayList<>();
        this.bankAccounts.addAll(Arrays.stream(bankAccounts).toList());
    }

    public List<BankAccount> getBankAccounts()
    {
        return bankAccounts;
    }

    public long getTotalWealth()
    {
        long wealth = 0;

        for (BankAccount bankAccount : this.bankAccounts)
        {
            wealth += bankAccount.getValue();
        }

        return wealth;
    }

    public void transfer(BankAccount from, BankAccount to, long amount)
    {
        if (from.removeFunds(amount) == -1)
        {
            try
            {
                Thread.sleep(20);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }

            return;
        }

        to.addFunds(amount);

        //System.out.println(from.getName() + " transferred " + amount + "$ to " + to.getName() + ". " + from.getName() + " now has " + from.getValue() + "$.");

        transactions++;

        if (transactions % 500 == 0)
        {
            System.out.println("Transactions: " + this.transactions + " Total Wealth: " + this.getTotalWealth());
        }
    }
}
