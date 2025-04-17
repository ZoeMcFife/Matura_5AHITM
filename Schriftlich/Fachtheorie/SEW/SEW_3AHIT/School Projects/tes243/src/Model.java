import javax.swing.*;

public class Model
{
    public void swapText(JLabel label, String text) throws NumberException
    {
        if (text.equals("3"))
        {
            label.setText("E");
            throw new NumberException();
        }

        label.setText(text);
    }
}
