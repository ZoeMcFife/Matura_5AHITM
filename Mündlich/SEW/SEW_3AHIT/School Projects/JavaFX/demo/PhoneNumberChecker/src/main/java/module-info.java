module com.example.phonenumberchecker {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.phonenumberchecker to javafx.fxml;
    exports com.example.phonenumberchecker;
}