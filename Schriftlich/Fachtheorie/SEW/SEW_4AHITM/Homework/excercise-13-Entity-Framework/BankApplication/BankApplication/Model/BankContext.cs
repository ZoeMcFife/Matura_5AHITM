using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankApplication.Model
{
    public class BankContext : DbContext
    {
        public DbSet<BankAccount> BankAccounts { get; set; }
        public DbSet<Person> Persons { get; set; }
        public DbSet<Transfer> Transfer { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=BankDB").UseLazyLoadingProxies();
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<BankAccount>().HasMany(ba => ba.IncomingTransactions).WithOne(t => t.TransferredTo);
            modelBuilder.Entity<BankAccount>().HasMany(ba => ba.OutgoingTransactions).WithOne(t => t.TransferredFrom);
        }

    }
}
