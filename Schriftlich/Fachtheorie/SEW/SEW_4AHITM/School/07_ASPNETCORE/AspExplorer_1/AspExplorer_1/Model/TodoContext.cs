using Microsoft.EntityFrameworkCore;

namespace AspExplorer_1.Model
{
    public class TodoContext : DbContext
    {
        public TodoContext(DbContextOptions options) : base(options)
        {

        }

        public DbSet<TodoItem> TodoItems { get; set; }
    }
}
