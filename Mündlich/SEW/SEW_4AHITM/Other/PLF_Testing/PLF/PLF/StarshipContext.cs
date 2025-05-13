using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PLF
{
    internal class StarshipContext : DbContext
    {
        public DbSet<Starship> Starships { get; set; }
        public DbSet<Component> Components { get; set; }
        public DbSet<Captain> Captains { get; set; }


        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=StarshipDB").UseLazyLoadingProxies();
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<Starship>().HasMany(e => e.Engineers).WithMany(e => e.Starships);

            //modelBuilder.Entity<Starship>.Has

        }
    }
}

// PM> Scaffold-DbContext -Provider Microsoft.EntityFrameworkCore.SqlServer -Connection "Data Source=(localdb)\ProjectsV13;Initial Catalog=StoreDB;"

