namespace MessestandBackend.Model
{
    public class UserDTO
    {
        public int Id { get; set; }
        public string Name { get; set; } = string.Empty;

        public UserRole Role { get; set; } = UserRole.Visitor;

        public UserDTO() { }

        public UserDTO(User user) 
        { 
            Id = user.Id;
            Name = user.Name;
            Role = user.Role;
        }
    }
}
