package com.example.threadsjavafx;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.EventListener;

public class HelloApplication extends Application
{
    Button btnStart = new Button("Start");
    Button btnExit = new Button("Exit");
    Label lblProcessing = new Label();
    TextArea txtOutput = new TextArea();

    @Override
    public void start(Stage stage) throws IOException
    {
        btnStart.setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent actionEvent)
            {
                loop();
            }
        });

        btnExit.setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent actionEvent)
            {
                stopLoop();
            }
        });
        HBox hBox = new HBox(10, btnStart, btnExit);
        VBox root = new VBox(10, lblProcessing, hBox, txtOutput);
        Scene scene = new Scene(root, 400, 400);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    private void stopLoop()
    {
        System.out.println(Thread.activeCount());
    }

    private void loop()
    {

        Thread thread = new Thread(() ->
        {
            for (int i = 1; i <= 10; i++)
            {
                txtOutput.appendText("Processing " + i + " out of 10.\n");

                int finalI = i;
                Platform.runLater(() -> lblProcessing.setText("Processing " + finalI + " out of 10."));

                try
                {
                    Thread.sleep(1000);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        });

        thread.setDaemon(true);
        thread.start();
    }

    public static void main(String[] args)
    {
        launch();
    }
}