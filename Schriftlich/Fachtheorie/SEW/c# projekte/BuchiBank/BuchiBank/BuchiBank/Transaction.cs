using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BuchiBank
{
    public class Transaction
    {
        public double Id { get; set; }
        public static double lastId { get; set; } = 0;

        public DateTime Time { get; set; }
        
        public double Amount { get; set; }

        public TransactionType Type { get; set; }

        public Transaction(DateTime time, double amount, TransactionType type)
        {
            Id = lastId + 1;
            lastId++;
            
            Time = time;
            Amount = amount;
            Type = type;
        }

        public override string ToString()
        {
            return $"Transaction: {Id} {Time} {Amount} {Type}";
        }

    }

    public enum TransactionType
    {
        Incoming,
        Outgoing
    }
}
