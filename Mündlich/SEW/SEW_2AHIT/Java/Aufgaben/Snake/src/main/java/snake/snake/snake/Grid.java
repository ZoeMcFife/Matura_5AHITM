package snake.snake.snake;

import javafx.scene.paint.Color;

import java.util.LinkedList;

public class Grid
{
    public final static int PIXELSIZE = 10;
    public final static Color GRIDCOLOR = Color.IVORY;

    private final int rows;
    private final int cols;

    private final Snake snake;
    private final Food food;

    private final LinkedList<Point> obstacles = new LinkedList<>();

    public boolean isSnakeDead;

    Grid(int width, int height, Snake snake, Food food)
    {
        this.rows = height / PIXELSIZE;
        this.cols = width / PIXELSIZE;

        this.snake = snake;
        this.food = food;

        this.isSnakeDead = false;
    }

    public void update()
    {
        snake.move();

        if (obstacles.contains(snake.getHeadPosition()) || isOutOfBounds(snake.getHeadPosition()))
        {
            snake.die();
            this.isSnakeDead = true;
        }

        if (snake.getHeadPosition().equals(food.getPosition()))
        {
            snake.extendSnake();

            LinkedList<Point> exclude = new LinkedList<>(obstacles);
            exclude.add(this.snake.getHeadPosition());

            food.setPosition(Point.getRandomPoint(rows, cols, exclude));
        }


        if (isSnakeIntersectingItself(snake))
        {
            obstacles.addAll(this.snake.splitBody(getIndexOfSnakeBodyWithoutHead(this.snake.getHeadPosition())));
        }

    }

    private boolean isOutOfBounds(Point position)
    {
        if (position.getX() < 0 || position.getY() < 0)
            return true;

        return position.getX() > cols - 1 || position.getY() > rows - 1;
    }

    private boolean isSnakeIntersectingItself(Snake snake)
    {
        if (snake.length == 1)
            return false;

        LinkedList<Point> snakeWithoutHead = new LinkedList<>(snake.getSnakeBody());
        snakeWithoutHead.remove(0);

        return snakeWithoutHead.contains(snake.getHeadPosition());
    }

    private int getIndexOfSnakeBodyWithoutHead(Point point)
    {
        if (snake.length == 1)
            return 0;

        LinkedList<Point> snakeWithoutHead = new LinkedList<>(snake.getSnakeBody());
        snakeWithoutHead.remove(0);

        return snakeWithoutHead.indexOf(point);
    }

    public LinkedList<Point> getObstacles()
    {
        return obstacles;
    }

    public int getWidth()
    {
        return rows * PIXELSIZE;
    }

    public int getHeight()
    {
        return cols * PIXELSIZE;
    }

    public int getCols()
    {
        return cols;
    }

    public int getRows()
    {
        return rows;
    }

    public Food getFood()
    {
        return food;
    }

    public Snake getSnake()
    {
        return snake;
    }
}