namespace LawnmowerRobot.Model
{
    public class Position
    {
        public int Id {  get; set; }
        public long Latitude {  get; set; }
        public long Longitude { get; set; }
        public string Event { get; set; } = string.Empty;
        public int Battery { get; set; }

        public virtual Robot? Robot { get; set; }
    }
}
