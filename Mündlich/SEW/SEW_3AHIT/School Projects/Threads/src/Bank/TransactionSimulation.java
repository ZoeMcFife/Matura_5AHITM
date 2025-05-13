package Bank;

import java.util.Comparator;
import java.util.Random;

public class TransactionSimulation
{
    public static void main(String[] args)
    {
        Bank bank = createBank();

        for (BankAccount a : bank.getBankAccounts())
        {
            final Thread thread = new Thread(new Runnable()
            {
                @Override
                public void run()
                {
                    while (true)
                    {
                       synchronized (bank)
                       {
                           int a1 = -1;
                           int a2 = -1;

                           do
                           {
                               a1 = pickRandomId(bank.getBankAccounts().size());
                               a2 = pickRandomId(bank.getBankAccounts().size());
                           }
                           while (a1 == a2);

                           bank.transfer(bank.getBankAccounts().get(a1), bank.getBankAccounts().get(a2), new Random().nextInt(1, 5000));
                       }
                    }
                }
            });

            thread.start();
        }
    }

    public static int pickRandomId(int totalAccounts)
    {
        return new Random().nextInt(totalAccounts);
    }

    public static Bank createBank()
    {
        BankAccount a1 = new BankAccount("Pie");
        BankAccount a2 = new BankAccount("Kiri");
        BankAccount a3 = new BankAccount("Alex");
        BankAccount a4 = new BankAccount("Microwave");
        BankAccount a5 = new BankAccount("Luner");
        BankAccount a6 = new BankAccount("Subi");
        BankAccount a7 = new BankAccount("David Braben");
        BankAccount a8 = new BankAccount("Aisling Duval");
        BankAccount a9 = new BankAccount("Zoe McFife");
        BankAccount aA = new BankAccount("Zargothrax");

        return new Bank(a1, a2, a3, a4, a5, a6, a7, a8, a9, aA);
    }
}
