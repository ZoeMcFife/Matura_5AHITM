using BankApplication.Model;

namespace BankApplication
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //ClearDB();

            //CreatePeopleAndAccounts();

            Testing();
        }

        static void Testing()
        {
            using (var context = new BankContext())
            {
                var michealStevens = (from p in context.Persons where p.FirstName == "Micheal" select p).First();

                Console.WriteLine(michealStevens);

                var michealsAccount = michealStevens.BankAccounts.FirstOrDefault();

                Console.WriteLine(michealsAccount);

                michealsAccount.Deposit(1000);

                Console.WriteLine(michealsAccount);

                var subiTheDog = (from p in context.Persons where p.FirstName == "Subi" select p).First();

                Console.WriteLine(subiTheDog);

                var subisAccount = subiTheDog.BankAccounts.FirstOrDefault();

                Console.WriteLine(subisAccount);

                BankAccount.Transfer(500, michealsAccount, subisAccount);

                Console.WriteLine("Transfer should be completed.");
                Console.WriteLine(michealsAccount);
                Console.WriteLine(subisAccount);
                
                context.SaveChanges();
            }
        }

        static void CreatePeopleAndAccounts()
        {
            var context = new BankContext();

            var person1 = new Person("Micheal", "Stevens", new DateTime(1942, 12, 1));
            var person2 = new Person("Mae", "Borowski", new DateTime(2002, 10, 23));
            var person3 = new Person("Subi", "The Dog", new DateTime(2017, 6, 20));

            context.Add(person1);
            context.Add(person2);
            context.Add(person3);

            var account1 = new BankAccount(1000, person1);
            var account2 = new BankAccount(1500, person1);
            var account3 = new BankAccount(2000, person2);
            var account4 = new BankAccount(2500, person2);
            var account5 = new BankAccount(3000, person3);
            var account6 = new BankAccount(3500, person3);

            account1.OpenAccount();
            account2.OpenAccount();
            account3.OpenAccount();
            account4.OpenAccount();
            account5.OpenAccount();
            account6.OpenAccount();

            context.BankAccounts.AddRange(account1, account2, account3, account4, account5, account6);

            context.SaveChanges();
        }

        static void ClearDB()
        {
            var context = new BankContext();

            // Remove all BankAccounts
            var bankAccounts = context.BankAccounts.ToList();
            context.BankAccounts.RemoveRange(bankAccounts);

            // Remove all Persons
            var persons = context.Persons.ToList();
            context.Persons.RemoveRange(persons);

            // Remove all Transfers
            var transfers = context.Transfer.ToList();
            context.Transfer.RemoveRange(transfers);

            // Save changes to the database
            context.SaveChanges();

        }
    }
}