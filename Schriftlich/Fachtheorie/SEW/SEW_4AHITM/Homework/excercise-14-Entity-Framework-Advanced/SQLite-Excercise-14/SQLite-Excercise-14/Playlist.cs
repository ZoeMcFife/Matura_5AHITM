﻿using System;
using System.Collections.Generic;

namespace SQLite_Excercise_14;

public partial class Playlist
{
    public long PlaylistId { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<Track> Tracks { get; set; } = new List<Track>();
}
