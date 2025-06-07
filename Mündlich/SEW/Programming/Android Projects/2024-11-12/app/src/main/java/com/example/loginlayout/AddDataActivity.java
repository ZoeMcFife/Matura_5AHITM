package com.example.loginlayout;

import android.content.ContentValues;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.example.loginlayout.database.CatColumnConstants;
import com.example.loginlayout.database.CatDatabase;

public class AddDataActivity extends AppCompatActivity {

    Button submitData;
    EditText editCatName;
    EditText editCatAge;

    CatDatabase catDatabase;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_add_data);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        // Initialize UI components
        editCatName = findViewById(R.id.editCatName);
        editCatAge = findViewById(R.id.editCatAge);
        submitData = findViewById(R.id.submitData);

        // Initialize database helper
        catDatabase = new CatDatabase(this);

        // Handle button click
        submitData.setOnClickListener(v -> addCatData());
    }

    private void addCatData() {
        String catName = editCatName.getText().toString().trim();
        String catAgeStr = editCatAge.getText().toString().trim();

        if (catName.isEmpty() || catAgeStr.isEmpty()) {
            Toast.makeText(this, "Please enter all fields!", Toast.LENGTH_SHORT).show();
            return;
        }

        int catAge;
        try {
            catAge = Integer.parseInt(catAgeStr);
        } catch (NumberFormatException e) {
            Toast.makeText(this, "Invalid age input!", Toast.LENGTH_SHORT).show();
            return;
        }

        SQLiteDatabase db = catDatabase.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(CatColumnConstants.CAT_NAME_COLUMN, catName);
        values.put(CatColumnConstants.CAT_AGE_COLUMN, catAge);

        long result = db.insert(CatColumnConstants.CAT_TABLE, null, values);
        db.close();

        if (result == -1) {
            Toast.makeText(this, "Failed to add cat!", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "Cat added successfully!", Toast.LENGTH_SHORT).show();
            editCatName.setText("");
            editCatAge.setText("");
        }
    }
}