module clock.app.aufgabe12 {
    requires javafx.controls;
    requires javafx.fxml;


    opens clock.app.aufgabe12 to javafx.fxml;
    exports clock.app.aufgabe12;
}