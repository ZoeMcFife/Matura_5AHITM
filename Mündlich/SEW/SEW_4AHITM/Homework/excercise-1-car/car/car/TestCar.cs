using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;

namespace Car
{
    internal class TestCar
    {
        public static void Main ()
        {
            Car c1 = new Car("BMW");
            Car c2 = new Car("Porsche", 2006, true);
            Car c3 = new Car("N.N", 2000, true, Color.Green, 200.0f);

            Console.WriteLine(c1);

            c1.StartEngine();

            Console.WriteLine(c1);
            Console.WriteLine(c2);

            c2.KillEngine();
            c2.Type = "VW";
            c2.YearOfManufacturing = 1800;
            c3.YearOfManufacturing = 1800;

            Console.WriteLine(c3);
            Console.WriteLine("The " + c1 + " is " + c1.Age + " years old.");
        }

    }
}
