package snake.snake.snake;

import javafx.scene.canvas.GraphicsContext;

public class GameLoop implements Runnable
{
    private final Grid grid;
    private final GraphicsContext gc;

    private int frameRate;
    private float interval;
    public boolean isPaused;

    public GameLoop(Grid grid, GraphicsContext gc)
    {
        this.grid = grid;
        this.gc = gc;

        this.frameRate = 16;
        this.interval = 1000.0f / frameRate;
        this.isPaused = false;
    }

    public void pause()
    {
        this.isPaused = true;
    }

    public void resume()
    {
        this.isPaused = false;
        (new Thread(this)).start();
    }

    public boolean isPaused()
    {
        return this.isPaused;
    }

    @Override
    public void run()
    {
        while (!isPaused && !grid.isSnakeDead)
        {
            float time = System.currentTimeMillis();

            grid.update();
            Painter.paint(grid, gc);

            if (grid.isSnakeDead)
                Painter.end(grid, gc);

            time = System.currentTimeMillis() - time;

            if (time < interval)
            {
                try
                {
                    Thread.sleep((long) (interval - time));
                }
                catch (InterruptedException ignore)
                {
                }
            }
        }
    }
}
