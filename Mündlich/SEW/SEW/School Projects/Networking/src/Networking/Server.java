package Networking;

import java.io.DataInputStream;
import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server
{
    public static void main(String[] args)
    {
        start();
    }

    public static void start()
    {
        try
        {
            ServerSocket serverSocket = new ServerSocket(8080);
            System.out.println("Server Socket is ready...");

            while (true)
            {
                Socket socket = serverSocket.accept();
                DataInputStream inputStream = new DataInputStream(socket.getInputStream());
                DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());

                System.out.println("Accepting ben client.");

                Thread thread = new Thread(new ClientHandler(socket, inputStream, outputStream));
                thread.start();
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}
