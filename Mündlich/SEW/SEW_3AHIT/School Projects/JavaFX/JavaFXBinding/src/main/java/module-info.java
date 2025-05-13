module com.example.javafxbinding {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.javafxbinding to javafx.fxml;
    exports com.example.javafxbinding;
}