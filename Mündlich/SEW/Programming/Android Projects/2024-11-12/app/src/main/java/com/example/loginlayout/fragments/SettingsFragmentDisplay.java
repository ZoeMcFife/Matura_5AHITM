package com.example.loginlayout.fragments;

import android.os.Bundle;

import androidx.preference.PreferenceFragmentCompat;

import com.example.loginlayout.R;

public class SettingsFragmentDisplay extends PreferenceFragmentCompat {

    @Override
    public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
        setPreferencesFromResource(R.xml.root_preferences, rootKey);
    }
}