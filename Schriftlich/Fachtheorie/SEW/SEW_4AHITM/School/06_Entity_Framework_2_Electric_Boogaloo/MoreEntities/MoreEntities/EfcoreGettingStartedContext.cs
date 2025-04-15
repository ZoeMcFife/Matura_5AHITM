using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;

namespace MoreEntities;

public partial class EfcoreGettingStartedContext : DbContext
{
    public EfcoreGettingStartedContext()
    {
    }

    public EfcoreGettingStartedContext(DbContextOptions<EfcoreGettingStartedContext> options)
        : base(options)
    {
    }

    public virtual DbSet<Blog> Blogs { get; set; }

    public virtual DbSet<Post> Posts { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
        => optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=EFCoreGettingStarted");

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Blog>(entity =>
        {
            entity.Property(e => e.BlogId).HasColumnName("BlogID");
            entity.Property(e => e.Url).HasColumnName("URL");
        });

        modelBuilder.Entity<Post>(entity =>
        {
            entity.HasIndex(e => e.BlogId, "IX_Posts_BlogID");

            entity.Property(e => e.PostId).HasColumnName("PostID");
            entity.Property(e => e.BlogId).HasColumnName("BlogID");

            entity.HasOne(d => d.Blog).WithMany(p => p.Posts).HasForeignKey(d => d.BlogId);
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
