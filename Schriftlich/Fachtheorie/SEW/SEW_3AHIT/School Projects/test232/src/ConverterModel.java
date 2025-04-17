public class ConverterModel
{
    public double convertToFahrenheit(double celsius)
    {
        return (9.0 / 5) * celsius + 32;
    }

    public void convert(ConverterView view)
    {
        double inputTemperature;
        double outputTemperature;
        inputTemperature = Double.parseDouble(view.temperatureInputTextField.getText());

        outputTemperature = convertToFahrenheit(inputTemperature);

        view.convertedTemperatureLabel.setText(outputTemperature + "° Fahrenheit");
    }
}
