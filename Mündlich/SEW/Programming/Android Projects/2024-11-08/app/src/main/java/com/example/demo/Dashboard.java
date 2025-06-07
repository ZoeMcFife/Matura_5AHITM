package com.example.demo;

import static android.content.Intent.getIntent;
import static android.os.Build.VERSION_CODES.R;

import android.os.Bundle;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.example.demo.data.Data;
import com.example.demo.fragments.MyFragment;

public class Dashboard extends AppCompatActivity {

    private TextView txtOutput;
    private MyFragment fragMyFragment;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_dashboard);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        //int value = getIntent().getIntExtra("data", 0);

        fragMyFragment = (MyFragment) this.getSupportFragmentManager().findFragmentById(R.id.fragMyFragment);

        String value;
        Bundle bundle = getIntent().getExtras();

        if (bundle != null)
        {
            Data data = bundle.getParcelable("data", Data.class);
            value = Integer.toString(data != null ? data.getCount() : 0);
            fragMyFragment.setData(data);
        }
        else
        {
            value = "no data";
        }


        txtOutput = findViewById(R.id.txtOutput);

        txtOutput.setText(String.valueOf(value));

    }
}