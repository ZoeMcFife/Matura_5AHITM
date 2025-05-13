package gay.fox.plftest;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class FoxController
{
    public TextField foxNameInput;
    public TextField foxKarmaInput;
    public TextField foxFurColorHexPreviewText;
    public Rectangle foxFurColorPreviewRectangle;
    public Slider redSlider;
    public Slider greenSlider;
    public Slider blueSlider;
    public Button addFoxButton;
    public Label errorLabel;

    public FoxModel foxModel;
    public TextField selectFoxTextInput;

    private SimpleIntegerProperty redValue = new SimpleIntegerProperty(this, "redValue");
    private SimpleIntegerProperty greenValue = new SimpleIntegerProperty(this, "greenValue");
    private SimpleIntegerProperty blueValue = new SimpleIntegerProperty(this, "blueValue");

    private SimpleStringProperty foxName = new SimpleStringProperty(this, "foxName");
    private SimpleStringProperty foxKarma = new SimpleStringProperty(this, "foxKarma");
    private SimpleStringProperty foxColor = new SimpleStringProperty(this, "foxColor");

    /**
     * This code is crap
     *
     * @see FoxApp
     * @author Zozo
     */

    public void initialize()
    {
        this.foxModel = new FoxModel();

        this.redSlider.valueProperty().addListener((observableValue, oldValue, newValue) ->
        {
            setRedValue(newValue.intValue());
            setFoxColor(getHexCode());
            updateColorPreviewRectangle();
        });

        this.greenSlider.valueProperty().addListener((observableValue, oldValue, newValue) ->
        {
            setGreenValue(newValue.intValue());
            setFoxColor(getHexCode());
            updateColorPreviewRectangle();
        });

        this.blueSlider.valueProperty().addListener((observableValue, oldValue, newValue) ->
        {
            setBlueValue(newValue.intValue());
            setFoxColor(getHexCode());
            updateColorPreviewRectangle();
        });

        this.redValue.bindBidirectional(this.redSlider.valueProperty());
        this.greenValue.bindBidirectional(this.greenSlider.valueProperty());
        this.blueValue.bindBidirectional(this.blueSlider.valueProperty());

        this.foxName.bindBidirectional(this.foxNameInput.textProperty());
        this.foxKarma.bindBidirectional(this.foxKarmaInput.textProperty());
        this.foxColor.bindBidirectional(this.foxFurColorHexPreviewText.textProperty());

        this.selectFoxTextInput.setOnKeyTyped(e ->
        {
            Fox fox = new Fox();

            try
            {
                fox = this.foxModel.getFox(selectFoxTextInput.getText());

                if (!this.foxModel.doesFoxExist(selectFoxTextInput.getText()))
                    throw new Exception();
            }
            catch (Exception exception)
            {
                setErrorLabel("Fox doesn't exist");
                return;
            }

            setFoxName(fox.getName());
            setFoxColor(fox.getFurColor());
            setFoxKarma(String.valueOf(fox.getRedditKarma()));

            setRedValue(Integer.valueOf(fox.getFurColor().substring(1, 3), 16));
            setGreenValue(Integer.valueOf(fox.getFurColor().substring(3, 5), 16));
            setBlueValue(Integer.valueOf(fox.getFurColor().substring(5, 7), 16));
            setErrorLabel("");
        });

    }

    public void addFox()
    {
        int foxRedditKarma;
        try
        {
            foxRedditKarma = Integer.parseInt(getFoxKarma());
        }
        catch (Exception e)
        {
            setErrorLabel("Karma must be a number");
            return;
        }

        Fox newFox = new Fox(getFoxName(), foxRedditKarma, getFoxColor());

        if (!this.foxModel.doesFoxExist(getFoxName()))
            this.foxModel.addFox(newFox);
        else
            setErrorLabel("Fox already exists!");
    }

    private void setErrorLabel(String errorText)
    {
        this.errorLabel.setText(errorText);
    }

    private void updateColorPreviewRectangle()
    {
        this.foxFurColorPreviewRectangle.setFill(getColor());
    }

    private void setFoxFurColorHexPreviewText(String hexCode)
    {
        this.foxFurColorHexPreviewText.setText(getHexCode());
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

    public void setRedValue(int redValue)
    {
        this.redValue.set(redValue);
    }

    public void setGreenValue(int greenValue)
    {
        this.greenValue.set(greenValue);
    }

    public void setBlueValue(int blueValue)
    {
        this.blueValue.set(blueValue);
    }

    public int getRedValue()
    {
        return redValue.get();
    }

    public int getGreenValue()
    {
        return greenValue.get();
    }

    public int getBlueValue()
    {
        return blueValue.get();
    }

    public void setFoxName(String foxName)
    {
        this.foxName.set(foxName);
    }

    public String getFoxName()
    {
        return foxName.get();
    }

    public void setFoxKarma(String foxKarma)
    {
        this.foxKarma.set(foxKarma);
    }

    public String getFoxKarma()
    {
        return foxKarma.get();
    }

    public void setFoxColor(String foxColor)
    {
        this.foxColor.set(foxColor);
    }

    public String getFoxColor()
    {
        return foxColor.get();
    }
}