using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using System.IO;

namespace linq_samples
{
   
    class Program
    {
        private static List<Product> products;
        private static List<Customer> customers;
        private static List<School> schools;
        private static List<Employee> employees;
        private static List<Student> students;
        private static List<Marking> marks;

        public static List<Customer> GetCustomerList()
        {
            if (customers == null)
                createLists();

            return customers;
        }

        class School 
        {
            public int SchoolID { get; set; }
            public string Name { get; set; }
        }
        
        class Employee 
        {
            public int EmployeeId { get; set; }
            public string EmployeeName { get; set; } public int SchoolID { get; set; } }

        private static void createLists()
        {
            // Product data created in-memory using collection initializer:
            products =
                new List<Product> {
                    new Product { ProductID = 1, ProductName = "Chai", Category = "Beverages", UnitPrice = 18.0000M, UnitsInStock = 39 },
                    new Product { ProductID = 2, ProductName = "Chang", Category = "Beverages", UnitPrice = 19.0000M, UnitsInStock = 17 },
                    new Product { ProductID = 3, ProductName = "Aniseed Syrup", Category = "Condiments", UnitPrice = 10.0000M, UnitsInStock = 13 },
                    new Product { ProductID = 4, ProductName = "Chef Anton's Cajun Seasoning", Category = "Condiments", UnitPrice = 22.0000M, UnitsInStock = 53 },
                    new Product { ProductID = 5, ProductName = "Chef Anton's Gumbo Mix", Category = "Condiments", UnitPrice = 21.3500M, UnitsInStock = 0 },
                    new Product { ProductID = 6, ProductName = "Grandma's Boysenberry Spread", Category = "Condiments", UnitPrice = 25.0000M, UnitsInStock = 120 },
                    new Product { ProductID = 7, ProductName = "Uncle Bob's Organic Dried Pears", Category = "Produce", UnitPrice = 30.0000M, UnitsInStock = 15 },
                    new Product { ProductID = 8, ProductName = "Northwoods Cranberry Sauce", Category = "Condiments", UnitPrice = 40.0000M, UnitsInStock = 6 },
                    new Product { ProductID = 9, ProductName = "Mishi Kobe Niku", Category = "Meat/Poultry", UnitPrice = 97.0000M, UnitsInStock = 29 },
                    new Product { ProductID = 10, ProductName = "Ikura", Category = "Seafood", UnitPrice = 31.0000M, UnitsInStock = 31 },
                    new Product { ProductID = 11, ProductName = "Queso Cabrales", Category = "Dairy Products", UnitPrice = 21.0000M, UnitsInStock = 22 },
                    new Product { ProductID = 12, ProductName = "Queso Manchego La Pastora", Category = "Dairy Products", UnitPrice = 38.0000M, UnitsInStock = 86 },
                    new Product { ProductID = 13, ProductName = "Konbu", Category = "Seafood", UnitPrice = 6.0000M, UnitsInStock = 24 },
                    new Product { ProductID = 14, ProductName = "Tofu", Category = "Produce", UnitPrice = 23.2500M, UnitsInStock = 35 },
                    new Product { ProductID = 15, ProductName = "Genen Shouyu", Category = "Condiments", UnitPrice = 15.5000M, UnitsInStock = 39 },
                    new Product { ProductID = 16, ProductName = "Pavlova", Category = "Confections", UnitPrice = 17.4500M, UnitsInStock = 29 },
                    new Product { ProductID = 17, ProductName = "Alice Mutton", Category = "Meat/Poultry", UnitPrice = 39.0000M, UnitsInStock = 0 },
                    new Product { ProductID = 18, ProductName = "Carnarvon Tigers", Category = "Seafood", UnitPrice = 62.5000M, UnitsInStock = 42 },
                    new Product { ProductID = 19, ProductName = "Teatime Chocolate Biscuits", Category = "Confections", UnitPrice = 9.2000M, UnitsInStock = 25 },
                    new Product { ProductID = 20, ProductName = "Sir Rodney's Marmalade", Category = "Confections", UnitPrice = 81.0000M, UnitsInStock = 40 },
                    new Product { ProductID = 21, ProductName = "Sir Rodney's Scones", Category = "Confections", UnitPrice = 10.0000M, UnitsInStock = 3 },
                    new Product { ProductID = 22, ProductName = "Gustaf's Knäckebröd", Category = "Grains/Cereals", UnitPrice = 21.0000M, UnitsInStock = 104 },
                    new Product { ProductID = 23, ProductName = "Tunnbröd", Category = "Grains/Cereals", UnitPrice = 9.0000M, UnitsInStock = 61 },
                    new Product { ProductID = 24, ProductName = "Guaraná Fantástica", Category = "Beverages", UnitPrice = 4.5000M, UnitsInStock = 20 },
                    new Product { ProductID = 25, ProductName = "NuNuCa Nuß-Nougat-Creme", Category = "Confections", UnitPrice = 14.0000M, UnitsInStock = 76 },
                    new Product { ProductID = 26, ProductName = "Gumbär Gummibärchen", Category = "Confections", UnitPrice = 31.2300M, UnitsInStock = 15 },
                    new Product { ProductID = 27, ProductName = "Schoggi Schokolade", Category = "Confections", UnitPrice = 43.9000M, UnitsInStock = 49 },
                    new Product { ProductID = 28, ProductName = "Rössle Sauerkraut", Category = "Produce", UnitPrice = 45.6000M, UnitsInStock = 26 },
                    new Product { ProductID = 29, ProductName = "Thüringer Rostbratwurst", Category = "Meat/Poultry", UnitPrice = 123.7900M, UnitsInStock = 0 },
                    new Product { ProductID = 30, ProductName = "Nord-Ost Matjeshering", Category = "Seafood", UnitPrice = 25.8900M, UnitsInStock = 10 },
                    new Product { ProductID = 31, ProductName = "Gorgonzola Telino", Category = "Dairy Products", UnitPrice = 12.5000M, UnitsInStock = 0 },
                    new Product { ProductID = 32, ProductName = "Mascarpone Fabioli", Category = "Dairy Products", UnitPrice = 32.0000M, UnitsInStock = 9 },
                    new Product { ProductID = 33, ProductName = "Geitost", Category = "Dairy Products", UnitPrice = 2.5000M, UnitsInStock = 112 },
                    new Product { ProductID = 34, ProductName = "Sasquatch Ale", Category = "Beverages", UnitPrice = 14.0000M, UnitsInStock = 111 },
                    new Product { ProductID = 35, ProductName = "Steeleye Stout", Category = "Beverages", UnitPrice = 18.0000M, UnitsInStock = 20 },
                    new Product { ProductID = 36, ProductName = "Inlagd Sill", Category = "Seafood", UnitPrice = 19.0000M, UnitsInStock = 112 },
                    new Product { ProductID = 37, ProductName = "Gravad lax", Category = "Seafood", UnitPrice = 26.0000M, UnitsInStock = 11 },
                    new Product { ProductID = 38, ProductName = "Côte de Blaye", Category = "Beverages", UnitPrice = 263.5000M, UnitsInStock = 17 },
                    new Product { ProductID = 39, ProductName = "Chartreuse verte", Category = "Beverages", UnitPrice = 18.0000M, UnitsInStock = 69 },
                    new Product { ProductID = 40, ProductName = "Boston Crab Meat", Category = "Seafood", UnitPrice = 18.4000M, UnitsInStock = 123 },
                    new Product { ProductID = 41, ProductName = "Jack's New England Clam Chowder", Category = "Seafood", UnitPrice = 9.6500M, UnitsInStock = 85 },
                    new Product { ProductID = 42, ProductName = "Singaporean Hokkien Fried Mee", Category = "Grains/Cereals", UnitPrice = 14.0000M, UnitsInStock = 26 },
                    new Product { ProductID = 43, ProductName = "Ipoh Coffee", Category = "Beverages", UnitPrice = 46.0000M, UnitsInStock = 17 },
                    new Product { ProductID = 44, ProductName = "Gula Malacca", Category = "Condiments", UnitPrice = 19.4500M, UnitsInStock = 27 },
                    new Product { ProductID = 45, ProductName = "Rogede sild", Category = "Seafood", UnitPrice = 9.5000M, UnitsInStock = 5 },
                    new Product { ProductID = 46, ProductName = "Spegesild", Category = "Seafood", UnitPrice = 12.0000M, UnitsInStock = 95 },
                    new Product { ProductID = 47, ProductName = "Zaanse koeken", Category = "Confections", UnitPrice = 9.5000M, UnitsInStock = 36 },
                    new Product { ProductID = 48, ProductName = "Chocolade", Category = "Confections", UnitPrice = 12.7500M, UnitsInStock = 15 },
                    new Product { ProductID = 49, ProductName = "Maxilaku", Category = "Confections", UnitPrice = 20.0000M, UnitsInStock = 10 },
                    new Product { ProductID = 50, ProductName = "Valkoinen suklaa", Category = "Confections", UnitPrice = 16.2500M, UnitsInStock = 65 },
                    new Product { ProductID = 51, ProductName = "Manjimup Dried Apples", Category = "Produce", UnitPrice = 53.0000M, UnitsInStock = 20 },
                    new Product { ProductID = 52, ProductName = "Filo Mix", Category = "Grains/Cereals", UnitPrice = 7.0000M, UnitsInStock = 38 },
                    new Product { ProductID = 53, ProductName = "Perth Pasties", Category = "Meat/Poultry", UnitPrice = 32.8000M, UnitsInStock = 0 },
                    new Product { ProductID = 54, ProductName = "Tourtière", Category = "Meat/Poultry", UnitPrice = 7.4500M, UnitsInStock = 21 },
                    new Product { ProductID = 55, ProductName = "Pâté chinois", Category = "Meat/Poultry", UnitPrice = 24.0000M, UnitsInStock = 115 },
                    new Product { ProductID = 56, ProductName = "Gnocchi di nonna Alice", Category = "Grains/Cereals", UnitPrice = 38.0000M, UnitsInStock = 21 },
                    new Product { ProductID = 57, ProductName = "Ravioli Angelo", Category = "Grains/Cereals", UnitPrice = 19.5000M, UnitsInStock = 36 },
                    new Product { ProductID = 58, ProductName = "Escargots de Bourgogne", Category = "Seafood", UnitPrice = 13.2500M, UnitsInStock = 62 },
                    new Product { ProductID = 59, ProductName = "Raclette Courdavault", Category = "Dairy Products", UnitPrice = 55.0000M, UnitsInStock = 79 },
                    new Product { ProductID = 60, ProductName = "Camembert Pierrot", Category = "Dairy Products", UnitPrice = 34.0000M, UnitsInStock = 19 },
                    new Product { ProductID = 61, ProductName = "Sirop d'érable", Category = "Condiments", UnitPrice = 28.5000M, UnitsInStock = 113 },
                    new Product { ProductID = 62, ProductName = "Tarte au sucre", Category = "Confections", UnitPrice = 49.3000M, UnitsInStock = 17 },
                    new Product { ProductID = 63, ProductName = "Vegie-spread", Category = "Condiments", UnitPrice = 43.9000M, UnitsInStock = 24 },
                    new Product { ProductID = 64, ProductName = "Wimmers gute Semmelknödel", Category = "Grains/Cereals", UnitPrice = 33.2500M, UnitsInStock = 22 },
                    new Product { ProductID = 65, ProductName = "Louisiana Fiery Hot Pepper Sauce", Category = "Condiments", UnitPrice = 21.0500M, UnitsInStock = 76 },
                    new Product { ProductID = 66, ProductName = "Louisiana Hot Spiced Okra", Category = "Condiments", UnitPrice = 17.0000M, UnitsInStock = 4 },
                    new Product { ProductID = 67, ProductName = "Laughing Lumberjack Lager", Category = "Beverages", UnitPrice = 14.0000M, UnitsInStock = 52 },
                    new Product { ProductID = 68, ProductName = "Scottish Longbreads", Category = "Confections", UnitPrice = 12.5000M, UnitsInStock = 6 },
                    new Product { ProductID = 69, ProductName = "Gudbrandsdalsost", Category = "Dairy Products", UnitPrice = 36.0000M, UnitsInStock = 26 },
                    new Product { ProductID = 70, ProductName = "Outback Lager", Category = "Beverages", UnitPrice = 15.0000M, UnitsInStock = 15 },
                    new Product { ProductID = 71, ProductName = "Flotemysost", Category = "Dairy Products", UnitPrice = 21.5000M, UnitsInStock = 26 },
                    new Product { ProductID = 72, ProductName = "Mozzarella di Giovanni", Category = "Dairy Products", UnitPrice = 34.8000M, UnitsInStock = 14 },
                    new Product { ProductID = 73, ProductName = "Röd Kaviar", Category = "Seafood", UnitPrice = 15.0000M, UnitsInStock = 101 },
                    new Product { ProductID = 74, ProductName = "Longlife Tofu", Category = "Produce", UnitPrice = 10.0000M, UnitsInStock = 4 },
                    new Product { ProductID = 75, ProductName = "Rhönbräu Klosterbier", Category = "Beverages", UnitPrice = 7.7500M, UnitsInStock = 125 },
                    new Product { ProductID = 76, ProductName = "Lakkalikööri", Category = "Beverages", UnitPrice = 18.0000M, UnitsInStock = 57 },
                    new Product { ProductID = 77, ProductName = "Original Frankfurter grüne Soße", Category = "Condiments", UnitPrice = 13.0000M, UnitsInStock = 32 }
                     };

               schools = new List <School>();
                   schools.Add(new School { SchoolID = 1, Name = "IT-HTL" });
                   schools.Add(new School { SchoolID = 2, Name = "HAK" });
                   schools.Add(new School { SchoolID = 3, Name = "HAS" });

               employees = new List<Employee>();
                   employees.Add(new Employee { SchoolID = 1, EmployeeId = 1, EmployeeName = "Brachinger"});
                   employees.Add(new Employee { SchoolID = 2, EmployeeId = 2, EmployeeName = "Pirringer"});
                   employees.Add(new Employee { SchoolID = 1, EmployeeId = 3, EmployeeName = "Altmeier"});

                students = new List<Student> {
                     new Student { Id = 1, Name="Max", Subject="M" },
                     new Student { Id = 2, Name="Marie", Subject="M" },
                     new Student { Id = 3, Name="Franz", Subject="M" },
                     new Student { Id = 4, Name="Anna", Subject="N" }
                };

                marks = new List<Marking> {
                     new Marking { StudId = 1, Course="SEW", Mark=1 },
                     new Marking { StudId = 1, Course="INSY", Mark=2 },
                     new Marking { StudId = 1, Course="MEDT", Mark=3 },
                     new Marking { StudId = 2, Course="SEW", Mark=2}
                };

            // Customer/Order data read into memory from XML file using XLinq:
            customers = (
                from e in XDocument.Load("Customers.xml").
                          Root.Elements("customer")
                select new Customer
                {
                    CustomerID = (string)e.Element("id"),
                    CompanyName = (string)e.Element("name"),
                    Address = (string)e.Element("address"),
                    City = (string)e.Element("city"),
                    Region = (string)e.Element("region"),
                    PostalCode = (string)e.Element("postalcode"),
                    Country = (string)e.Element("country"),
                    Phone = (string)e.Element("phone"),
                    Fax = (string)e.Element("fax"),
                    Orders = (
                        from o in e.Elements("orders").Elements("order")
                        select new Order
                        {
                            OrderID = (int)o.Element("id"),
                            OrderDate = (DateTime)o.Element("orderdate"),
                            Total = (decimal)o.Element("total")
                        })
                        .ToArray()
                })
                .ToList();
        }
        static void Main(string[] args)
        {
            //0. Create list 
            createLists();
            
            //1) Finde alle Städte die mit L beginnen
            string[] cities = { "London", "Vienna", "Paris", "Linz", "Brussels" };
            Console.WriteLine("\n\nAufgabe 1: Städe die mit L beginnen:");
            var citiesWithL = from c in cities where c.StartsWith("L") orderby c select c;

            foreach (var n in citiesWithL)
                Console.Write(n + " ");


            //2) Finde alle Zahlen die groeßer als 5 sind und gib diese aufsteigend aus.
            int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
            Console.WriteLine("\n\nAufgabe 2: alle Zahlen größer 5");
            var highNums = from n in numbers where n > 5 select n;
            
            foreach (var n in highNums)
                Console.Write(" " + n);


            //3) Finde alle Produkte in products, wo mehr als 100 Stück auf Lager (unitsInStock > 100). 
            var inStockProducts = from p in products where p.UnitsInStock > 100 select p;

            Console.WriteLine("\n\nAufgabe 3:");
            
            foreach (var s in inStockProducts)
                Console.WriteLine($"{s.ProductID} {s.ProductName} UnitsInStock={s.UnitsInStock} ");


            //4) Finde alle Produkte in products, wo UnitsInStock >100 und der UnitsInPrice < 10 ist.
            var cheapInStockProducts = from p in products where p.UnitsInStock < 100 && p.UnitPrice < 10 select p;

            Console.WriteLine("\n\nAufgabe 4:");
            foreach (var e in cheapInStockProducts)
               Console.WriteLine($"{e.ProductID} {e.ProductName} UnitsInStock={e.UnitsInStock} prod.UnitPrice={e.UnitPrice}  ");


            //5) Finde alle Kunden in Deutschland (Germany).
            Console.WriteLine("\n\nAufgabe 5:");
            var germanyCustomers = from c in customers where c.Country.Equals("Germany") select c;

            foreach (var c in germanyCustomers)
                Console.WriteLine($"{c.CustomerID} {c.CompanyName} Country={c.Country} ");


            //6) Finde alle Wörter die länger als 4 Zeichen sind.
            string[] words = { "hello", "wonderful", "LINQ", "beautiful", "world" };
            Console.WriteLine("\n\nAufgabe 6:");
            var longWords = from w in words where w.Length > 4 select w;

            foreach (var s in longWords)
               Console.Write(s + " ");


            //7) Zeige alle Personen (employees) mit dem zugehörigen Schultyp an, die in die HTL gehen. 
            //(Tipp: Join über die Tabellen employees und schools) 
            Console.WriteLine("\n\nAufgabe 7:");
            var list = from e in employees
                       join s in schools on e.SchoolID equals s.SchoolID
                       where s.Name == "IT-HTL"
                       select new { e.EmployeeName, SchoolName = s.Name };

            foreach (var e in list) {
                Console.WriteLine("Employee Name = {0} , Department Name = {1}", e.EmployeeName, e.SchoolName); }

            
            //8) Gib von allen Personen (employees) nur die ersten drei Buchstaben aus. Bsp: Brachinger -> Bra
            Console.WriteLine("\n\nAufgabe 8:");
            var query = from e in employees select e.EmployeeName.Substring(0, 3);
            
            foreach (string s in query) Console.Write(" " + s);


            //9) Gib alle Zahlen von numbers in absteigender Reihenfolge aus
            Console.WriteLine("\n\nAufgabe 9: absteigend");
            var desList = from n in numbers orderby n descending select n; 
            
            foreach (int s in desList) Console.Write(" " + s);


            //10) Kommazahlen mit gerundeten Zahlen ausgeben. Beispiel: 3.5 4
            Console.WriteLine("\n\nAufgabe 10:");
            Console.Write("\nGib alle Kommazahlen und die zugehörige gerundete Zahl aus\n");

            var arr1 = new[] { 3.5, 9.2, 2.7, 8.7, 6.3, 5.2 };
            var roundNum = from n in arr1 select new {Number = n, roundNumber = Math.Round(n)};

            foreach (var a in roundNum)
                Console.WriteLine($"{a.Number} {a.roundNumber}");


            //11 Wie kann aus einer generischen Liste (List<int>) die 4 kleinsten Werte ausgegeben werden.
            Console.WriteLine("\n\nAufgabe 11:");
            List<int> templist = new List<int> { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
            
            /* dein Code */
            int n2 = 4;

            templist.Sort();

            Console.Write("\nDie {0} kleinsten Zahlen sind : \n", n2);
            foreach (int topn in templist.Take(n2))
            {
                Console.Write(topn + " ");
            }

            //12 Grouping - Gib alle Kategorien mit ihren Produkten aus
            //Kategorie soll nur 1 mal ausgegeben werden, dann alle Produkte zu dieser Kategorie
            Console.WriteLine("\n\nAufgabe 12:");
            Console.Write("\nGib alle Kategorien mit ihren zugehörigen Produkten aus.\n");

            var result = from p in products group p.ProductName by p.Category;
 
            
            foreach (var group in result)
            {
                Console.WriteLine(group.Key);
                foreach (string name in group) Console.WriteLine("  " + name);
            }
            


            //13 Grouping - Gib alle Kategorien mit der Anzahl der enthaltenen Produkte
            //Jede Kategorie soll mit der Anzahl der enthaltenen Produkte ausgegeben werden
            Console.WriteLine("\n\nAufgabe 13:");
            Console.Write("Gib alle Kategorien mit ihren zugehörigen Produkten aus.\n");

            var result1 = from p in products
                          group p by p.Category
                          into a
                          select new { Category = a.Key, Amount = a.Count() };

            
            foreach (var group in result1)
            {
                Console.WriteLine(group.Category + " - " + group.Amount);
            }
            


            //14 Join - Gib alle Studenten mit allen Noten aus 
            //Join über die Tabellen students und marks
            //als Ergebnis soll ein String (Name, Course, Mark) pro Student geliefert werden
            Console.WriteLine("\n\nAufgabe 14:");
            Console.Write("Gib alle Studenten mit ihren Noten aus.\n");

            var result3 = from s in students
                          join m in marks
                          on s.Id equals m.StudId
                          select s.Name + " " + m.Mark;

            
            foreach (String s in result3)
            {
                Console.WriteLine(s);
            }
            


            //15 Grouping mit into  
            Console.WriteLine("\n\nAufgabe 15:");
            Console.Write("Gib den Zweig (M oder N) mit der Anzahl aus .\n");

            var result4 = from s in students
                          group s by s.Subject
                          into g
                          select new { s = g.Key + " " + g.Count() };

            
            foreach (var s in result4)
            {
                Console.WriteLine(s);
            }
            

            //16 Group mit Join 
            Console.WriteLine("\n\nAufgabe 16:");
            Console.Write("Gib den Zweig (M oder N) mit der Anzahl aus .\n");

            var result5 = from s in students
                          join m in marks
                          on s.Id equals m.StudId
                          group m by s.Name
                          into g
                          select new { Name = g.Key, Marks = g};

            foreach (var x in result5)
            {
                Console.WriteLine(x.Name);
                foreach (var m in x.Marks)
                {
                    Console.WriteLine("  " + m.Course + ", " + m.Mark);
                }
            }
            


            //let Beispeil
            var result6 =
                 from s in students
                 where s.Subject == "Computing"
                 let year = s.Id / 1000
                 where year == 2009
                 select s.Name;

            //weitere Methoden
            /*
            e.Any(i => i < 0)   true, if any element of e is < 0
            e.All(i => i > 0)   true, if all elements of e are > 0
            e.Take(3)   takes the first 3 elements of e
            e.Skip(2)   drops the first 2 elements of e
            e.TakeWhile(i => i < 1000)  takes elements from e as long as predicate is true
            e.SkipWhile(i => i < 100)   drops elements from e as long as predicate is true
            e.Distinct()    yields e without duplicates
            e.Concat(e2)    appends e2 to e
            e.Reverse() yields e in reverse order
            e.ToList()  converts an IEnumerable<T> into a List<T>
            e.ToArray() converts an IEnumerable< T > into a T[]
            */
                       
            Console.WriteLine("\n\nEnde - Geschafft");
            Console.ReadLine();

        }
    }
}
