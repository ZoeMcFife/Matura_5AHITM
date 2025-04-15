using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace PLF
{
    public class Component
    {
        public int ComponentID { get; set; }

        public string? Type { get; set; }

        public virtual Starship? Starship { get; set; }

        public Component()
        {

        }

        public Component(string type)
        {
            Type = type;
        }
    }
}
