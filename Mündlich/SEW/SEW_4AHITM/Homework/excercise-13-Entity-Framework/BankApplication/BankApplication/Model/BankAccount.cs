using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Transactions;

namespace BankApplication.Model
{
    public enum AccountStatus
    {
        OPEN,
        CLOSED,
        DELETED
    }

    public class BankAccount
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int BankAccountID { get; set; }

        public long Balance { get; set; }

        public AccountStatus AccountStatus { get; set; } = AccountStatus.CLOSED;

        public virtual Person? AccountOwner { get; set; }

        public virtual ICollection<Transfer?> OutgoingTransactions { get; set; }
        public virtual ICollection<Transfer?> IncomingTransactions { get; set; }

        public BankAccount() 
        {
            Balance = 0;
        }

        public BankAccount(long startingBalance, Person accountOwner)
        {
            Balance = startingBalance;
            AccountOwner = accountOwner;
        }

        public void OpenAccount()
        {
            AccountStatus = AccountStatus.OPEN;
        }

        public void CloseAccount() 
        {
            AccountStatus = AccountStatus.CLOSED;
        }

        public void DeleteAccount() 
        {
            AccountStatus = AccountStatus.DELETED;
        }

        public void Withdraw(long amount)
        {
            using (var context = new BankContext())
            {
                if (!CanWithdraw(amount))
                    return;

                if (!IsAccountUsable())
                    return;

                Balance -= amount;

                context.Attach(this);

                Transfer t = new Transfer(amount, this, null);

                Console.WriteLine(t);

                context.Add(t);

                context.SaveChanges();
            }
        }

        public bool IsAccountUsable()
        {
            if (AccountStatus == AccountStatus.DELETED ||  AccountStatus == AccountStatus.CLOSED)
                return false;

            return true;
        }

        private bool CanWithdraw(long amount)
        {
            if (Balance == 0)
            {
                return false;
            }

            if (Balance < amount)
            {
                return false;
            }

            return true;
        }

        public void Deposit(long amount)
        {
            using (var context = new BankContext())
            {
                if (!IsAccountUsable())
                    return;

                Balance += amount;

                context.Attach(this);

                Transfer t = new Transfer(amount, null, this);

                context.Add(t);

                context.SaveChanges();
            }
        }

        public static void Transfer(long amount, BankAccount account, BankAccount destinationAccount)
        {
            using (var context = new BankContext())
            {
                if (!account.IsAccountUsable())
                    return;

                if (!account.CanWithdraw(amount))
                    return;

                if (!destinationAccount.IsAccountUsable())
                    return;

                // Thanks Copilot, this helped fix the Identity Insert Error 
                context.Attach(account);
                context.Attach(destinationAccount);

                account.Balance -= amount;
                destinationAccount.Balance += amount;

                Transfer t = new Transfer(amount, account, destinationAccount);

                context.Add(t);

                context.SaveChanges();
            }
        }

        public override string ToString()
        {
            return $"{BankAccountID} : {Balance} : {AccountOwner}";
        }
    }
}
