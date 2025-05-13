import javax.swing.*;
import java.awt.*;

public class PrimeTest
{
    public static void main(String[] args)
    {
        JFrame jFrame = new JFrame("Prime Number");
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.setSize(500, 500);

        // Create vie
        PrimeView view = new PrimeView();
        // cteate model
        PrimeModel model = new PrimeModel();
        // create Controller
        PrimeController controller = new PrimeController(model, view);


        jFrame.add(view);
        jFrame.pack();
        jFrame.setVisible(true);
    }
}
