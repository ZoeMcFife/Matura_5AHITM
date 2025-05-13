using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employee.Test
{
    internal class EmployeeTest3
    {
        public static void Main(String[] args)
        {
            Employee[] f = new Employee[3];
            f[0] = new PermanentEmployee("Franz", "Schuster", 15000.0);
            f[1] = new ContractEmployee("Hans", "Huber", 100.0);
            f[2] = new TempEmployee("Barbara", "Schmidt", 7.5);
            String hourlyRate;
            foreach (Employee e in f)
            {
                Console.WriteLine(e);
                hourlyRate = e.CalculateHourlyRate().ToString("f2");
                Console.WriteLine("Hourly rate = " + hourlyRate);
            }
            Console.ReadLine();
        }

    }
}
