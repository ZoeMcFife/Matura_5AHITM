using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BuchiBank
{
    class Withdrawer : Worker
    {
        public Withdrawer(BankAccount account, int waitTime) : base(account, waitTime)
        { }

        public override async Task Action()
        {
            var amount = GetRandomNumber();

            var result = await Account.Withdraw(amount);

            if (result)
            {
                Console.WriteLine("Withdrawed " + amount);
            }
            else
            {
                Console.WriteLine("Withdraw Unsuccessful. " + amount);
            }
        }
    }
}
