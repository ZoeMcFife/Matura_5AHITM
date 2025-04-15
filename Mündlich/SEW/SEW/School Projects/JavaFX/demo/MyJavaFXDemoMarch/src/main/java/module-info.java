module com.example.myjavafxdemomarch {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.myjavafxdemomarch to javafx.fxml;
    exports com.example.myjavafxdemomarch;
}