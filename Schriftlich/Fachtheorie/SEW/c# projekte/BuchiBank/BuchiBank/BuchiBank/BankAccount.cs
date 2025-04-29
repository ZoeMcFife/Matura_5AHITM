using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace BuchiBank
{
    public class BankAccount
    {
        private readonly object _lock = new();

        public List<Transaction> TransactionHistory = new();

        private double _balance;

        public double Balance
        {
            get
            {
                return _balance;
            }

            set
            {
                if (value < 0)
                {
                    _balance = 0;
                }
                else
                {
                    _balance = value;
                }
            }
        }

        public List<Transaction> HistoryAscending
        {
            get
            {
                var result = from t in TransactionHistory
                             orderby t.Time ascending
                             select t;

                return result.ToList();
            }
        }

        public List<Transaction> Withdrawels
        {
            get
            {
                var result = from t in TransactionHistory
                             orderby t.Time ascending
                             where t.Type == TransactionType.Outgoing
                             select t;

                return result.ToList();
            }
        }

        public List<Transaction> Deposits
        {
            get
            {
                var result = from t in TransactionHistory
                             orderby t.Time ascending
                             where t.Type == TransactionType.Outgoing
                             select t;

                return result.ToList();
            }
        }

        public async Task AddTransaction(Transaction transaction)
        {
            await Task.Run(async () =>
            {
                if (transaction.Type == TransactionType.Outgoing)
                {
                    bool result = await Withdraw(transaction.Amount);

                    if (result)
                    {
                        TransactionHistory.Add(transaction);
                    }
                }

                if (transaction.Type == TransactionType.Incoming)
                {
                    await Withdraw(transaction.Amount);
                }
            });
        }

        public async Task Deposit(double amount)
        {
            await Task.Run(() =>
            {
                lock (_lock)
                {
                    Balance += amount;
                    TransactionHistory.Add(new Transaction(DateTime.UtcNow, amount, TransactionType.Incoming));
                }
            });
        }

        public async Task<bool> Withdraw(double amount)
        {
            return await Task.Run(() =>
            {
                lock ( _lock)
                {
                    if (amount > Balance)
                    {
                        return false;
                    }

                    Balance -= amount;
                    TransactionHistory.Add(new Transaction(DateTime.UtcNow, amount, TransactionType.Outgoing));

                    return true;
                }
            });
        }

        public static void PrintTransactions(string title, List<Transaction> transactions)
        {
            Console.WriteLine($"Printing {title}:");

            foreach (Transaction transaction in transactions)
            {
                Console.WriteLine(transaction);
            }
            Console.WriteLine();
        }
    }
}
