package Arithmetics;

import javax.swing.*;

public class Main
{
    public static void main(String[] args)
    {
        JFrame frame = new JFrame("Trainer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        TrainerView view = new TrainerView();
        TrainerModel model = new TrainerModel();
        TrainerController controller = new TrainerController(view, model);

        frame.add(view);
        frame.pack();
        frame.setVisible(true);
    }
}
