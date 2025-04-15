using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employee
{
    internal class TempEmployee : Employee
    {
        private double _hourlySalary = 0;

        public double HourlySalary { get { return _hourlySalary; } set { _hourlySalary = value; } }

        public TempEmployee() : this("Unknown", "Unknown", 0) { }

        public TempEmployee(string firstName, string lastName, double hourlySalary) : base(firstName, lastName)
        {
            HourlySalary = hourlySalary;
        }

        public override string ToString()
        {
            return base.ToString() + $" Hourly Rate: € {HourlySalary:F2}";
        }

        public override double CalculateHourlyRate()
        {
            return HourlySalary;
        }
    }
}
