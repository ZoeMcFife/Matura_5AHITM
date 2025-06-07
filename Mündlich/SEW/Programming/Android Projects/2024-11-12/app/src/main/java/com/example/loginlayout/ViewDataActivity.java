package com.example.loginlayout;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.example.loginlayout.database.CatColumnConstants;
import com.example.loginlayout.database.CatDatabase;

public class ViewDataActivity extends AppCompatActivity {

    TextView textOutput;
    CatDatabase catDatabase;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_view_data);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        textOutput = findViewById(R.id.textOutput);
        catDatabase = new CatDatabase(this);

        displayCatData();
    }

    private void displayCatData() {
        SQLiteDatabase db = catDatabase.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + CatColumnConstants.CAT_TABLE, null);

        StringBuilder dataBuilder = new StringBuilder();

        if (cursor.moveToFirst()) {
            do {
                int id = cursor.getInt(cursor.getColumnIndexOrThrow(CatColumnConstants._ID));
                String name = cursor.getString(cursor.getColumnIndexOrThrow(CatColumnConstants.CAT_NAME_COLUMN));
                int age = cursor.getInt(cursor.getColumnIndexOrThrow(CatColumnConstants.CAT_AGE_COLUMN));

                dataBuilder.append("🐱 ID: ").append(id)
                        .append("\n📛 Name: ").append(name)
                        .append("\n🎂 Age: ").append(age).append(" years\n\n");
            } while (cursor.moveToNext());
        } else {
            dataBuilder.append("No cat data found! 🐾");
        }

        textOutput.setText(dataBuilder.toString());
        cursor.close();
        db.close();
    }
}