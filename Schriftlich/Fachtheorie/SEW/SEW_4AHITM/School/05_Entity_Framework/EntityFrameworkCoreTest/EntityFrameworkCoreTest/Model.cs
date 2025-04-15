using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EntityFrameworkCoreTest
{
    public class BlogContext : DbContext
    {
        public DbSet<Blog> Blogs { get; set; }
        public DbSet<Post> Posts { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=EFCoreGettingStarted").UseLazyLoadingProxies();
        }
    }

    public class Blog
    {
        public int BlogID { get; set; }
        public string URL { get; set; } = string.Empty;

        public virtual ICollection<Post>? Posts { get; set; }
    }

    public class Post
    {
        public int PostID { get; set; }
        public string Title { get; set; } = string.Empty;
        public string Content { get; set; } = string.Empty;

        public int BlogID { get; set; }
        public virtual Blog? Blog { get; set; }
    }
}
