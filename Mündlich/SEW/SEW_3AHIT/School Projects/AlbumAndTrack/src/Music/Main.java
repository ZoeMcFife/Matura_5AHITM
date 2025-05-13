package Music;

public class Main
{
    public static void main(String[] args)
    {
        Track[] tracks1 = {
                new Track("Infernus Ad Astra", "", 84),
                new Track("Rise of the Chaos Wizards", "", 237),
                new Track("Legend of the Astral Hammer", "", 314),
                new Track("Goblin King of the Darkstorm Galaxy", "", 229),
                new Track("The Hollywood Hootsman", "", 235),
                new Track("Victorious Eagle Warfare", "", 299),
                new Track("Questlords of Inverness, Ride to The Galactic Fortress!", "", 323),
                new Track("Universe on Fire", "", 246),
                new Track("Heroes (of Dundee)", "", 350),
                new Track("Apocalypse 1992", "", 579)
        };

        Album Space1992 = new Album("Space 1992: Rise of the Chaos Wizards", "Gloryhammer", tracks1);

        Space1992.printInfo();

    }
}
