package Account;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AccountTest
{
    @Test
    void GetSetAccountOwnerTest()
    {
        Account account = new Account("Test", 10)
        {
            @Override
            public void withdraw(int cents)
            {
                //
            }

            @Override
            public void deposit(int cents)
            {
                //
            }
        };

        Assertions.assertEquals("Test", account.getAccountOwner());
    }

    @Test
    void GetSetBalanceTest()
    {
        Account account = new Account("Test", 10)
        {
            @Override
            public void withdraw(int cents)
            {
                //
            }

            @Override
            public void deposit(int cents)
            {
                //
            }
        };

        Assertions.assertEquals(10, account.getBalance());
    }


    @Test
    void GetSetAccountIDTest()
    {
        Account.resetAccountIDs();

        Account account = new Account("Test", 0)
        {
            @Override
            public void withdraw(int cents)
            {
                //
            }

            @Override
            public void deposit(int cents)
            {
                //
            }
        };

        Account account2 = new Account("Test", 0)
        {
            @Override
            public void withdraw(int cents)
            {
                //
            }

            @Override
            public void deposit(int cents)
            {
                //
            }
        };

        Account account3 = new Account("Test", 0)
        {
            @Override
            public void withdraw(int cents)
            {
                //
            }

            @Override
            public void deposit(int cents)
            {
                //
            }
        };

        Assertions.assertEquals(2, account3.getAccountID());
    }
    @Test
    void toStringTest()
    {
        Account account = new Account("Test", 120)
        {
            @Override
            public void withdraw(int cents)
            {
                //
            }

            @Override
            public void deposit(int cents)
            {
                //
            }
        };

        Assertions.assertEquals("Account Details: Owner: Test Balance: 1.2€", account.toString());
    }
}
