using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employee
{
    internal abstract class Employee : IPayable
    {
        private string _firstame = string.Empty;
        private string _lastName = string.Empty;

        public string FirstName { get { return _firstame; } set { _firstame = value; } }
        public string LastName { get { return _lastName; } set { _lastName = value; } }

        public Employee() : this("Unknown", "Unknown") { }

        public Employee(string firstame, string lastName)
        { 
            FirstName = firstame;
            LastName = lastName;
        }

        public override string ToString()
        {
            return $"First Name: {FirstName}, Last Name: {LastName}";
        }

        public abstract double CalculateHourlyRate();
    }
}
