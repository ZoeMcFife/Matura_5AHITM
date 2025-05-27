namespace MessestandBackend.Model
{
    public class User
    {

        public int Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Password { get; set; } = string.Empty;
      
        public UserRole Role { get; set; } = UserRole.Visitor;

        public User() {}

        public User(string name)
        {
            Name = name;
        }

        public User(string name, string password) : this(name)
        {
            Password = password;
        }
    }
}
