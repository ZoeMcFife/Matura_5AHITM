using Microsoft.EntityFrameworkCore;

namespace EntityFrameworkCoreTest
{
    internal class Program
    {
        static void Main(string[] args)
        {
            using (var context = new BlogContext()) 
            {
                //var blog = new Blog { URL = "mynewblog.con" };
                //context.Add(blog);
                //context.SaveChanges();

                var blogs = (from b in context.Blogs where b.BlogID == 1 select b).First();

                Console.WriteLine(blogs.URL);

                foreach (var pst in blogs.Posts)
                {
                    Console.WriteLine(pst.Title);
                }

                //var post = new Post { Blog = blogs, Content = "TestContent", Title = "TestTitle"};
                //context.Add(post);

                context.SaveChanges();

                var anotherPost = (from p in context.Posts
                                   where p.PostID == 1 select p).First();

                context.Remove(anotherPost);

                context.SaveChanges();

            }
        }
    }
}