import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ConverterController
{
    ConverterModel model;
    ConverterView view;

    public ConverterController(ConverterView view, ConverterModel model)
    {
        this.view = view;
        this.model = model;

        view.convertButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                model.convert(view);
            }
        });
    }
}
