using System;
using System.Collections.Generic;

namespace PLF_BSP2;

public partial class CasesPreviou
{
    public long Id { get; set; }

    public string? DateRep { get; set; }

    public long? CasesOld { get; set; }

    public long? CasesNew { get; set; }

    public long? DeathsOld { get; set; }

    public long? DeathsNew { get; set; }

    public string? Modified { get; set; }

    public string? GeoId { get; set; }

    public string? SunnyComment { get; set; }

    public virtual Country? Geo { get; set; }
}
