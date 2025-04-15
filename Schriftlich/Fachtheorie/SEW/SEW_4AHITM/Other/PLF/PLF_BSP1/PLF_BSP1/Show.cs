using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PLF_BSP1
{
    public class Show
    {
        public int ID {  get; set; }
        public string? Name { get; set; }
        public int ReleaseYear { get; set; }

        public virtual ICollection<Episode>? Episodes { get; set;} = new List<Episode>();
    }
}
