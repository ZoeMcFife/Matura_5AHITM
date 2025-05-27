namespace MessestandBackend.Model
{
    public class NewsArticle
    {
        public int Id { get; set; }
        public string Title { get; set; }
        public string Content { get; set; }
        public virtual User PublishedBy {  get; set; }
    }
}
