namespace PLF_BSP2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Ex3();
        }

        public static void Ex1()
        {
            Console.WriteLine("Ermittle die Fälle vom 3.5.2020 für alle Länder aus Europa mit einer Bevölkerung von mehr als 10 Millionen Einwohner*innen.");

            using (var context = new CovidContext())
            {
                var cases = from c in context.Cases
                            where c.DateRep == "2022-05-03" && c.Geo.ContinentExp == "Europe" && c.Geo.PopData2018 >= 10000000
                            select c;

                foreach (var c in cases)
                {
                    Console.WriteLine(c.Id);
                }
            }
        }

        public static void Ex2()
        {
            Console.WriteLine("Gib die Anzahl der auftretenden Fälle pro Land (CountriesAndTerretories) vom Feburar 2020 in absteigender Reihenfolge aus.");

            using (var context = new CovidContext())
            {
                var cases = from c in context.Cases
                            join co in context.Countries
                            on c.Geo.Id equals co.Id
                            where c.DateRep.Substring(0, 7).Equals("2020-02")
                            orderby c.Cases descending
                            group c by co into g
                            select new
                            {
                                Country = g.Key.GeoId,
                                Cases = g.ToList().Sum(e => e.Cases)
                            };

                foreach (var c in cases)
                {
                    Console.WriteLine(c.Country + " " + c.Cases);
                }


            }
        }

        public static void Ex3()
        {
            Console.WriteLine("Ermittle in welchem Land die meisten Fällen im Mai 2020 auftraten und gib die Anzahl an Einwohnern, Anzah an Fällen und den Landnamen aus.");


            using (var context = new CovidContext())
            {
                var casesMay =  from c in context.Cases
                                where c.DateRep.Substring(0, 7).Equals("2020-05")
                                orderby c.Cases descending
                                select c;

                foreach (var c in casesMay)
                {
                    Console.WriteLine(c.Cases + " " + c.Geo.PopData2018 + " " + c.Geo.GeoId);
                }
            }
        }
    }
}

/*
 * Ermittle die Fälle vom 3.5.2020 für alle Länder aus Europa mit einer Bevölkerung von mehr als 10 Millionen
Einwohner*innen.
• Gib die Anzahl der auftretenden Fälle pro Land (CountriesAndTerretories) vom Feburar 2020 in absteigender
Reihenfolge aus.
• Ermittle in welchem Land die meisten Fällen im Mai 2020 auftraten und gib die Anzahl an Einwohnern, Anzahl
an Fällen und den Landnamen aus.
• Ermittle den Tag mit den meisten Fällen von allen Ländern die mit ‘A’ beginnen.
Bonus
• Gib alle Fallraten mit den zugehörigen Namen der Länder vom Februar 2020 aus. (Fallrate ergibt sich aus den
Fällen pro 1000 Einwohner*innen
 * 
 * */