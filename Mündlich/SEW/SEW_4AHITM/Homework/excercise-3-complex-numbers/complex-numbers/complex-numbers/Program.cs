using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace complex_numbers
{
    internal class Program
    {
        public static void Main(String[] args)
        {
            Complex c1 = new Complex();
            Complex c2 = new Complex(3d, 3.0d);
            Complex c3;
            c2.Real = 10.0;
            c2.Imaginary = 5.0;
            c1.PrintOut(); //0+0i
            c2.PrintOut(); //10+5i
            (Complex.Add(c1, c2)).PrintOut(); //10+5i
            (Complex.Add(new Complex(3, 2), new Complex(5, 5))).PrintOut(); //8+7i
            (new Complex(5, 5).Sub(new Complex(3, 2))).PrintOut(); //2+3i
            (Complex.Mul(new Complex(2, 5), new Complex(3, 7))).PrintOut(); //18+29i, It actually should be -29+29i  https://www.wolframalpha.com/input?i=%282%2B5i%29*%283%2B7i%29
            Console.WriteLine("Current number of complex objects: {0}", Complex.CountComplex);
            //Current number of complex objects: 12
            Console.WriteLine("Number is complex: {0}", (c2 * new Complex(-5, -10)).IsComplex);
            //Number is complex: True
            c3 = c1 + c2 - (new Complex(3, 3));
            c3.PrintOut(); // 7+2i

            Complex c4 = new Complex(3d, 3.0d);
            Complex c5 = new Complex(3d, 3.0d);
            List<Complex> list = new List<Complex>();
            list.Add(c4);
            if (list.Contains(c5))
            {
                Console.WriteLine("Same complex number already in the list.");
            }


            Console.ReadLine();
        }
    }
}
