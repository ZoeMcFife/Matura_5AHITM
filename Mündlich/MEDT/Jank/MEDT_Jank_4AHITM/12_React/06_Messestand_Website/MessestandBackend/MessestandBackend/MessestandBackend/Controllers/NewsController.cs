using MessestandBackend.Model;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace MessestandBackend.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class NewsController : ControllerBase
    {

        private GalacticNewsContext _context;

        public NewsController(GalacticNewsContext context)
        {
            _context = context;
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<NewsArticleDTO>> GetNews(int id)
        {
            var news = await _context.newsArticles.FindAsync(id);

            if (news == null)
            {
                return NotFound();
            }

            return Ok(new NewsArticleDTO(news));
        }

        [HttpGet]
        public async Task<ActionResult<ICollection<NewsArticleDTO>>> GetAllNews()
        {
            return Ok(await _context.newsArticles.Select(n => ConvertToNewsDTO(n)).ToListAsync());
        }

        [HttpPost("{userId}")]
        public async Task<ActionResult<NewsArticleDTO>> PostNews(int userId, NewsArticleDTO news)
        {
            var user = await _context.users.FindAsync(userId);

            if (user == null || user.Role == UserRole.Visitor)
            {
                return BadRequest();
            }

            Console.WriteLine(news.Id + " " + news.Title + " " + news.PublishedBy);

            var newsDb = new NewsArticle();
            
            newsDb.Title = news.Title;
            newsDb.Content = news.Content;
            newsDb.Id = news.Id;
            newsDb.PublishedBy = user;

            _context.Add(newsDb);

            await _context.SaveChangesAsync();

            return CreatedAtAction(nameof(GetNews), new { id = news.Id }, news);
        }

        [HttpDelete("{userId}/{id}")]
        public async Task<ActionResult<NewsArticleDTO>> DeleteNews(int userId, int id)
        {
            var user = await _context.users.FindAsync(userId);

            if (user == null || user.Role == UserRole.Visitor)
            {
                return BadRequest();
            }

            var news = await _context.newsArticles.FindAsync(id);

            if (news == null)
            {
                return NotFound(nameof(GetNews));
            }

            _context.newsArticles.Remove(news);

            await _context.SaveChangesAsync();

            return Ok(news);
        }

        private NewsArticleDTO ConvertToNewsDTO(NewsArticle news)
        {
            return new NewsArticleDTO(news);
        }

    }
}
