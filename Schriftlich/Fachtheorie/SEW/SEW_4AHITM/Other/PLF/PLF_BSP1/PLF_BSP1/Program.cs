using Microsoft.EntityFrameworkCore;

namespace PLF_BSP1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //CreateShow();
            UpdateEpisode(1, 80);
            //DeleteEpisode(3);

        }

        public static void CreateShow()
        {
            using (TVContext context = new TVContext())
            {
                Show show = new Show { Name = "Bojack Horseman", ReleaseYear = 2016 };

                Episode ep1 = new Episode { Name = "The View from Halfway Down", Length = 20, Season = 5, ReleaseDate = DateTime.Now, Seen = true };
                Episode ep2 = new Episode { Name = "Another Episode", Length = 20, Season = 1, ReleaseDate = DateTime.Now, Seen = false };
                Episode ep3 = new Episode { Name = "Free Churro", Length = 20, Season = 5, ReleaseDate = DateTime.Now, Seen = false };

                show.Episodes.Add(ep3);
                context.Add(ep3);

                show.Episodes.Add(ep1);
                show.Episodes.Add(ep2);

                context.Add(show);
                context.Add(ep1);
                context.Add(ep2);

                context.SaveChanges();
            }
        }

        public static void UpdateEpisode(int episodeID, int newTime)
        {
            using (TVContext context = new TVContext())
            {
                var episode = (from e in context.Episodes where e.ID == episodeID select e) as Episode;

                episode.Length = newTime;

                context.Update(episode);

                context.SaveChanges();
            }
        }

        public static void DeleteEpisode(int episodeID)
        {
            using (TVContext context = new TVContext())
            {
                Episode episode = (Episode)(from e in context.Episodes where e.ID == episodeID select e);

                context.Remove(episode);

                context.SaveChanges();
            }
        }

    }
}

/*
 * Nutze die Features vom EntityFramework um ein sauberes Mapping zu gewährleisten.
• Erstelle eine SQLite Datenbankdatei (bitte mit abgeben)
• Schreibe eine Methode die deine Lieblingsserie und ein min. 2 Folgen erstellt
• Schreibe eine Methode die die Laufzeit von einer der Folgen verändert.
• Schreibe eine Methode die eine Folge aus den Daten lösch
*/