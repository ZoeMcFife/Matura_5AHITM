package com.example.loginlayout.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class CatDatabase extends SQLiteOpenHelper
{
    private static final String DATABASE_NAME = "cat.db";
    private static final int DATABASE_VERSION = 1;

    private static final String CREATE_USERS_TABLE =
            "CREATE TABLE " + UserColumnConstants.USER_TABLE + " (" +
                    UserColumnConstants._ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    UserColumnConstants.USERNAME_COLUMN + " TEXT NOT NULL, " +
                    UserColumnConstants.EMAIL_COLUMN + " TEXT NOT NULL UNIQUE, " +
                    UserColumnConstants.PASSWORD_COLUMN + " TEXT NOT NULL);";

    private static final String CREATE_CATS_TABLE =
            "CREATE TABLE " + CatColumnConstants.CAT_TABLE + " (" +
                    CatColumnConstants._ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    CatColumnConstants.CAT_NAME_COLUMN + " TEXT NOT NULL, " +
                    CatColumnConstants.CAT_AGE_COLUMN + " INTEGER NOT NULL);";

    public CatDatabase(Context context)
    {
        super(context, "DATABASE_NAME", null, DATABASE_VERSION);
    }

    public CatDatabase(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db)
    {
        db.execSQL(CREATE_USERS_TABLE);
        db.execSQL(CREATE_CATS_TABLE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion)
    {
        db.execSQL("DROP TABLE IF EXISTS " + UserColumnConstants.USER_TABLE);
        db.execSQL("DROP TABLE IF EXISTS " + CatColumnConstants.CAT_TABLE);
        onCreate(db);
    }
}
