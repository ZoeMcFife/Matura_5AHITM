package snake.snake.snake;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application
{
    @Override
    public void start(Stage stage) throws IOException
    {
        Group root = new Group();
        Canvas canvas = new Canvas(800, 800);
        canvas.setFocusTraversable(true);

        Food food = new Food(new Point((int) Math.random() * 800 + 1, (int) Math.random() * 800 + 1));
        Snake snake = new Snake(new Point(48, 49));

        Grid grid = new Grid(800, 800, snake, food);
        GraphicsContext graphics = canvas.getGraphicsContext2D();

        GameLoop loop = new GameLoop(grid, graphics);

        canvas.setOnKeyPressed( e -> {
            switch (e.getCode())
            {
                case UP:
                    snake.moveUp();
                    break;
                case DOWN:
                    snake.moveDown();
                    break;
                case LEFT:
                    snake.moveLeft();
                    break;
                case RIGHT:
                    snake.moveRight();
                    break;
                case ENTER:
                    if (loop.isPaused())
                        loop.resume();
                    else
                    {
                        Painter.pause(grid, graphics);
                        loop.pause();
                    }
                    break;
            }
        });

        Painter.paint(grid, graphics);
        root.getChildren().add(canvas);

        Scene scene = new Scene(root);

        stage.setTitle("Snake but better");
        stage.setScene(scene);
        stage.show();

        (new Thread(loop)).start();
    }

    public static void main(String[] args)
    {
        launch();
    }
}