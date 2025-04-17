package Account;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertThrows;

public class CreditAccountTest
{
    @Test
    void CreditAccountTest()
    {
        CreditAccount creditAccount = new CreditAccount("Owner", 500);

        Assertions.assertEquals("Owner", creditAccount.getAccountOwner());
        Assertions.assertEquals(-500, creditAccount.getBalance());
    }

    @Test
    void CreditAccountTest2()
    {
        Exception exception = assertThrows(IllegalArgumentException.class, () ->
        {
            CreditAccount creditAccount = new CreditAccount("Owner", -50);
        });

        String expectedMessage = "Starting credit cannot be negative.";
        String actualMessage = exception.getMessage();

        Assertions.assertTrue(actualMessage.contains(expectedMessage));
    }

    @Test
    void depositTest()
    {
        CreditAccount creditAccount = new CreditAccount("Owner", 500);

        creditAccount.deposit(50);

        Assertions.assertEquals(-450, creditAccount.getBalance());
    }

    @Test
    void depositTest2()
    {
        CreditAccount creditAccount = new CreditAccount("Owner", 40);

        creditAccount.deposit(50);

        Assertions.assertEquals(-40, creditAccount.getBalance());
    }

    @Test
    void depositTest3()
    {
        CreditAccount creditAccount = new CreditAccount("Owner", 40);

        creditAccount.deposit(-50);

        Assertions.assertEquals(-40, creditAccount.getBalance());
    }
}
