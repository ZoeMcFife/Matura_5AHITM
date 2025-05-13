using System;
using System.Collections.Generic;

namespace BankApplicationDBFirst;

public partial class BankAccount
{
    public int BankAccountId { get; set; }

    public long Balance { get; set; }

    public int AccountStatus { get; set; }

    public int? AccountOwnerPersonId { get; set; }

    public virtual Person? AccountOwnerPerson { get; set; }

    public virtual ICollection<Transfer> TransferTransferredFromBankAccounts { get; set; } = new List<Transfer>();

    public virtual ICollection<Transfer> TransferTransferredToBankAccounts { get; set; } = new List<Transfer>();
}
