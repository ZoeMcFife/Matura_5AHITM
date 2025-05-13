using System;
using System.Collections.Generic;

namespace PLF_BSP2;

public partial class Case
{
    public long Id { get; set; }

    public string? DateRep { get; set; }

    public long? Cases { get; set; }

    public long? Deaths { get; set; }

    public string? GeoId { get; set; }

    public string? SunnyComment { get; set; }

    public virtual Country? Geo { get; set; }
}
