module gay.fox.plftest {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens gay.fox.plftest to javafx.fxml;
    exports gay.fox.plftest;
}