package aufgabe.sew.aufabe11;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class ResistanceCalculator extends Application
{
    @Override
    public void start(Stage stage)
    {
        Label ring1_Label = new Label("Ring 1");
        Label ring2_Label = new Label("Ring 2");
        Label ring3_Label = new Label("Ring 3");
        Label ring4_Label = new Label("Ring 4");

        Label resistanceValue_Label = new Label("Resistance");
        Label toleranceValue_Label = new Label("Tolerance");
        TextField resistanceValue_Text = new TextField();
        TextField toleranceValue_Text = new TextField();

        Label graphic_Label = new Label("Graphic");


        Rectangle resistor_Graphic = new Rectangle(10,0,100,26);
        resistor_Graphic.setFill(javafx.scene.paint.Color.DARKGREY);

        Rectangle ring1_Graphic = new Rectangle(20,2, 12, 22);
        Rectangle ring2_Graphic = new Rectangle(40, 2, 12, 22);
        Rectangle ring3_Graphic = new Rectangle(60, 2, 12, 22);
        Rectangle ring4_Graphic = new Rectangle(85, 2, 12, 22);

        Rectangle resistorLine_Graphic = new Rectangle(0, 13, 10, 2);
        Rectangle resistorLine2_Graphic = new Rectangle(110, 13, 10, 2);

        Group resistor_Group = new Group(resistor_Graphic, ring1_Graphic, ring2_Graphic, ring3_Graphic, ring4_Graphic, resistorLine_Graphic, resistorLine2_Graphic);

        Color[] ring1_Colors = {Color.BLACK, Color.BROWN, Color.RED, Color.ORANGE, Color.YELLOW, Color.GREEN, Color.BLUE, Color.PURPLE, Color.GREY, Color.WHITE};
        ComboBox ring1_Selection = new ComboBox(FXCollections.observableArrayList(ring1_Colors));

        ComboBox ring2_Selection = new ComboBox(FXCollections.observableArrayList(ring1_Colors));

        Color[] ring3_Colors = {Color.BLACK, Color.BROWN, Color.RED, Color.ORANGE, Color.YELLOW, Color.GREEN, Color.BLUE, Color.PURPLE, Color.GREY, Color.WHITE, Color.GOLD, Color.SILVER};
        ComboBox ring3_Selection = new ComboBox(FXCollections.observableArrayList(ring3_Colors));

        Color[] ring4_Colors = {Color.BROWN, Color.RED, Color.GREEN, Color.BLUE, Color.PURPLE, Color.GREY, Color.GOLD, Color.SILVER, Color.NONE};
        ComboBox ring4_Selection = new ComboBox(FXCollections.observableArrayList(ring4_Colors));

        Button calculate_Button = new Button("Calculate");
        calculate_Button.setOnAction(actionEvent ->
        {
            try
            {
                Resistor resistor = new Resistor((Color)ring1_Selection.getValue(), (Color)ring2_Selection.getValue(), (Color)ring3_Selection.getValue(), (Color)ring4_Selection.getValue());
                toleranceValue_Text.setText(String.valueOf(resistor.getTolerance()));
                resistanceValue_Text.setText(String.valueOf(resistor.getResistance()));

                ring1_Graphic.setFill(convertToJavaFXColor((Color) ring1_Selection.getValue()));
                ring2_Graphic.setFill(convertToJavaFXColor((Color) ring2_Selection.getValue()));
                ring3_Graphic.setFill(convertToJavaFXColor((Color) ring3_Selection.getValue()));
                ring4_Graphic.setFill(convertToJavaFXColor((Color) ring4_Selection.getValue()));

            }
            catch (Exception e)
            {
                toleranceValue_Text.setText("Error");
                resistanceValue_Text.setText("Error");
            }
        });


        GridPane root = new GridPane();

        root.setHgap(10);
        root.setVgap(10);
        root.setPadding(new Insets(10,10,10,10));

        root.add(ring1_Label, 0, 0);
        root.add(ring1_Selection, 1, 0);
        root.add(ring2_Label, 0, 1);
        root.add(ring2_Selection, 1, 1);
        root.add(ring3_Label, 0, 2);
        root.add(ring3_Selection, 1, 2);
        root.add(ring4_Label, 0, 3);
        root.add(ring4_Selection, 1, 3);
        root.add(calculate_Button, 1, 5);
        root.add(resistanceValue_Label, 0, 7);
        root.add(resistanceValue_Text, 1, 7);
        root.add(toleranceValue_Label, 0, 8);
        root.add(toleranceValue_Text, 1, 8);
        root.add(graphic_Label, 0, 9);
        root.add(resistor_Group, 1, 9);

        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    private javafx.scene.paint.Color convertToJavaFXColor(Color color)
    {
        javafx.scene.paint.Color newColor = new javafx.scene.paint.Color(0,0,0,0);

        switch (color)
        {
            case BLACK -> newColor = javafx.scene.paint.Color.BLACK;
            case BROWN -> newColor = javafx.scene.paint.Color.BROWN;
            case RED -> newColor = javafx.scene.paint.Color.RED;
            case ORANGE -> newColor = javafx.scene.paint.Color.ORANGE;
            case YELLOW -> newColor = javafx.scene.paint.Color.YELLOW;
            case GREEN -> newColor = javafx.scene.paint.Color.GREEN;
            case BLUE -> newColor = javafx.scene.paint.Color.BLUE;
            case PURPLE -> newColor = javafx.scene.paint.Color.PURPLE;
            case GREY -> newColor = javafx.scene.paint.Color.GREY;
            case WHITE -> newColor = javafx.scene.paint.Color.WHITE;
            case GOLD -> newColor = javafx.scene.paint.Color.GOLD;
            case SILVER -> newColor = javafx.scene.paint.Color.SILVER;
            case NONE -> newColor = javafx.scene.paint.Color.TRANSPARENT;
        }

        return newColor;
    }

    public static void main(String[] args)
    {
        launch();
    }
}