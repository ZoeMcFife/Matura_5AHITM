using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Person
{
    internal class Person
    {
        public string FirstName { get; set; } = "N.";
        public string LastName { get; set; } = "N.";
        public int YearOfBirth { get; set; } = 1978;

        public int Age
        {
            get
            {
                return DateTime.Now.Year - YearOfBirth;
            }
        }

        public Person(int yearOfBirth)
        {
            YearOfBirth = yearOfBirth;
        }

        public Person(string lastName, int yearOfBirth): this(yearOfBirth)
        {
            LastName = lastName;
        }

        public Person(string lastName, string firstName, int yearOfBirth): this(lastName, yearOfBirth)
        {
            FirstName = firstName;
        }

        public bool SameAge(Person person)
        {
            return Person.SameAge(this, person);
        }

        public static bool SameAge(Person person1, Person person2)
        {
            if (person1.Age == person2.Age) return true;

            return false;
        }

        public override string ToString()
        {
            return LastName + " " + FirstName;
        }

    }
}
