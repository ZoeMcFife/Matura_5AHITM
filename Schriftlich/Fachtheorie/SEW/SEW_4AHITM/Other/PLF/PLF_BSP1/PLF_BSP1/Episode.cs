using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PLF_BSP1
{
    public class Episode
    {
        public int ID {  get; set; }
        public string? Name { get; set; }
        public int Season { get; set; }
        public DateTime ReleaseDate { get; set; }
        public int Length { get; set; }
        public bool Seen { get; set; }

        public virtual Show? Show { get; set; }

    }
}
