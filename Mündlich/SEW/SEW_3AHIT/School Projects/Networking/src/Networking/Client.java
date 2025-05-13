package Networking;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client
{
    public static void main(String[] args)
    {
        start();
    }

    public static void start()
    {
        Scanner scanner = new Scanner(System.in);

        try
        {
            InetAddress ip = InetAddress.getByName("localhost");
            Socket socket = new Socket(ip, 8080);
            DataInputStream inputStream = new DataInputStream(socket.getInputStream());
            DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());

            while (true)
            {
                String tpsend = scanner.nextLine();
                outputStream.writeUTF(tpsend);

                if (tpsend.equals("Exit"))
                {
                    System.out.println("Closing " + socket);
                    socket.close();;
                    System.out.println("CLOSRD");
                    break;
                }
            }

            socket.close();
            inputStream.close();
            outputStream.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }


    }
}
