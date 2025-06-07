package com.example.loginlayout.data;

import android.os.Parcel;
import android.os.Parcelable;

import androidx.annotation.NonNull;

public class User implements Parcelable, Parcelable.Creator<User>
{
    public String username;
    public String email;
    public String password;

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }


    public User(String username, String email, String password)
    {
        this.username = username;
        this.email = email;
        this.password = password;
    }

    public boolean Login(String email, String password)
    {
        return this.email.equals(email) && this.password.equals(password);
    }

    protected User(Parcel in) {
        username = in.readString();
        email = in.readString();
        password = in.readString();
    }

    public static final Creator<User> CREATOR = new Creator<User>() {
        @Override
        public User createFromParcel(Parcel in) {
            return new User(in);
        }

        @Override
        public User[] newArray(int size) {
            return new User[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(@NonNull Parcel dest, int flags) {
        dest.writeString(username);
        dest.writeString(email);
        dest.writeString(password);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true; // If they are the same object
        }

        if (obj == null || getClass() != obj.getClass()) {
            return false; // If the object is null or not the same class
        }

        User user = (User) obj;

        // Compare the fields
        return username.equals(user.username) &&
                email.equals(user.email) &&
                password.equals(user.password);
    }

    @Override
    public int hashCode() {
        // Generate a hashCode based on the fields
        return 31 * username.hashCode() + 31 * email.hashCode() + 31 * password.hashCode();
    }

    @Override
    public User createFromParcel(Parcel source) {
        return new User(source);
    }

    @Override
    public User[] newArray(int size) {
        return new User[0];
    }
}
