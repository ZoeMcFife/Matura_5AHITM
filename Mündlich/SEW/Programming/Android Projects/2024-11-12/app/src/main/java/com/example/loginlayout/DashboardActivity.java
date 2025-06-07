package com.example.loginlayout;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.example.loginlayout.data.User;
import com.example.loginlayout.fragments.DashboardDataFragment;

public class DashboardActivity extends AppCompatActivity {

    DashboardDataFragment dashboardDataFragment;

    Button logoutButton;

    Button settingsButton;

    Button viewDataButton;
    Button addDataButton;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_dashboard);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.dashboard), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        User user;
        Bundle bundle = getIntent().getExtras();

        if (bundle != null)
        {
            user = bundle.getParcelable("user", User.class);
        }
        else
        {
            user = new User("empty", "empty", "empty");
        }

        dashboardDataFragment = (DashboardDataFragment) getSupportFragmentManager().findFragmentById(R.id.fragmentContainerView);
        dashboardDataFragment.setUser(user);

        logoutButton = findViewById(R.id.logoutButton);
        logoutButton.setOnClickListener(v -> {
            Intent intent = new Intent(DashboardActivity.this, MainActivity.class);

            startActivity(intent);
        });

        settingsButton = findViewById(R.id.buttonSettings);
        settingsButton.setOnClickListener(v -> {
            Intent intent = new Intent(DashboardActivity.this, SettingsActivity.class);
            startActivity(intent);
        });

        viewDataButton = findViewById(R.id.ViewDataButton);
        viewDataButton.setOnClickListener(v -> {
            Intent intent = new Intent(DashboardActivity.this, ViewDataActivity.class);
            startActivity(intent);
        });

        addDataButton = findViewById(R.id.AddDataButton);
        addDataButton.setOnClickListener(v -> {
            Intent intent = new Intent(DashboardActivity.this, AddDataActivity.class);
            startActivity(intent);
        });
    }
}