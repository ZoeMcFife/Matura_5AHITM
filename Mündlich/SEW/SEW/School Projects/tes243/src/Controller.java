import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Controller
{
    private View view;
    private Model model;

    public Controller(View view, Model model)
    {
        this.model = model;
        this.view = view;

        this.view.button.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                try
                {
                    model.swapText(view.label, view.textField.getText());
                }
                catch (NumberException a)
                {
                    a.printStackTrace();
                }
            }
        });
    }
}
