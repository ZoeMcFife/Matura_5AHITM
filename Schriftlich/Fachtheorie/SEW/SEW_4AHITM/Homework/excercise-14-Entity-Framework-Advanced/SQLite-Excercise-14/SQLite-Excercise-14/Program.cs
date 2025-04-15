using System.ComponentModel.DataAnnotations;
using System.Globalization;
using System.Security.Cryptography;

namespace SQLite_Excercise_14 
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /* Console.WriteLine("Hello, World!");

             using (var context = new ExampleContext())
             {
                 var track = context.Genres
                     .Where(g => g.Name == "Rock")
                     .SelectMany(g => g.Tracks)
                     .OrderBy(t => t.Milliseconds);

                 // in LINQ

                 var trackLinq = from g in context.Genres
                                 where g.Name == "Rock"
                                 from t in g.Tracks
                                 orderby t.Milliseconds
                                 select t;

                 foreach (var t in trackLinq)
                     Console.WriteLine(t.Name);
             }*/

            PeopleNamedFrank();
            MoreThan5AlbumTracks();
            ShowAllTracks(false);
            MostSpent();
            EmployessThatSoldZecaVoilica();
            BestSalesAgent();
            CustomersOfEachSalesAgent();
            GetBrazilians();
            PeopleListeningToRock();
            Invoices20092011();
        }

        public static void Invoices20092011()
        {
            PrintTitle("How many Invoices were there in 2009 and 2011? What are the respective total sales for each of those years?");

            using (var context = new ExampleContext())
            {
                var invoices = from i in context.Invoices
                               where i.InvoiceDate.Year >= 2009 || i.InvoiceDate.Year >= 2011
                               select i;

                var totalsPerYear = from i in invoices
                                    group i by i.InvoiceDate.Year into g
                                    select new
                                    {
                                        Year = g.Key,
                                        Invoices = g.ToList().Count(),
                                        Total = g.Sum(i => i.Total),
                                    };

                foreach (var t in totalsPerYear)
                    Console.WriteLine(t.Year + " " + t.Invoices + " Invoices " + t.Total + "$ Total");
            }

            Console.WriteLine();
        }

        public static void PeopleListeningToRock()
        {
            PrintTitle("How many customers are listening to Rock music?");

            using (var context = new ExampleContext())
            {
                var customers = (from c in context.Customers
                                from i in c.Invoices
                                from ii in i.InvoiceItems
                                where ii.Track.Genre.Name.Equals("Rock")
                                select c).Distinct();

                Console.WriteLine(customers.Count() + " customers listen to Rock.");
            }

            Console.WriteLine();
        }

        public static void PrintTitle(string title)
        {
            string titleHeader = string.Empty;

            for (int i = 0; i < title.Length; i++)
                titleHeader += "=";


            Console.WriteLine(titleHeader);
            Console.WriteLine(title);
            Console.WriteLine(titleHeader);
        }

        public static void GetBrazilians()
        {
            PrintTitle("What customers are from Brazil? Print the customer’s full name, Invoice ID, Date of the invoice and billing country.");

            using (var context = new ExampleContext())
            {
                var customers = from i in context.Invoices
                                where i.Customer.Country == "Brazil"
                                select new
                                {
                                    Name = i.Customer.FirstName + " " + i.Customer.LastName,
                                    InvoiceID = i.InvoiceId,
                                    InvoiceDate = i.InvoiceDate,
                                    BillingCountry = i.Customer.Country
                                };

                foreach (var s in customers)
                    Console.WriteLine(s.Name + " | " + s.InvoiceID + " | " + s.InvoiceDate + " | " + s.BillingCountry);
            }

            Console.WriteLine();
        }

        public static void CustomersOfEachSalesAgent()
        {
            PrintTitle("How many customers are assigned to each sales agent?");

            using (var context = new ExampleContext())
            {
                var salesAgents = from e in context.Employees
                                  where e.Title == "Sales Support Agent"
                                  select new
                                  {
                                      Name = e.FirstName + " " + e.LastName,
                                      Customers = e.Customers.Count
                                  };

                foreach (var s in salesAgents)
                    Console.WriteLine(s.Name + " has " + s.Customers + " Customers.");
            }



            Console.WriteLine();
        }

        public static void BestSalesAgent()
        {
            PrintTitle("Which sales agent made the most in sales in 2010?");

            using (var context = new ExampleContext())
            {
                var invoiceItems2010 = from e in context.InvoiceItems
                                   where e.Invoice.InvoiceDate.Year == 2010
                                   select new
                                   {   
                                       InvoiceItem = e,
                                       SalesAgent = e.Invoice.Customer.SupportRep
                                   };

                var salesAgentsWithTotals = from i in invoiceItems2010
                                            orderby i.InvoiceItem.UnitPrice descending
                                            group i.InvoiceItem.UnitPrice by i.SalesAgent into g
                                            select new
                                            {
                                                SalesAgent = g.Key,
                                                Profit = g.ToList().Sum()
                                            };





                //var salesAgents = from i in invoiceItems
                //                group i.SalesAgent by i.InvoiceItem into g


                Console.WriteLine("Most profitable Sales Agent in 2010:");
                Console.WriteLine(salesAgentsWithTotals.FirstOrDefault().SalesAgent.FirstName + " " + salesAgentsWithTotals.FirstOrDefault().SalesAgent.LastName);

                Console.WriteLine("Others: ");

                foreach (var item in salesAgentsWithTotals)
                {
                    Console.WriteLine("Sales Agent " + item.SalesAgent.FirstName + " " + item.Profit);
                }
            }

            Console.WriteLine();


        }

        public static void EmployessThatSoldZecaVoilica()
        {
            PrintTitle("What employees sold the track “Zeca Violeiro”?");

            // There isn't any table that indicates employees selling stuff
            // so I assume i have to get the SupportRep of each customer that has an Invoice
            // with Zeca Violeira as an Invoice Item
            // only Employee 5 Steve Johnson should come out

            using (var context = new ExampleContext())
            {
                var employess = from invoiceItem in context.InvoiceItems
                                where invoiceItem.Track.Name == "Zeca Violeiro"
                                select invoiceItem.Invoice.Customer.SupportRep;

                foreach (var e in employess)
                    Console.WriteLine(e.EmployeeId);
            }

            Console.WriteLine();
        }

        public static void MostSpent()
        {
            PrintTitle("What customer spent the most amount of money?");

            using (var context = new ExampleContext())
            {
                var invoices = from c in context.Invoices
                               select new
                               {
                                   CustomerId = c.CustomerId,
                                   Total = c.Total
                               };        

                var customers = from c in context.Customers.AsEnumerable()
                                join i in invoices on c.CustomerId equals i.CustomerId
                                group i.Total by c.CustomerId into g
                                select new
                                {
                                    Customer = g.Key,
                                    Total = g.ToList().Sum()
                                };

                var whales = from c in customers
                             join c2 in context.Customers
                             on c.Customer equals c2.CustomerId
                             where c.Total == customers.Max(x => x.Total)
                             select new
                             {
                                 Name = c2.FirstName + " " + c2.LastName,
                                 Spent = c.Total
                             };

                foreach (var c in whales)
                    Console.WriteLine(c.Name + " " + c.Spent);
            }

            Console.WriteLine();
        }


        public static void PeopleNamedFrank()
        {
            PrintTitle("How many customers are named “Frank”?");

            using (var context = new ExampleContext())
            {
                var franks = from f in context.Customers
                             where f.FirstName == "Frank"
                             select f;

                Console.WriteLine("There are " + franks.Count() + " Franks.");
                Console.WriteLine();

                foreach (var f in franks)
                    Console.WriteLine(f.FirstName + " " + f.LastName);
            }

            Console.WriteLine();
        }

        public static void MoreThan5AlbumTracks()
        {
            PrintTitle("Get all albums where more than 5 tracks are on the albums and sort them by number of tracks (desc).");

            using (var context = new ExampleContext())
            {
                var albums = from a in context.Albums
                             where a.Tracks.Count > 5
                             orderby a.Tracks.Count descending
                             select new
                             {
                                 Title = a.Title,
                                 TrackCount = a.Tracks.Count
                             };

                Console.WriteLine("Found " + albums.Count() + " Albums.");

                foreach (var album in albums)
                {
                    Console.WriteLine("Titele: " + album.Title + " | " + album.TrackCount + " Tracks");
                }
            }

            Console.WriteLine();
        }

        public static void ShowAllTracks(bool ShowTracks)
        {
            PrintTitle("Show all the tracks and print the Album Name, Artist Name and Media Type.");

            using (var context = new ExampleContext())
            {
                var tracks = from t in context.Tracks
                             select new
                             {
                                 Track = t,
                                 AlbumName = t.Album.Title,
                                 Artist = t.Album.Artist.Name,
                                 MediaType = t.MediaType.Name
                             };

                if (!ShowTracks)
                {
                    Console.WriteLine("Found " + tracks.Count() + " Tracks.");
                    Console.WriteLine("Set ShowTracks to True in the method call to show all tracks.");
                    Console.WriteLine();
                    return;
                }

                foreach (var track in tracks)
                {
                    PrintTitle("Track");
                    Console.WriteLine(track.Track.Name);
                    Console.WriteLine(track.AlbumName);
                    Console.WriteLine(track.Artist);
                    Console.WriteLine(track.MediaType);
                    Console.WriteLine();
                }
            }

            Console.WriteLine();
        }


    }
}