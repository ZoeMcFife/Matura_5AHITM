package com.example.phonenumberchecker;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class HelloController
{
    @FXML
    private TextField phoneNumberTextField;
    @FXML
    private Label phoneNumberCheckLabel;
    @FXML
    private Button checkButton;

    @FXML
    protected void validatePhoneNumber()
    {
        String phoneRegex = "((\\((\\d{3})\\))|(\\d{3}))(?<combiner>(\\.| |-|\\/))(\\d{3})(\\k<combiner>)(\\d{4})";
        Pattern phonePattern = Pattern.compile(phoneRegex);
        Matcher phoneMatcher = phonePattern.matcher(phoneNumberTextField.getText());

        if (phoneMatcher.find())
        {
            phoneNumberCheckLabel.setText("Valid");
        }
        else
        {
            phoneNumberCheckLabel.setText("Not Valid");
        }
    }
}