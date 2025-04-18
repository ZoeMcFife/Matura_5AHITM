﻿using System;
using System.Collections.Generic;

namespace SQLite_Excercise_14;

public partial class Artist
{
    public long ArtistId { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<Album> Albums { get; set; } = new List<Album>();
}
