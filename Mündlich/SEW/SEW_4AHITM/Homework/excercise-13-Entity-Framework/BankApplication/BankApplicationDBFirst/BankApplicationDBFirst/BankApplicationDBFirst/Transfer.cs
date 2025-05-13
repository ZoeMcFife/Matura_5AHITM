using System;
using System.Collections.Generic;

namespace BankApplicationDBFirst;

public partial class Transfer
{
    public int TransferId { get; set; }

    public long Amount { get; set; }

    public DateTime Timestamp { get; set; }

    public int? TransferredFromBankAccountId { get; set; }

    public int? TransferredToBankAccountId { get; set; }

    public virtual BankAccount? TransferredFromBankAccount { get; set; }

    public virtual BankAccount? TransferredToBankAccount { get; set; }
}
