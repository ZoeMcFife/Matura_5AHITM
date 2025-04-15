using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankApplication.Model
{
    public class Transfer
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int TransferId { get; set; }

        public long Amount { get; set; }
        public DateTime Timestamp { get; set; }

        public virtual BankAccount? TransferredFrom { get; set; }
        public virtual BankAccount? TransferredTo { get; set; }

        public Transfer() 
        {
            Amount = 0;
        }

        public Transfer(long amount, BankAccount? transferredFrom, BankAccount? transferredTo) 
        {
            Amount = amount;

            TransferredFrom = transferredFrom;
            TransferredTo = transferredTo;

            Timestamp = DateTime.UtcNow;
        }

        public override string ToString()
        {
            return $"Transfer: {TransferredFrom} to {TransferredTo} : Amount: {Amount}";
        }
    }
}
