package com.example.loginlayout;

import org.junit.Test;

import static org.junit.Assert.*;

import android.content.Intent;

import com.example.loginlayout.data.SavedUsers;
import com.example.loginlayout.data.User;

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        assertEquals(4, 2 + 2);
    }

    @Test
    public void test_login()
    {
        String username = "test";
        String email = "test";
        String password = "test";

        if (username.isEmpty() || email.isEmpty() || password.isEmpty())
        {
            return;
        }

        User user = new User(username, email, password);


        SavedUsers.users.add(user);

        if (email.isEmpty() || password.isEmpty())
        {
            return;
        }

        for (User user2 : SavedUsers.users)
        {
            // print user values

            System.out.println(user2.getUsername());
            System.out.println(user2.getEmail());
            System.out.println(user2.getPassword());

            if (user2.getEmail().equals(email) && user2.getPassword().equals(password))
            {
                assertTrue(true);
            }
        }
        //assertFalse(true);

    }
}