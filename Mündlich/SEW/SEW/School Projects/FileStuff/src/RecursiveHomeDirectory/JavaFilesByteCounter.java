package RecursiveHomeDirectory;

import java.io.IOException;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.HashSet;

public class JavaFilesByteCounter
{
    public long totalFileSize;

    JavaFilesByteCounter()
    {
        this.totalFileSize = 0;
    }

    public void calculateTotalFileSize(String path) throws IOException
    {
        Path root = Path.of(path);

        Files.walkFileTree(root, new HashSet<>(),20, new FileVisitor<Path>()
        {
            @Override
            public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException
            {
                return FileVisitResult.CONTINUE;
            }

            @Override
            public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException
            {
                if (getFileExtension(file.toString()).equals("java"))
                    addToFileSize(attrs.size());

                return FileVisitResult.CONTINUE;
            }

            @Override
            public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException
            {
                return FileVisitResult.CONTINUE;
            }

            @Override
            public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException
            {
                return FileVisitResult.CONTINUE;
            }
        });
    }

    private void addToFileSize(long bytes)
    {
        this.totalFileSize += bytes;
    }

    private String getFileExtension(String fileName)
    {
        int i = fileName.lastIndexOf('.');
        if (i >= 0)
        {
            return fileName.substring(i+1);
        }
        return "";
    }
}
