package snake.snake.snake;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class Painter
{
    public static void paint(Grid grid, GraphicsContext gc)
    {
        paintGrid(grid, gc, Grid.GRIDCOLOR);
        paintFood(grid, gc, grid.getFood().getCOLOR());
        paintSnake(grid, gc, grid.getSnake().getColor());
        paintObstacles(grid, gc, Color.RED);

        paintText(new Point(2, grid.getCols() - 2), "Score: " + grid.getSnake().length, grid, gc, Color.BLACK);
    }

    private static void paintText(Point point, String text, Grid grid, GraphicsContext gc, Color color)
    {
        gc.setStroke(color);
        gc.strokeText(text, point.getX() * Grid.PIXELSIZE, point.getY() * Grid.PIXELSIZE);
    }

    public static void pause(Grid grid, GraphicsContext gc)
    {
        paintGrid(grid, gc, Color.BEIGE);
        paintSnake(grid, gc, Color.BLACK);
        paintObstacles(grid, gc, Color.DARKRED);
        paintText(new Point(grid.getRows() / 2 - 1, grid.getCols() / 2 - 2), "PAUSED", grid, gc, Color.BLACK);
    }

    public static void end(Grid grid, GraphicsContext gc)
    {
        paintGrid(grid, gc, Color.BLACK);
        paintSnake(grid, gc, Color.WHITE);
        paintText(new Point(grid.getRows() / 2 - 1, grid.getCols() / 2 - 2), "DEAD", grid, gc, Color.RED);
        paintText(new Point(grid.getRows() / 2 - 1, grid.getCols() / 2), "Score: " + grid.getSnake().length, grid, gc, Color.RED);
    }

    private static void paintPixel(Point point, Grid grid, GraphicsContext gc)
    {
        gc.fillRect(point.getX() * Grid.PIXELSIZE, point.getY() * Grid.PIXELSIZE, Grid.PIXELSIZE, Grid.PIXELSIZE);
    }

    private static void paintGrid(Grid grid, GraphicsContext gc, Color color)
    {
        gc.setFill(color);
        gc.fillRect(0, 0, grid.getWidth(), grid.getHeight());
    }

    private static void paintObstacles(Grid grid, GraphicsContext gc, Color color)
    {
        gc.setFill(color);

        for (Point p : grid.getObstacles())
        {
            paintPixel(p, grid, gc);
        }
    }

    private static void paintFood(Grid grid, GraphicsContext gc, Color color)
    {
        gc.setFill(color);
        paintPixel(grid.getFood().getPosition(), grid, gc);
    }

    private static void paintSnake(Grid grid, GraphicsContext gc, Color color)
    {
        gc.setFill(color);

        for (Point p : grid.getSnake().snakeBody)
        {
            paintPixel(p, grid, gc);
        }
    }
}
