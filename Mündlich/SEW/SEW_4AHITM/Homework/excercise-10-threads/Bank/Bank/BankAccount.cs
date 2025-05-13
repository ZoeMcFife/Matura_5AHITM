using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    internal class BankAccount
    {
        public long Balance { get; private set; }
        public string Name { get; set; } = "Name";

        public BankAccount(long balance, string name)
        {
            Balance = balance;
            Name = name;
        }

        public bool Withdraw(long amount)
        {

            lock (this)
            {
                if (Balance == 0)
                {
                    Console.WriteLine("No credits to withdraw.");

                    return false;
                }

                if (Balance < amount)
                {
                    Console.WriteLine("Insufficient credits. Requested {0} : Only have {1}", amount, Balance);
                    return false;
                }

                long newBalance = Balance - amount;

                Console.WriteLine("New Balance after Withdrawel: {0} / {1}", newBalance, Balance);

                Balance = newBalance;

                return true;
            }


        }

        public void Deposit(long amount)
        {
            lock (this) 
            {
                long newBalance = Balance + amount;

                Console.WriteLine("New Balance after Deposit: {0} / {1}", newBalance, Balance);

                Balance = newBalance;
            }
        }

        public void Transfer(long amount, BankAccount destinationAccount)
        {
            if (Withdraw(amount))
                destinationAccount.Deposit(amount);
        }


    }
}
