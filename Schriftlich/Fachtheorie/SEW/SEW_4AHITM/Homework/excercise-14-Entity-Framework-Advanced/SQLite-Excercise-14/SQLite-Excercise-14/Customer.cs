﻿using System;
using System.Collections.Generic;

namespace SQLite_Excercise_14;

public partial class Customer
{
    public long CustomerId { get; set; }

    public string FirstName { get; set; } = null!;

    public string LastName { get; set; } = null!;

    public string? Company { get; set; }

    public string? Address { get; set; }

    public string? City { get; set; }

    public string? State { get; set; }

    public string? Country { get; set; }

    public string? PostalCode { get; set; }

    public string? Phone { get; set; }

    public string? Fax { get; set; }

    public string Email { get; set; } = null!;

    public long? SupportRepId { get; set; }

    public virtual ICollection<Invoice> Invoices { get; set; } = new List<Invoice>();

    public virtual Employee? SupportRep { get; set; }
}
