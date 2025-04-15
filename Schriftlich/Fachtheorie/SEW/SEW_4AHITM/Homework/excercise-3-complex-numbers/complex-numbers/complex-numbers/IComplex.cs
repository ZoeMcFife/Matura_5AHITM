using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace complex_numbers
{
    public interface IComplex
    {
        double Real { get; set; }
        double Imaginary { get; set; }

        bool IsComplex { get; }
        void PrintOut();
    }
}
