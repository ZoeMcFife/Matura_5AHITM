using System;
using System.Collections.Generic;

namespace PLF_BSP2;

public partial class Country
{
    public long Id { get; set; }

    public string? CountriesAndTerritories { get; set; }

    public string GeoId { get; set; } = null!;

    public string? CountryTerritoryCode { get; set; }

    public long? PopData2018 { get; set; }

    public string? ContinentExp { get; set; }

    public string? SunnyComment { get; set; }

    public virtual ICollection<Case> Cases { get; set; } = new List<Case>();

    public virtual ICollection<CasesPreviou> CasesPrevious { get; set; } = new List<CasesPreviou>();
}
