using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PLF_BSP1
{
    public class TVContext : DbContext
    {
        public DbSet<Episode>? Episodes;
        public DbSet<Show>? Shows;

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlite("Data Source=tvdatabase.db").UseLazyLoadingProxies();
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<Episode>().HasOne(e => e.Show).WithMany(s => s.Episodes);
        }
    }
}
