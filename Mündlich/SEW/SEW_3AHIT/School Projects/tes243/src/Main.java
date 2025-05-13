import javax.swing.*;

public class Main
{
    public static void main(String[] args)
    {
        JFrame frame = new JFrame("Frame");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        View view = new View();
        Model model = new Model();
        Controller controller = new Controller(view, model);

        frame.setSize(600, 600);
        frame.add(view);
        frame.setVisible(true);
    }
}
