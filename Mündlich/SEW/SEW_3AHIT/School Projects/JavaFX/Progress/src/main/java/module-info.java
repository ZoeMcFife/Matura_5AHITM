module com.example.progress {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.progress to javafx.fxml;
    exports com.example.progress;
}