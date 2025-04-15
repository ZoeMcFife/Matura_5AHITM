package Account;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class SavingsAccountTest
{
    @Test
    void SavingsAccountTest()
    {
        SavingsAccount savingsAccount = new SavingsAccount("Owner", 20);

        Assertions.assertEquals("Owner", savingsAccount.getAccountOwner());
        Assertions.assertEquals(20, savingsAccount.getBalance());
    }

    @Test
    void SavingsAccountTest2()
    {
        Exception exception = assertThrows(IllegalArgumentException.class, () ->
        {
            SavingsAccount savingsAccount = new SavingsAccount("Owner", -20);
        });

        String expectedMessage = "Starting Balance must be higher than or equal to 0.";
        String actualMessage = exception.getMessage();
        Assertions.assertTrue(actualMessage.contains(expectedMessage));
    }

    @Test
    void withdrawTest()
    {
        SavingsAccount savingsAccount = new SavingsAccount("Owner", 50);

        savingsAccount.withdraw(20);

        Assertions.assertEquals(30, savingsAccount.getBalance());
    }

    @Test
    void withdrawTest2()
    {
        SavingsAccount savingsAccount = new SavingsAccount("Owner", 50);

        savingsAccount.withdraw(500);

        Assertions.assertEquals(50, savingsAccount.getBalance());
    }

    @Test
    void withdrawTest3()
    {
        SavingsAccount savingsAccount = new SavingsAccount("Owner", 50);

        savingsAccount.withdraw(-20);

        Assertions.assertEquals(50, savingsAccount.getBalance());
    }

    @Test
    void depositTest()
    {
        SavingsAccount savingsAccount = new SavingsAccount("Owner", 50);

        savingsAccount.deposit(20);

        Assertions.assertEquals(70, savingsAccount.getBalance());
    }

    @Test
    void depositTest2()
    {
        SavingsAccount savingsAccount = new SavingsAccount("Owner", 50);

        savingsAccount.deposit(-20);

        Assertions.assertEquals(50, savingsAccount.getBalance());
    }

}
