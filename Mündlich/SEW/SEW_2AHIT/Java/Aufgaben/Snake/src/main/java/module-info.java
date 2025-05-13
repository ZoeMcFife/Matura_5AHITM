module snake.snake.snake {
    requires javafx.controls;
    requires javafx.fxml;


    opens snake.snake.snake to javafx.fxml;
    exports snake.snake.snake;
}