package com.example.demo;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.example.demo.data.Data;
import com.example.demo.database.ColumnConstants;
import com.example.demo.database.EventDatabase;

public class MainActivity extends AppCompatActivity implements View

        .OnClickListener
{
    private Button btnNext;
    private Button buttonSettings;
    private Data value = new Data();

    private EventDatabase eventDatabase;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        btnNext = findViewById(R.id.btnNext);

        btnNext.setOnClickListener(this);

        buttonSettings = findViewById(R.id.buttonSettings);
        buttonSettings.setOnClickListener(
                v -> {
                    Intent intent = new Intent(this, SettingsActivity.class);
                    startActivity(intent);
                }
        );

        eventDatabase = new EventDatabase(this);
    }

    private void writeDatabase()
    {
        SQLiteDatabase db = eventDatabase.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(ColumnConstants.TIME, System.currentTimeMillis());
        values.put(ColumnConstants.EVENT, "MainActivity");
        db.insert(ColumnConstants.TABLE_NAME, null, values);
    }

    private void readDatabase()
    {
        SQLiteDatabase db = eventDatabase.getReadableDatabase();

    }

    @Override
    public void onClick(View v)
    {
        if (v != btnNext)
            return;

        int oldValue = value.getCount();

        value.setCount(oldValue + 1);

        //Intent intent = new Intent(this, Dashboard.class);
        //intent.putExtra("data", value);
        //startActivity(intent);

    }
}