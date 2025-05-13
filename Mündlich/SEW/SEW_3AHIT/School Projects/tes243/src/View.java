import javax.swing.*;
import java.awt.*;

public class View extends JPanel
{
   public JLabel label;
   public JButton button;
   public JTextField textField;

   View()
   {
      this.setLayout(null);

      this.label = new JLabel();
      this.label.setSize(200, 200);
      this.label.setBounds(20, 20, 300, 300);

      this.button = new JButton("New Text");
      this.button.setSize(100, 100);
      this.button.setBounds(350, 20, 120, 120);

      this.textField = new JTextField();
      this.textField.setSize(200, 80);
      this.textField.setBounds(50, 400, 250, 100);

      this.add(this.label);
      this.add(this.button);
      this.add(this.textField);
   }
}
