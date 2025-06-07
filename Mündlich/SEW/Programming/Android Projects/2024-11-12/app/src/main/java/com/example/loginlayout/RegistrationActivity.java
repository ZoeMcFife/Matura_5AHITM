package com.example.loginlayout;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.example.loginlayout.data.SavedUsers;
import com.example.loginlayout.data.User;
import com.example.loginlayout.database.CatDatabase;
import com.example.loginlayout.database.UserColumnConstants;

public class RegistrationActivity extends AppCompatActivity
{
    TextView registerUsername;
    TextView registerEmail;
    TextView registerPassword;
    Button registerButton;

    private CatDatabase catDatabase;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_registration);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.registration), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        registerUsername = findViewById(R.id.registerUsername);
        registerEmail = findViewById(R.id.registerEmail);
        registerPassword = findViewById(R.id.registerPassword);
        registerButton = findViewById(R.id.buttonRegister);

        registerButton.setOnClickListener(v -> Register());

        catDatabase = new CatDatabase(this);
    }

    private void Register()
    {
        String username = registerUsername.getText().toString();
        String email = registerEmail.getText().toString();
        String password = registerPassword.getText().toString();

        if (username.isEmpty() || email.isEmpty() || password.isEmpty())
        {
            return;
        }

        User user = new User(username, email, password);




        Intent intent = new Intent(this, LoginActivity.class);

        addUserToDb(user);

        SavedUsers.users.add(user);

        startActivity(intent);
    }

    private void addUserToDb(User user)
    {
        SQLiteDatabase db = catDatabase.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(UserColumnConstants.USERNAME_COLUMN, user.getUsername());
        values.put(UserColumnConstants.EMAIL_COLUMN, user.getEmail());
        values.put(UserColumnConstants.PASSWORD_COLUMN, user.getPassword());
        db.insert(UserColumnConstants.USER_TABLE, null, values);
    }
}