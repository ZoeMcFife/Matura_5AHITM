using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PLF
{
    public class Engineer
    {
        public int EngineerID { get; set; }

        public string EngineerName { get; set;}

        public virtual ICollection<Starship> Starships { get; set; }


    }
}
