using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinqQueries
{
    class Person
    {
        public int Nr {  get; set; }
        public string Firstname { get; set; } = string.Empty;
        public string Lastname { get; set; } = string.Empty;
        public int Group {  get; set; }
        public int Age { get; set; }
        public List<int> Grading { get; set; } = new List<int>();

        public Person(int nr, string firstname, string lastname, int group, int age, List<int> grading)
        {
            Nr = nr;
            Firstname = firstname;
            Lastname = lastname;
            Group = group;
            Age = age;
            Grading = grading ?? new List<int>(); 
        }

        public override string ToString()
        {
            return $"Nr: {Nr}, Name: {Firstname} {Lastname}, Group: {Group}, Age: {Age}, Grades: [{string.Join(", ", Grading)}]";
        }

        public static void PrintPeople(List<Person> people)
        {
            if (people.Count == 0)
            {
                Console.WriteLine("Empty");
                return;
            }

            Console.WriteLine("List of People:");
            Console.WriteLine("-------------------------------------------------------------");
            foreach (var person in people)
            {
                Console.WriteLine(person.ToString());
            }
            Console.WriteLine("-------------------------------------------------------------");
        }

    }
}
