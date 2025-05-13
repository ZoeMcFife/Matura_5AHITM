package com.example.javafxbinding;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;

/**
 You create the first name and last name variables of type SimpleStringProperty
 outside the created Contact domain object.
 You bind them bi-directionally to allow changes to update on either end
 (domain object <-> outside variables)
 */

public class BindingExpressions
{
    public static void main(String[] args)
    {
        System.out.println("Binding a Contact bean [Bi-directional binding]");

        Contact contact = new Contact("Kirsi", "Snow");
        StringProperty firstName = new SimpleStringProperty();
        firstName.bindBidirectional(contact.firstNameProperty());
        StringProperty lastName = new SimpleStringProperty();
        lastName.bindBidirectional(contact.lastNameProperty());

        firstName.addListener((observableValue, s, t1) -> System.out.println("First name has been changed."));

        System.out.println("Current - StringProperty values: " + firstName.getValue() + " " + lastName.getValue());
        System.out.println("Current - Contact values: " + contact.getFirstName() + " " + contact.getLastName());
        System.out.println("Modifying StringProperty values:");

        firstName.setValue("Cutie");
        lastName.setValue("Woofer");

        System.out.println("After - StringProperty values: " + firstName.getValue() + " " + lastName.getValue());
        System.out.println("After - Contact values: " + contact.getFirstName() + " " + contact.getLastName());

        System.out.println();
    }
}
