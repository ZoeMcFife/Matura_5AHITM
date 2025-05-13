package com.example.progress;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.ProgressIndicator;
import javafx.scene.control.skin.ProgressIndicatorSkin;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application
{

    @Override
    public void start(Stage stage) throws IOException
    {
        HBox root = new HBox(10, createProgressIndicator(), createProgressIndicator(), createProgressIndicator(), createProgressIndicator(), createProgressIndicator());

        Scene scene = new Scene(root, 400, 400);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    private ProgressIndicator createProgressIndicator()
    {
        ProgressIndicator p = new ProgressIndicator(10);

        Thread loading = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                for (double i = 0; Math.round(i * 100) <= 100; i += 0.01)
                {
                    p.setProgress(i);

                    try
                    {
                        double random = Math.random() * (10 - 1 + 1) + 1;

                        Thread.sleep((long) random * 50);
                    }
                    catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }

                }
            }
        });

        loading.start();

        return p;
    }



    public static void main(String[] args)
    {
        launch();
    }
}