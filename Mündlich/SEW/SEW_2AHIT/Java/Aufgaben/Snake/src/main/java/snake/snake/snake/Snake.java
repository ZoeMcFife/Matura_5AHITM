package snake.snake.snake;

import javafx.scene.paint.Color;

import java.util.LinkedList;

public class Snake
{
    LinkedList<Point> snakeBody = new LinkedList<>();
    LinkedList<Point> oldSnakeBody = new LinkedList<>();


    private final Point head;
    private Color color = Color.DARKGREEN;

    public int xVelocity = 0;
    public int yVelocity = 0;

    public int length = 1;

    Snake(Point startingPosition)
    {
        this.head = startingPosition;
        snakeBody.push(head);
    }

    public Point getHeadPosition()
    {
        return head;
    }

    public void extendSnake()
    {
        snakeBody.add(new Point(snakeBody.getLast().translate(-this.xVelocity, this.yVelocity)));
        length = snakeBody.size();
    }

    public void move()
    {
        this.oldSnakeBody = new LinkedList<>(snakeBody);

        Point oldPos = new Point(head);
        head.translateThis(xVelocity, -yVelocity);

        for (int i = 1; i < snakeBody.size(); i++)
        {
            Point oldPos2 = new Point(snakeBody.get(i));
            snakeBody.get(i).setPoint(oldPos);
            oldPos.setPoint(oldPos2);
        }

    }

    public void moveUp()
    {
        if (this.yVelocity != -1)
        {
            this.xVelocity = 0;
            this.yVelocity = 1;
        }
    }

    public void moveDown()
    {
        if (this.yVelocity != 1)
        {
            this.xVelocity = 0;
            this.yVelocity = -1;
        }
    }

    public void moveLeft()
    {
        if (this.xVelocity != 1)
        {
            this.xVelocity = -1;
            this.yVelocity = 0;
        }
    }

    public void moveRight()
    {
        if (this.xVelocity != -1)
        {
            this.xVelocity = 1;
            this.yVelocity = 0;
        }
    }

    public Color getColor()
    {
        return color;
    }

    public void die()
    {
        this.color = Color.DARKRED;
    }

    public void setSnakeBody(LinkedList<Point> newBody)
    {
        this.snakeBody = new LinkedList<>(newBody);
        length = snakeBody.size();
    }

    public LinkedList<Point> getSnakeBody()
    {
        return this.snakeBody;
    }

    public LinkedList<Point> splitBody(int index)
    {
        LinkedList<Point> snakeBody = new LinkedList<>(getSnakeBody());
        LinkedList<Point> removedBody = new LinkedList<>();

        for (int i = index; i < getSnakeBody().size(); i++)
        {
            removedBody.add(snakeBody.remove(index));
        }

        setSnakeBody(snakeBody);
        removedBody.removeFirst();

        return removedBody;
    }

    @Override
    public String toString()
    {
        StringBuilder str = new StringBuilder();

        for (Point p : snakeBody)
        {
            str.append(p).append(" | ");
        }

        return str.toString();
    }
}