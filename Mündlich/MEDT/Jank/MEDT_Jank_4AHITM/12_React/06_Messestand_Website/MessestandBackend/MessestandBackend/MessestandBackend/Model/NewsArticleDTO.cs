namespace MessestandBackend.Model
{
    public class NewsArticleDTO
    {
        public int Id { get; set; }
        public string Title { get; set; } = string.Empty;
        public string Content { get; set; } = string.Empty;
        public int PublishedBy { get; set; }

        public NewsArticleDTO() { }

        public NewsArticleDTO(NewsArticle newsArticle)
        {
            Id = newsArticle.Id;
            Title = newsArticle.Title;
            Content = newsArticle.Content;
            PublishedBy = newsArticle.PublishedBy.Id;
        }
    }
}
