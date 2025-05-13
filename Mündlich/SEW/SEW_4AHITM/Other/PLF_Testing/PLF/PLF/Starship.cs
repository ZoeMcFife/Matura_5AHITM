using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PLF
{
    public class Starship
    {
        public int StarshipID { get; set; }

        public string? Name { get; set; }
        
        public virtual Captain? Captain { get; set; }
        public virtual ICollection<Component>? Components { get; set; }

        public virtual ICollection<Engineer> Engineers { get; set; }

        public Starship()
        {

        }

        public Starship(string name)
        {
            Name = name;
        }
    }
}
