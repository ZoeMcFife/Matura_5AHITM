using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employee
{
    internal class ContractEmployee : Employee
    {
        private double _dailySalary = 0;

        public double DailySalary { get { return _dailySalary; } set { _dailySalary = value; } }

        public ContractEmployee() : this("Unknown", "Unknown", 0) { }

        public ContractEmployee(string firstName, string lastName, double dailySalary) : base(firstName, lastName)
        {
            DailySalary = dailySalary;
        }

        public override string ToString()
        {
            return base.ToString() + $" Daily Rate: € {DailySalary:F2}";
        }

        public override double CalculateHourlyRate()
        {
            return DailySalary / Globals.WorkHoursPerDay;
        }
    }
}
