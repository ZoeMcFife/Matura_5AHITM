using Microsoft.EntityFrameworkCore;
using StudentsDB.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentsDB
{
    internal class StudentContext : DbContext
    {
        public DbSet<Class> classes;
        public DbSet<Student> students;

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=StudentDB").UseLazyLoadingProxies();
        }

        public StudentContext(DbContextOptions options) : base(options)
        {

        }
    }
}
