import javax.swing.*;

public class ConverterView extends JPanel
{
    public JTextField temperatureInputTextField;
    public JLabel currentUnitLabel;
    public JButton convertButton;
    public JLabel convertedTemperatureLabel;

    ConverterView()
    {
        this.setLayout(null);

        //        temperatureInputTextField.setSize(100, 50);
        temperatureInputTextField = new JTextField();
        temperatureInputTextField.setBounds(10, 10, 100, 30);

        currentUnitLabel = new JLabel("Celsius");
        currentUnitLabel.setBounds(120, 10, 50, 30);

        convertButton = new JButton("Convert");
        convertButton.setBounds(10, 50, 100, 30);

        convertedTemperatureLabel = new JLabel();
        convertedTemperatureLabel.setBounds(120, 50, 130, 30);

        this.add(temperatureInputTextField);
        this.add(currentUnitLabel);
        this.add(convertButton);
        this.add(convertedTemperatureLabel);
    }

}
