package com.example.javafxbinding;

import javafx.beans.property.SimpleStringProperty;

public class Contact
{
    private SimpleStringProperty firstName = new SimpleStringProperty();
    private SimpleStringProperty lastName = new SimpleStringProperty();

    public Contact(String firstName, String lastName)
    {
        setFirstName(firstName);
        setLastName(lastName);
    }

    public String getFirstName()
    {
        return firstName.get();
    }

    public SimpleStringProperty firstNameProperty()
    {
        return firstName;
    }

    public void setFirstName(String firstName)
    {
        this.firstName.set(firstName);
    }

    public String getLastName()
    {
        return lastName.get();
    }

    public SimpleStringProperty lastNameProperty()
    {
        return lastName;
    }

    public void setLastName(String lastName)
    {
        this.lastName.set(lastName);
    }
}
