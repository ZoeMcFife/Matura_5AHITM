package com.example.aufgabe11_1;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Aufgabe11_1 extends Application
{
    @Override
    public void start(Stage primaryStage) {
        Label label1 = new Label("Eingabe 1:");
        Label label2 = new Label("Eingabe 2:");
        Label label3 = new Label("Ergebnis:");
        TextField txtIn1 = new TextField();
        TextField txtIn2 = new TextField();
        TextField txtOut = new TextField();
        Button btn = new Button("Suche größte Übereinstimmung");
        btn.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {

                txtOut.setText(findLongestMatch(txtIn1.getText(), txtIn2.getText()));
            }
        });

        VBox root = new VBox(4.0); //vertikales Layout mit 4 Pixel Abstand für folgende Elemente:
        root.getChildren().addAll(label1,txtIn1,label2,txtIn2,btn,label3,txtOut);

        Scene scene = new Scene(root);

        primaryStage.setTitle("Rechner");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private String findLongestMatch(String string1, String string2)
    {
        String match = "No match found";
        int largestMatchLengthFound = 1;

        if (string1.equals(string2)) return string1;
        if (string1.isEmpty() || string2.isEmpty()) return "Invalid Input";

        //Swaps to the shortest string to improve performance
        if (string1.length() > string2.length())
        {
            String temp = string1;
            string1 = string2;
            string2 = temp;
        }

        // Loops through every substring
        for (int j = string1.length(); j > 0; j--)
        {
            for (int i = 0; i < string1.length(); i++)
            {
                if (i >= j)
                    continue;

                String contained = string1.substring(i, j);

                if (string2.contains(contained) && contained.length() > largestMatchLengthFound)
                {
                    largestMatchLengthFound = contained.length();
                    match = contained;
                }
            }
        }

        return match;
    }

    public static void main(String[] args)
    {
        launch();
    }
}