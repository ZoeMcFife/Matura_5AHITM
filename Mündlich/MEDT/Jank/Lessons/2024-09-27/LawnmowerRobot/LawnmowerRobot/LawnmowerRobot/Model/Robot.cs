namespace LawnmowerRobot.Model
{
    public class Robot
    {
        public int Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Type {  get; set; } = string.Empty;
        public DateTime LastUse { get; set; }

        public virtual List<Position> Positions { get; set; } = new List<Position>();
    }
}
