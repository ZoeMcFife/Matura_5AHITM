module meow.nya.socialmedia {
    requires javafx.controls;
    requires javafx.fxml;


    opens meow.nya.socialmedia to javafx.fxml;
    exports meow.nya.socialmedia;
}