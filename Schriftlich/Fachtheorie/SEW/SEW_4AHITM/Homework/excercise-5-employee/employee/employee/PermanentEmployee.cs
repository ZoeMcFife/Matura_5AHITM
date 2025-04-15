using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employee
{
    internal class PermanentEmployee : Employee
    {
        private double _yearlySalary = 0;
        
        public double YearlySalary { get { return _yearlySalary;} set { _yearlySalary = value; } }

        public PermanentEmployee() : this("Unknown", "Unknown", 0) { }

        public PermanentEmployee(string firstName, string lastName, double yearlySalary) : base(firstName, lastName)
        {
            YearlySalary = yearlySalary; 
        }

        public override string ToString()
        {
            return base.ToString() + $" Salary: € {YearlySalary:F2}";
        }

        public override double CalculateHourlyRate()
        {
            return YearlySalary / Globals.WorkDaysPerYear / Globals.WorkHoursPerDay;
        }
    }
}
