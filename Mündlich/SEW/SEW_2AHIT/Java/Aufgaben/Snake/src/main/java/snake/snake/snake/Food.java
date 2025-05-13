package snake.snake.snake;

import javafx.scene.paint.Color;

public class Food
{
    private Point position;
    private final Color COLOR = Color.BURLYWOOD;

    Food(Point position)
    {
        this.position = position;
    }

    public Point getPosition()
    {
        return position;
    }

    public Color getCOLOR()
    {
        return COLOR;
    }

    public void setPosition(Point position)
    {
        this.position = position;
    }
}
