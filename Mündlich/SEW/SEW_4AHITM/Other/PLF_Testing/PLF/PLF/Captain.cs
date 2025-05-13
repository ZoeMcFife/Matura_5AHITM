using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PLF
{
    public class Captain
    {
        public int CaptainID { get; set; }

        public string? CaptainName { get; set; }

        public virtual ICollection<Starship>? Starships { get; set; }

        
        public Captain()
        {

        }

        public Captain (string name)
        {
            CaptainName = name;
        }
    }
}
