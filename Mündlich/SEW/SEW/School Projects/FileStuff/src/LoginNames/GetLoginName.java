package LoginNames;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class GetLoginName
{
    public static void outputLoginNamesToFile()
    {
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");

        String loginName = System.getProperty("user.name");
        LocalDateTime currentLocalDateTime = LocalDateTime.now();
        String currentDateAndTime = dateTimeFormatter.format(currentLocalDateTime);

        Path path2 = Paths.get("./tmp/foo");

        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("test.txt")))
        {
            bufferedWriter.write("test");
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

        Path path = Paths.get(System.getProperty("user.home"), "java-info.tmp");

        try (BufferedWriter bufferedWriter = Files.newBufferedWriter(path, StandardOpenOption.CREATE))
        {
            bufferedWriter.write(loginName + " " + currentDateAndTime);
        }
        catch (IOException ioException)
        {
            ioException.printStackTrace();
        }
    }
}
