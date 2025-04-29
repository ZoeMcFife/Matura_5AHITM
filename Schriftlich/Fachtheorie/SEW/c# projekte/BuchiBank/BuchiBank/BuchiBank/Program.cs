namespace BuchiBank
{
    /* 2023 Beispiel */

    internal class Program
    {
        /*
         *  Um async Methoden in Main zu executen muss Main zu !! async Task !! konvertiert werden 
         */

        static async Task Main(string[] args)
        {
            var bankAccount = new BankAccount();

            var depositer = new Depositer(bankAccount, 2);
            var withdrawer = new Withdrawer(bankAccount, 1);

            /* await Task.WhenAll();
             * 
             * wartet bis alle Tasks fertig sind
             * 
             */

            await Task.WhenAll
            (
                depositer.RunForDurationAsync(10),
                withdrawer.RunForDurationAsync(10)
            );

            BankAccount.PrintTransactions("History Ascending", bankAccount.HistoryAscending);
            BankAccount.PrintTransactions("Deposits", bankAccount.Deposits);
            BankAccount.PrintTransactions("Withdrawels", bankAccount.Withdrawels);

            Console.ReadLine();
        }
    }
}
