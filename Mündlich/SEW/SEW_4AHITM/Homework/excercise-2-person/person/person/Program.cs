using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Person
{
    internal class Program
    {

        public static void Main(String[] args)
        {
            // name = firstName = "N.N.", YoB = 1978
            Person p1 = new Person(2005); // add your own year of birth
            Person p2 = new Person("Maier", 1967);
            Person p3 = new Person("Schmidt", "Franz", 1967);
            p1.LastName = "Loe";
            p1.FirstName = "Bunea";
            p2.FirstName = "Eva";
            Console.WriteLine(p1 + " is " + p1.Age + " years old.");
            if (p2.SameAge(p3))
                Console.WriteLine(p2 + " and " + p3 + " are the same age");
            if (Person.SameAge(p2, p3))
                Console.WriteLine(p2 + " and " + p3 + " are the same age");
            Console.ReadLine();
        }
    }
}
