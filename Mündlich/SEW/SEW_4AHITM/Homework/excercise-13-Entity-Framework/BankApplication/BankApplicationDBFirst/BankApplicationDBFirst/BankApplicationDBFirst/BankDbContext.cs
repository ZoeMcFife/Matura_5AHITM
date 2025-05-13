using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;

namespace BankApplicationDBFirst;

public partial class BankDbContext : DbContext
{
    public BankDbContext()
    {
    }

    public BankDbContext(DbContextOptions<BankDbContext> options)
        : base(options)
    {
    }

    public virtual DbSet<BankAccount> BankAccounts { get; set; }

    public virtual DbSet<Person> Persons { get; set; }

    public virtual DbSet<Transfer> Transfers { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
        => optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=BankDB").UseLazyLoadingProxies();

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<BankAccount>(entity =>
        {
            entity.HasIndex(e => e.AccountOwnerPersonId, "IX_BankAccounts_AccountOwnerPersonID");

            entity.Property(e => e.BankAccountId).HasColumnName("BankAccountID");
            entity.Property(e => e.AccountOwnerPersonId).HasColumnName("AccountOwnerPersonID");

            entity.HasOne(d => d.AccountOwnerPerson).WithMany(p => p.BankAccounts).HasForeignKey(d => d.AccountOwnerPersonId);
        });

        modelBuilder.Entity<Person>(entity =>
        {
            entity.Property(e => e.PersonId).HasColumnName("PersonID");
        });

        modelBuilder.Entity<Transfer>(entity =>
        {
            entity.ToTable("Transfer");

            entity.HasIndex(e => e.TransferredFromBankAccountId, "IX_Transfer_TransferredFromBankAccountID");

            entity.HasIndex(e => e.TransferredToBankAccountId, "IX_Transfer_TransferredToBankAccountID");

            entity.Property(e => e.TransferredFromBankAccountId).HasColumnName("TransferredFromBankAccountID");
            entity.Property(e => e.TransferredToBankAccountId).HasColumnName("TransferredToBankAccountID");

            entity.HasOne(d => d.TransferredFromBankAccount).WithMany(p => p.TransferTransferredFromBankAccounts).HasForeignKey(d => d.TransferredFromBankAccountId);

            entity.HasOne(d => d.TransferredToBankAccount).WithMany(p => p.TransferTransferredToBankAccounts).HasForeignKey(d => d.TransferredToBankAccountId);
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
