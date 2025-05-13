package rgb.color.rgbeditor;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class RGBController
{
    @FXML
    private Slider redSlider;
    @FXML
    private Slider greenSlider;
    @FXML
    private Slider blueSlider;
    @FXML
    private Rectangle colorPreviewBox;
    @FXML
    private Label hexValueLabel;

    private int redValue;
    private int greenValue;
    private int blueValue;

    public void initialize()
    {
        redSlider.valueProperty().addListener((observableValue, oldValue, newValue) ->
        {
            setRedValue(newValue.intValue());
            changeColorOfPreviewBox();
        });

        greenSlider.valueProperty().addListener((observableValue, oldValue, newValue) ->
        {
            setGreenValue(newValue.intValue());
            changeColorOfPreviewBox();
        });

        blueSlider.valueProperty().addListener((observableValue, oldValue, newValue) ->
        {
            setBlueValue(newValue.intValue());
            changeColorOfPreviewBox();
        });
    }

    private void changeColorOfPreviewBox()
    {
        this.colorPreviewBox.setFill(getColor());
        setHexValueLabel();
    }

    private void setHexValueLabel()
    {
        this.hexValueLabel.setText(getHexCode());
    }

    private Color getColor()
    {
        return Color.rgb(getRedValue(), getGreenValue(), getBlueValue());
    }

    private String getHexCode()
    {
        String hexCode = "#";

        hexCode += String.format("%1$02X", getRedValue());
        hexCode += String.format("%1$02X", getGreenValue());
        hexCode += String.format("%1$02X", getBlueValue());

        return hexCode;
    }

    public int getRedValue()
    {
        return redValue;
    }

    public int getGreenValue()
    {
        return greenValue;
    }

    public int getBlueValue()
    {
        return blueValue;
    }

    private void setRedValue(int redValue)
    {
        this.redValue = redValue;
    }

    private void setGreenValue(int greenValue)
    {
        this.greenValue = greenValue;
    }

    private void setBlueValue(int blueValue)
    {
        this.blueValue = blueValue;
    }
}