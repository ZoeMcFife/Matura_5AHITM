package Networking;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class ClientHandler implements Runnable
{
    public Socket socket;
    public DataOutputStream outputStream;
    public DataInputStream inputStream;

    public ClientHandler(Socket socket, DataInputStream inputStream, DataOutputStream outputStream)
    {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
        this.socket = socket;
    }

    @Override
    public void run()
    {
        try
        {
            while (true)
            {
                /* Get answer from client*/
                String get = inputStream.readUTF();

                if (get.equals("Exit"))
                {
                    System.out.println("Client " + socket + " sends exit ...");
                    System.out.println("Closing this connection?");
                    socket.close();
                    System.out.println("Connection closed. Goodbye");
                    break;
                }

                switch (get)
                {
                    case "INIT" -> System.out.println("INIT");
                    case "ADD" -> System.out.println("ADD");
                    default -> System.out.println("PYROCINICAL");
                }
            }

            inputStream.close();
            outputStream.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}

