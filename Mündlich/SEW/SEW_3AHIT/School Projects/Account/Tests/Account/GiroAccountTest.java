package Account;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class GiroAccountTest
{
    @Test
    void GiroAccountTest()
    {
        GiroAccount giroAccount = new GiroAccount("Owner", 500, 20);

        Assertions.assertEquals("Owner", giroAccount.getAccountOwner());
        Assertions.assertEquals(500, giroAccount.getBalance());
        Assertions.assertEquals(20, giroAccount.getOverdraftLimit());
    }

    @Test
    void GiroAccountTest2()
    {
        Exception exception = assertThrows(IllegalArgumentException.class, () ->
        {
            GiroAccount giroAccount = new GiroAccount("Owner", 500, -20);
        });

        String expectedMessage = "Overdraft limit cannot be below 0.";
        String actualMessage = exception.getMessage();
        Assertions.assertTrue(actualMessage.contains(expectedMessage));
    }

    @Test
    void withdrawTest()
    {
        GiroAccount giroAccount = new GiroAccount("Owner", 500, 20);

        giroAccount.withdraw(20);

        assertEquals(480, giroAccount.getBalance());
    }

    @Test
    void withdrawTest2()
    {
        GiroAccount giroAccount = new GiroAccount("Owner", 500, 20);

        giroAccount.withdraw(-20);

        assertEquals(500, giroAccount.getBalance());
    }

    @Test
    void withdrawTest3()
    {
        GiroAccount giroAccount = new GiroAccount("Owner", 500, 20);

        giroAccount.withdraw(550);

        assertEquals(500, giroAccount.getBalance());
    }

    @Test
    void withdrawTest4()
    {
        GiroAccount giroAccount = new GiroAccount("Owner", 500, 20);

        giroAccount.withdraw(515);

        assertEquals(-15, giroAccount.getBalance());
    }

    @Test
    void depositTest()
    {
        GiroAccount giroAccount = new GiroAccount("Owner", 500, 20);

        giroAccount.deposit(20);

        Assertions.assertEquals(520, giroAccount.getBalance());
    }

    @Test
    void depositTest2()
    {
        GiroAccount giroAccount = new GiroAccount("Owner", 500, 20);

        giroAccount.deposit(-20);

        Assertions.assertEquals(500, giroAccount.getBalance());
    }
}
