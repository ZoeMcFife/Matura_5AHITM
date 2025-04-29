using System.Runtime.ConstrainedExecution;
using System;
using System.Security.Cryptography;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace LinqQueries
{
    internal class Program
    {
        /*
            public int Nr {  get; set; }
            public string Firstname { get; set; } = string.Empty;
            public string Lastname { get; set; } = string.Empty;
            public int Group {  get; set; }
            public int Age { get; set; }
            public List<int> Grading { get; set; } = new List<int>();
        */

        static void Main(string[] args)
        {
            var people = CreatePeople();

            Console.Write("All people");

            Person.PrintPeople(people);

            Console.WriteLine();

            // Folgende Aufgaben sind mit Linq oder mit Lambda zu lösen:

            // a. Erstellen Sie eine Klasse Students und fügen Sie die gegebenen Daten zu einer Liste hinzu.

            /* Schon Gemacht :) */

            // b. Zeigen Sie alle Studenten der Gruppe 1 und sortieren Sie diese absteigend anhand des Nachnamens.

            Console.WriteLine("Zeigen Sie alle Studenten der Gruppe 1 und sortieren Sie diese absteigend anhand des Nachnamens.");

            var b = from p in people
                    where p.Group == 1
                    orderby p.Lastname descending
                    select p;

            Person.PrintPeople(b.ToList());

            Console.WriteLine();

            // c. Geben Sie alle Studenten zwischen 18 und 24 Jahren aus. Die Ausgabe soll die Eigenschaften Firstname,
            //    Lastname und Alter beinhalten.

            Console.WriteLine("Geben Sie alle Studenten zwischen 18 und 24 Jahren aus.Die Ausgabe soll die Eigenschaften Firstname, Lastname und Alter beinhalten.");

            var c = from p in people
                    where p.Age >= 18 && p.Age <= 24
                    select new { p.Firstname, p.Lastname, p.Age };

            PrintList(c.ToList());

            Console.WriteLine();


            // d. Geben Sie alle Studenten aus, deren Nachname mit „er“ endet.

            Console.WriteLine("Geben Sie alle Studenten aus, deren Nachname mit „er“ endet.");

            var d = from p in people
                    where p.Lastname.EndsWith("er")
                    select p;

            Person.PrintPeople(d.ToList());

            Console.WriteLine();

            // e. Geben Sie alle Studenten aus, welche mindestens eine Note 1 beinhalten.

            Console.WriteLine("Geben Sie alle Studenten aus, welche mindestens eine Note 1 beinhalten.");

            var e = from p in people
                    where p.Grading.Contains(1)
                    select p;

            Person.PrintPeople(e.ToList());

            Console.WriteLine();
        }

        public static List<Person> CreatePeople()
        {
            return new List<Person>
            {
                new Person(1, "Sara", "Mills", 1, 30, new List<int> { 1, 5, 5, 3, 4 }),
                new Person(2, "Daniel", "Carter", 1, 35, new List<int> { 1, 4, 5, 3, 2 }),
                new Person(3, "Aaron", "Gibson", 5, 30, new List<int> { 5, 3, 5, 3, 5 }),
                new Person(4, "William", "Alexander", 3, 38, new List<int> { 3, 5, 5, 3, 2 })
            };
        }

        public static void PrintList<T>(List<T> list)
        {
            if (list.Count == 0)
            {
                Console.WriteLine("Empty");
                return;
            }

            foreach (var item in list)
            {
                Console.WriteLine($"- {item}");
            }
        }
    }
}
