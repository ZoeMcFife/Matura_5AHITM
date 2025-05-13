module com.example.aufgabe11_1 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.aufgabe11_1 to javafx.fxml;
    exports com.example.aufgabe11_1;
}