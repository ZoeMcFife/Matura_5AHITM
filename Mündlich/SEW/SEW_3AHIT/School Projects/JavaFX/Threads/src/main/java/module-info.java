module com.example.threadsjavafx {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.threadsjavafx to javafx.fxml;
    exports com.example.threadsjavafx;
}