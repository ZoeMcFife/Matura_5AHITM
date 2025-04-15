using System;
using System.Collections.Generic;

namespace PLF_BSP2;

public partial class IndiaCase
{
    public long Id { get; set; }

    public string? Date { get; set; }

    public string? Time { get; set; }

    public string? StateUnionTerritory { get; set; }

    public long? ConfirmedIndianNational { get; set; }

    public long? ConfirmedForeignNational { get; set; }

    public long? Cured { get; set; }

    public long? Deaths { get; set; }

    public long? Confirmed { get; set; }

    public string? SunnyComment { get; set; }
}
