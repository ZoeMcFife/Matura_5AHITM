import javax.swing.*;
import javax.swing.text.ComponentView;

public class Main
{
    public static void main(String[] args)
    {
        JFrame jFrame = new JFrame("Converter");

        ConverterView view = new ConverterView();
        ConverterModel model = new ConverterModel();
        ConverterController controller = new ConverterController(view, model);

        jFrame.setVisible(true);
        jFrame.add(view);
        jFrame.setSize(400, 400);
    }
}
