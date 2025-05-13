package RecursiveHomeDirectory;

import java.io.IOException;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        JavaFilesByteCounter byteCounter = new JavaFilesByteCounter();

        byteCounter.calculateTotalFileSize(System.getProperty("user.home"));

        System.out.println(byteCounter.totalFileSize + " Bytes");
    }
}
