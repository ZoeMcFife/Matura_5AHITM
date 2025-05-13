package clock.app.aufgabe12;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.io.IOException;
import java.time.LocalDateTime;

public class Clock extends Application
{
    @Override
    public void start(Stage stage)
    {
        Group root = new Group();
        Canvas canvas = new Canvas(300, 300);
        GraphicsContext graphics = canvas.getGraphicsContext2D();
        drawClock(graphics);
        root.getChildren().add(canvas);

        stage.setScene(new Scene(root));
        stage.setTitle("Clock");
        stage.show();

        Timeline timeline = new Timeline() ;
        timeline.setCycleCount( Animation.INDEFINITE ) ;

        EventHandler<ActionEvent> refreshClock = (ActionEvent event ) ->
        {
            int hour = LocalDateTime.now().getHour();
            int minute = LocalDateTime.now().getMinute();
            int second = LocalDateTime.now().getSecond();

            stage.setTitle("Time: " + hour + ":" + minute + ":" + second);

            graphics.clearRect(0,0,300,300);
            drawClock(graphics);
        } ;

        KeyFrame keyframe = new KeyFrame( Duration.millis( 1000 ), refreshClock ) ;

        timeline.getKeyFrames().add( keyframe ) ;
        timeline.play() ;
    }

    private void drawClock(GraphicsContext gc)
    {
        int hour = LocalDateTime.now().getHour();
        int minute = LocalDateTime.now().getMinute();
        int second = LocalDateTime.now().getSecond();

        for (int i = 0; i < 60; i++)
        {
            drawTimeMark(gc, 0.8, Color.GRAY, i * 6, 4);
        }

        for (int i = 0; i < 12; i++)
        {
            drawTimeMark(gc, 1.5, Color.DARKGRAY, i * 30, 8);
        }

        for (int i = 0; i < 4; i++)
        {
            drawTimeMark(gc, 2.2, Color.BLACK, i * 90, 10);
        }

        drawClockHands(gc, 2.5, Color.LAVENDER, 90 - minute * 6, 100);
        drawClockHands(gc, 1, Color.GRAY, 90 - second * 6, 110);
        drawClockHands(gc, 4.5, Color.BLUEVIOLET, 90 - hour * 30, 65);
    }

    private void drawClockHands(GraphicsContext gc, double width, Color color, double angle, double length)
    {
        double faceRadius = 120;
        double faceCenter = 150;

        length = 120 - length;

        angle = Math.toRadians(angle);

        System.out.println(angle);

        gc.setLineWidth(width);
        gc.setStroke(color);

        double yStart = faceCenter - Math.sin(angle) * faceRadius;
        double xStart = faceCenter + Math.cos(angle) * faceRadius;

        double yEnd = yStart + Math.sin(angle) * length;
        double xEnd = xStart - Math.cos(angle) * length;

        gc.strokeLine(faceCenter, faceCenter, xEnd, yEnd);
    }

    private void drawTimeMark(GraphicsContext gc, double width, Color color, double angle, double length)
    {
        double faceRadius = 120;
        double faceCenter = 150;

        angle = Math.toRadians(angle);

        System.out.println(angle);

        gc.setLineWidth(width);
        gc.setStroke(color);

        double yStart = faceCenter - Math.sin(angle) * faceRadius;
        double xStart = faceCenter + Math.cos(angle) * faceRadius;

        double yEnd = yStart + Math.sin(angle) * length;
        double xEnd = xStart - Math.cos(angle) * length;

        gc.strokeLine(xStart, yStart, xEnd, yEnd);
    }

    public static void main(String[] args)
    {
        launch();
    }
}