using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;

namespace PLF_BSP2;

public partial class CovidContext : DbContext
{
    public CovidContext()
    {
    }

    public CovidContext(DbContextOptions<CovidContext> options)
        : base(options)
    {
    }

    public virtual DbSet<AndroidMetadatum> AndroidMetadata { get; set; }

    public virtual DbSet<Case> Cases { get; set; }

    public virtual DbSet<CasesPreviou> CasesPrevious { get; set; }

    public virtual DbSet<Country> Countries { get; set; }

    public virtual DbSet<CountryPreviou> CountryPrevious { get; set; }

    public virtual DbSet<Covid19EcdcEuropaEuSunnySainiCom> Covid19EcdcEuropaEuSunnySainiComs { get; set; }

    public virtual DbSet<Covid19EcdcEuropaEuSunnySainiComSimple> Covid19EcdcEuropaEuSunnySainiComSimples { get; set; }

    public virtual DbSet<CsvImport> CsvImports { get; set; }

    public virtual DbSet<CsvImportIndium> CsvImportIndia { get; set; }

    public virtual DbSet<IndiaCase> IndiaCases { get; set; }

    public virtual DbSet<IndiaKaggleComPritamguha31SunnySainiCom> IndiaKaggleComPritamguha31SunnySainiComs { get; set; }

    public virtual DbSet<Indium> India { get; set; }

    public virtual DbSet<Info> Infos { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
        => optionsBuilder.UseSqlite("DataSource=covid.db");

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<AndroidMetadatum>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("android_metadata");

            entity.Property(e => e.Locale).HasColumnName("locale");
        });

        modelBuilder.Entity<Case>(entity =>
        {
            entity.HasIndex(e => new { e.DateRep, e.GeoId }, "IX_Cases_dateRep_geoId").IsUnique();

            entity.Property(e => e.Id)
                .ValueGeneratedNever()
                .HasColumnName("id");
            entity.Property(e => e.Cases).HasColumnName("cases");
            entity.Property(e => e.DateRep).HasColumnName("dateRep");
            entity.Property(e => e.Deaths).HasColumnName("deaths");
            entity.Property(e => e.GeoId).HasColumnName("geoId");

            entity.HasOne(d => d.Geo).WithMany(p => p.Cases)
                .HasPrincipalKey(p => p.GeoId)
                .HasForeignKey(d => d.GeoId);
        });

        modelBuilder.Entity<CasesPreviou>(entity =>
        {
            entity.Property(e => e.Id)
                .ValueGeneratedNever()
                .HasColumnName("id");
            entity.Property(e => e.CasesNew).HasColumnName("casesNew");
            entity.Property(e => e.CasesOld).HasColumnName("casesOld");
            entity.Property(e => e.DateRep).HasColumnName("dateRep");
            entity.Property(e => e.DeathsNew).HasColumnName("deathsNew");
            entity.Property(e => e.DeathsOld).HasColumnName("deathsOld");
            entity.Property(e => e.GeoId).HasColumnName("geoId");
            entity.Property(e => e.Modified).HasDefaultValueSql("date('now', '+05:30')");

            entity.HasOne(d => d.Geo).WithMany(p => p.CasesPrevious)
                .HasPrincipalKey(p => p.GeoId)
                .HasForeignKey(d => d.GeoId);
        });

        modelBuilder.Entity<Country>(entity =>
        {
            entity.ToTable("Country");

            entity.HasIndex(e => e.GeoId, "IX_Country_GeoID").IsUnique();

            entity.Property(e => e.Id)
                .ValueGeneratedNever()
                .HasColumnName("id");
            entity.Property(e => e.GeoId).HasColumnName("GeoID");
        });

        modelBuilder.Entity<CountryPreviou>(entity =>
        {
            entity.HasIndex(e => e.GeoId, "IX_CountryPrevious_GeoID").IsUnique();

            entity.Property(e => e.Id)
                .ValueGeneratedNever()
                .HasColumnName("id");
            entity.Property(e => e.GeoId).HasColumnName("GeoID");
            entity.Property(e => e.Modified).HasDefaultValueSql("date('now','+05:30')");
        });

        modelBuilder.Entity<Covid19EcdcEuropaEuSunnySainiCom>(entity =>
        {
            entity
                .HasNoKey()
                .ToView("Covid19 - ecdc.europa.eu - SunnySaini.com");

            entity.Property(e => e.DC).HasColumnName("D/C%");
            entity.Property(e => e.DMp).HasColumnName("D/Mp");
        });

        modelBuilder.Entity<Covid19EcdcEuropaEuSunnySainiComSimple>(entity =>
        {
            entity
                .HasNoKey()
                .ToView("Covid19 - ecdc.europa.eu - SunnySaini.com Simple");

            entity.Property(e => e.DateRep).HasColumnName("dateRep");
            entity.Property(e => e.Death).HasColumnName("Death%");
        });

        modelBuilder.Entity<CsvImport>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("csvImport");

            entity.Property(e => e.Cases).HasColumnName("cases");
            entity.Property(e => e.ContinentExp).HasColumnName("continentExp");
            entity.Property(e => e.CountriesAndTerritories).HasColumnName("countriesAndTerritories");
            entity.Property(e => e.CountryterritoryCode).HasColumnName("countryterritoryCode");
            entity.Property(e => e.DateRep).HasColumnName("dateRep");
            entity.Property(e => e.Day).HasColumnName("day");
            entity.Property(e => e.Deaths).HasColumnName("deaths");
            entity.Property(e => e.GeoId).HasColumnName("geoId");
            entity.Property(e => e.Month).HasColumnName("month");
            entity.Property(e => e.PopData2018).HasColumnName("popData2018");
            entity.Property(e => e.Year).HasColumnName("year");
        });

        modelBuilder.Entity<CsvImportIndium>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("csvImportIndia");

            entity.Property(e => e.StateUnionTerritory).HasColumnName("State/UnionTerritory");
        });

        modelBuilder.Entity<IndiaCase>(entity =>
        {
            entity.Property(e => e.Id)
                .ValueGeneratedNever()
                .HasColumnName("id");
            entity.Property(e => e.StateUnionTerritory).HasColumnName("State/UnionTerritory");
        });

        modelBuilder.Entity<IndiaKaggleComPritamguha31SunnySainiCom>(entity =>
        {
            entity
                .HasNoKey()
                .ToView("India kaggle.com/pritamguha31 - SunnySaini.com");

            entity.Property(e => e.StateUnionTerritory).HasColumnName("State/UnionTerritory");
        });

        modelBuilder.Entity<Indium>(entity =>
        {
            entity.Property(e => e.Id)
                .ValueGeneratedNever()
                .HasColumnName("id");
            entity.Property(e => e.DC).HasColumnName("D/C%");
            entity.Property(e => e.DMp).HasColumnName("D/Mp");
        });

        modelBuilder.Entity<Info>(entity =>
        {
            entity.ToTable("!Info");

            entity.Property(e => e.Id)
                .ValueGeneratedNever()
                .HasColumnName("id");
            entity.Property(e => e.Ist)
                .HasDefaultValueSql("date('now','+05:30')")
                .HasColumnName("IST");
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
