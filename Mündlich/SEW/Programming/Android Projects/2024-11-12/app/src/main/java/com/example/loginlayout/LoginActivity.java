package com.example.loginlayout;

import android.content.Intent;
import android.database.Cursor;
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

public class LoginActivity extends AppCompatActivity {

    Button loginButton;
    Button registerButton;

    TextView passwordLogin;
    TextView emailLogin;

    private CatDatabase catDatabase;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_login);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.login), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        SavedUsers.users.add(new User("test", "test", "test"));


        loginButton = findViewById(R.id.loginButton);
        registerButton = findViewById(R.id.registerButton);

        passwordLogin = findViewById(R.id.passwordLogin);
        emailLogin = findViewById(R.id.emailLogin);


        registerButton.setOnClickListener(v -> {
            Intent intent = new Intent(this, RegistrationActivity.class);
            startActivity(intent);
        });

        loginButton.setOnClickListener(v -> {
                    Login();
                }
        );

        catDatabase = new CatDatabase(this);
    }

    public User ValidateUser(String email, String password) {
        SQLiteDatabase db = catDatabase.getReadableDatabase();
        User user = null;

        String query = "SELECT * FROM " + UserColumnConstants.USER_TABLE +
                " WHERE " + UserColumnConstants.EMAIL_COLUMN + " = ? AND " +
                UserColumnConstants.PASSWORD_COLUMN + " = ?";

        Cursor cursor = db.rawQuery(query, new String[]{email, password});

        if (cursor.moveToFirst()) {
            // Extract user details from the cursor
            String username = cursor.getString(cursor.getColumnIndexOrThrow(UserColumnConstants.USERNAME_COLUMN));
            String retrievedEmail = cursor.getString(cursor.getColumnIndexOrThrow(UserColumnConstants.EMAIL_COLUMN));
            String retrievedPassword = cursor.getString(cursor.getColumnIndexOrThrow(UserColumnConstants.PASSWORD_COLUMN));

            user = new User(username, retrievedEmail, retrievedPassword); // Create User object
        }

        cursor.close();
        db.close();
        return user; // Returns User object if found, else null
    }


    public void Login()
    {
        String email = emailLogin.getText().toString();
        String password = passwordLogin.getText().toString();

        if (email.isEmpty() || password.isEmpty())
        {
            return;
        }

        User user = ValidateUser(email, password);

        if (user != null)
        {
            Intent intent = new Intent(this, DashboardActivity.class);
            intent.putExtra("user", user);
            startActivity(intent);
        }
    }
}