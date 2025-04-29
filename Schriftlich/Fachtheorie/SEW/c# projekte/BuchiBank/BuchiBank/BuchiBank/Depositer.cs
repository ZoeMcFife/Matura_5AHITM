using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BuchiBank
{
    class Depositer : Worker
    {
        public Depositer(BankAccount account, int waitTime) : base(account, waitTime)
        {
        }

        public override async Task Action()
        {
            var amount = GetRandomNumber();

            await Account.Deposit(amount);

            Console.WriteLine("Deposited " + amount);
        }

    }
}
