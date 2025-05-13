package Databas;

import java.sql.*;
import java.util.Collections;

public class DBAccess
{
    public static void main(String[] args)
    {
        Collections.list(DriverManager.getDrivers()).forEach(driver -> System.out.println(driver.getClass().getName()));

        try (Connection connection = DriverManager.getConnection("jdbc:mariadb://localhost:3306/FitnessCenter", "root", ""))
        {
            Statement statement = connection.createStatement();
            ResultSet query = statement.executeQuery("SELECT * FROM mitarbeiter");

            while (query.next())
            {
                System.out.println(query.getString("Name"));
            }

            System.out.println("Prepared Stamement");

            PreparedStatement preparedStatement = connection.prepareStatement("SELECT COUNT(*) AS a FROM mitarbeiter WHERE name = ?");

            preparedStatement.setString(1, "Ann Stoss");

            ResultSet resultSet = preparedStatement.executeQuery();

            while (resultSet.next())
            {
                System.out.println(resultSet.getInt(1));
            }

        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
    }

}
