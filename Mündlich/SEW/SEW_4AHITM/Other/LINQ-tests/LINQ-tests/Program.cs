namespace LINQ_tests
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class Artist
    {
        public int ArtistId { get; set; }
        public string Name { get; set; }
    }

    public class Album
    {
        public int AlbumId { get; set; }
        public int ArtistId { get; set; }
        public string Title { get; set; }
        public int ReleaseYear { get; set; }
    }

    public class Song
    {
        public int SongId { get; set; }
        public int AlbumId { get; set; }
        public string Title { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Artist> artists = new List<Artist>
        {
            new Artist { ArtistId = 824, Name = "Miley Cyrus" },
            new Artist { ArtistId = 876, Name = "Nina Chuba" },
            new Artist { ArtistId = 716, Name = "Apache 207" }
        };

            List<Album> albums = new List<Album>
        {
            new Album { AlbumId = 1035, ArtistId = 824, Title = "Endless Summer Vacation", ReleaseYear = 2023 },
            new Album { AlbumId = 647, ArtistId = 824, Title = "Plastic Hearts", ReleaseYear = 2020 },
            new Album { AlbumId = 1064, ArtistId = 876, Title = "Glas", ReleaseYear = 2023 },
            new Album { AlbumId = 998, ArtistId = 716, Title = "Komet", ReleaseYear = 2023 }
        };

            List<Song> songs = new List<Song>
        {
            new Song { SongId = 1346, AlbumId = 1035, Title = "Flowers" },
            new Song { SongId = 1357, AlbumId = 1035, Title = "River" },
            new Song { SongId = 1348, AlbumId = 1035, Title = "You" },
            new Song { SongId = 875, AlbumId = 647, Title = "Midnight Sky" },
            new Song { SongId = 875, AlbumId = 647, Title = "Hate Me" },
            new Song { SongId = 1268, AlbumId = 1064, Title = "Wildberry Lilet" },
            new Song { SongId = 1272, AlbumId = 1064, Title = "Mangos mit Chili" },
            new Song { SongId = 1246, AlbumId = 998, Title = "Komet" }
        };

            // Now that the data is properly defined, let's write LINQ queries

            // 1. All song titles by Miley Cyrus

            var a = from artist in artists
                    join album in albums
                    on artist.ArtistId equals album.ArtistId
                    group album by artist into g
                    select new
                    {
                        Artist = g.Key.Name,
                        Albums = g.ToList().Select(a => a.Title)
                    };

            foreach (var arrr in a)
            {
                Console.WriteLine(arrr.Artist);
                foreach (var ar in arrr.Albums) 
                {
                    Console.WriteLine(ar);
                }
            }



            /*var mileySongs = from song in songs
                             join album in albums on song.AlbumId equals album.AlbumId
                             join artist in artists on album.ArtistId equals artist.ArtistId
                             where artist.Name == "Miley Cyrus"
                             select song.Title;


            var artistsWithTwoAlbums = from artist in artists
                                       join album in albums
                                       on artist.ArtistId equals album.ArtistId
                                       group album by artist into g
                                       where g.ToList().Count() >= 2
                                       select new
                                       {
                                           ArtistName = g.Key.Name,
                                           AlbumCount = g.ToList().Count()
                                       };
            */



        }
    }

}