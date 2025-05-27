using Microsoft.EntityFrameworkCore;

namespace MessestandBackend.Model
{
    public class GalacticNewsContext : DbContext
    {
        public DbSet<User> users { get; set; }
        public DbSet<NewsArticle> newsArticles { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=GalacticNewsDb");
            optionsBuilder.UseLazyLoadingProxies();

        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
        }
    }
}
