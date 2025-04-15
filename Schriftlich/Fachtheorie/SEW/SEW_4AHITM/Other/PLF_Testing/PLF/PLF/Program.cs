using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PLF
{
    internal class Program
    {
        public static void Main(string[] args) 
        {
            Console.WriteLine("Hello World.");
            //CreateExampleClassesAndRelations();
            using (StarshipContext context = new StarshipContext())
            {
                Engineer engineer = new Engineer { EngineerName = "Florence Ambross" };
                Engineer engineer1 = new Engineer { EngineerName = "Felicity Farseer" };

                Starship? flurryWinter = (from s in context.Starships where s.Name == "Flurry Winter" select s).FirstOrDefault();

                flurryWinter.Engineers.Add(engineer1);
                flurryWinter.Engineers.Add(engineer);

                Starship? sunk = (from s in context.Starships where s.Name == "The Sunkn Norwegian" select s).FirstOrDefault();
                sunk.Engineers.Add(engineer);

                context.Add(engineer);
                context.Add(engineer1);
                context.SaveChanges();
            }

            /*using (StarshipContext context = new StarshipContext())
            {
                var CaptainsShips = from c in context.Captains
                                    join s in context.Starships
                                    on c.CaptainID equals s.Captain.CaptainID
                                    select new
                                    {
                                        Captain = c.CaptainName,
                                        Ship = s.Name
                                    };

                foreach (var a in CaptainsShips) 
                {
                    Console.WriteLine(a.Captain + " " + a.Ship);
                }

                var CaptainsShips2 = from c in context.Captains
                                    join s in context.Starships
                                    on c.CaptainID equals s.Captain.CaptainID
                                    group s by c into g
                                    select new
                                    {
                                        Captain = g.Key.CaptainName,
                                        Ships = g.ToList()
                                    };

                foreach (var a in CaptainsShips2)
                {
                    Console.WriteLine(a.Captain);

                    foreach (var b in a.Ships)
                    {
                        Console.WriteLine(b.Name);
                    }
                }

                var CC = from cap in context.Captains
                         join ship in context.Starships on cap.CaptainID equals ship.Captain.CaptainID
                         join comp in context.Components on ship.StarshipID equals comp.Starship.StarshipID
                         where cap.CaptainName == "Zoe McFife"
                         group comp by cap into g
                         select new
                         {
                             Captain = g.Key.CaptainName,
                             Components = g.ToList().Select(c => c.Type)
                         };
                
                foreach(var a in CC)
                {
                    Console.WriteLine(a.Captain);

                    foreach (var b in a.Components)
                    {
                        Console.WriteLine(b);
                    }
                }
                

            } */

        }

        public static void CreateExampleClassesAndRelations()
        {
            using (StarshipContext context = new StarshipContext()) 
            {
                // Create a captain
                Captain captain = new Captain("Captain Kirk");

                // Create a starship
                Starship starship = new Starship("Enterprise");

                // Assign the captain to the starship
                starship.Captain = captain;

                // Add the starship to the captain's collection of starships
                captain.Starships = new List<Starship> { starship };

                // Create some components
                Component component1 = new Component("Warp Drive");
                Component component2 = new Component("Photon Torpedoes");

                // Assign the starship to the components
                component1.Starship = starship;
                component2.Starship = starship;

                // Add the components to the starship's collection of components
                starship.Components = new List<Component> { component1, component2 };

                Captain zoe = new Captain("Zoe McFife");
                Starship FlurryWinter = new Starship("Flurry Winter");

                FlurryWinter.Captain = zoe;

                Component abyssDrive = new Component("Abyss Drive");
                Component shieldGen = new Component("Class 8 ShieldGen");

                abyssDrive.Starship = FlurryWinter;
                shieldGen.Starship = FlurryWinter;

                Starship sunknNorwegian = new Starship("The Sunkn Norwegian");
                Component abyssDrive2 = new Component("Abyss Drive");
                Component shieldGen2 = new Component("Class 4 ShieldGen");
                Component pew = new Component("WEAPONS");

                sunknNorwegian.Captain = zoe;

                abyssDrive2.Starship = sunknNorwegian;
                shieldGen2.Starship = sunknNorwegian;
                pew.Starship = sunknNorwegian;

                context.Captains.Add(captain);
                context.Captains.Add(zoe);

                // Add starships to the context
                context.Starships.Add(starship);
                context.Starships.Add(FlurryWinter);
                context.Starships.Add(sunknNorwegian);

                // Add components to the context
                context.Components.Add(component1);
                context.Components.Add(component2);
                context.Components.Add(abyssDrive);
                context.Components.Add(shieldGen);
                context.Components.Add(abyssDrive2);
                context.Components.Add(shieldGen2);
                context.Components.Add(pew);

                // Save changes to the database
                context.SaveChanges();
            }
        }

    }
}


