package com.example.demo.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class EventDatabase extends SQLiteOpenHelper
{
    private static final String DATABASE_NAME = "eventlogger.db";
    private static final int DATABASE_VERSION = 1;

    public EventDatabase(Context context)
    {
        super(context, "DATABASE_NAME", null, DATABASE_VERSION);
    }

    public EventDatabase(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version)
    {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db)
    {
        /* THIS IS HORRIBLE CODE.*/
        db.execSQL("CREATE TABLE " + ColumnConstants.TABLE_NAME + "(" + ColumnConstants._ID +
                " INTEGER PRIMARY KEY AUTOINCREMENT, " +
                ColumnConstants.TIME + " INTEGER," +
                " " + ColumnConstants.EVENT + " TEXT NOT NULL);");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion)
    {
        db.execSQL("DROP TABLE IF EXISTS " + ColumnConstants.TABLE_NAME + ";");
        onCreate(db);
    }
}
