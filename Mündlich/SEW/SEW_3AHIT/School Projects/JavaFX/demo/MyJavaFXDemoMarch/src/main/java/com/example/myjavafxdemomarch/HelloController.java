package com.example.myjavafxdemomarch;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class HelloController
{
    @FXML
    private Button helloButton;
    @FXML
    private Label welcomeText;

    public void initialize()
    {
        System.out.println("Hello");

        helloButton.getStyleClass().add("btn-primary");
        helloButton.setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent actionEvent)
            {
                welcomeText.getStyleClass().add("lbl-danger");
                welcomeText.setText("Welcome to JavaFX Application!!");
            }
        });
    }

    @FXML
    protected void onHelloButtonClick()
    {
        welcomeText.setText("Welcome to JavaFX Application!");
    }
}