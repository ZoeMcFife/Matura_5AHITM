module rgb.color.rgbeditor {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens rgb.color.rgbeditor to javafx.fxml;
    exports rgb.color.rgbeditor;
}