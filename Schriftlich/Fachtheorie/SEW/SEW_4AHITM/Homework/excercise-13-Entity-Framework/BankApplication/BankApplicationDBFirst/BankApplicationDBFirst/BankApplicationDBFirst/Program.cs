using static System.Runtime.InteropServices.JavaScript.JSType;

namespace BankApplicationDBFirst
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Testing();
        }

        static void Testing()
        {
            using (var context = new BankDbContext())
            {
                var michealStevens = (from p in context.Persons where p.FirstName == "Micheal" select p).FirstOrDefault();

                Console.WriteLine(michealStevens.FirstName);

                var michealsAccount = michealStevens.BankAccounts.FirstOrDefault();

                Console.WriteLine(michealsAccount.Balance);

                var subiTheDog = (from p in context.Persons where p.FirstName == "Subi" select p).First();

                Console.WriteLine(subiTheDog.FirstName);

                var subisAccount = subiTheDog.BankAccounts.FirstOrDefault();

                Console.WriteLine(subisAccount.Balance);

                Transfer(500, michealsAccount, subisAccount);

                Console.WriteLine("Transfer should be completed.");
                Console.WriteLine(michealsAccount.Balance);
                Console.WriteLine(subisAccount.Balance);

                context.SaveChanges();
            }
        }

        public static void Transfer(long amount, BankAccount account, BankAccount destinationAccount)
        {
            using (var context = new BankDbContext())
            {
                context.Attach(account);
                context.Attach(destinationAccount);

                account.Balance -= amount;
                destinationAccount.Balance += amount;

                Transfer t = new Transfer();
                t.Amount = amount;
                t.TransferredFromBankAccount = account;
                t.TransferredToBankAccount = destinationAccount;
                t.Timestamp = DateTime.UtcNow;

                context.Add(t);

                context.SaveChanges();
            }
        }
    }
}

