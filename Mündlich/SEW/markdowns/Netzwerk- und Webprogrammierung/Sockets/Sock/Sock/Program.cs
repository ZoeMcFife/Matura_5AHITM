using System;
using System.Net;
using System.Net.Sockets;
using System.Text;


namespace Sock
{
    class SocketServer
    {
        static void Main()
        {
            IPAddress ip = IPAddress.Any;
            int port = 5000;

            Socket listener = new Socket(
                AddressFamily.InterNetwork,
                SocketType.Stream,
                ProtocolType.Tcp
            );
            listener.Bind(new IPEndPoint(ip, port));
            listener.Listen(5);
            Console.WriteLine($"Socket server listening on port {port}");

            Socket client = listener.Accept();
            byte[] buffer = new byte[1024];
            int received = client.Receive(buffer);
            string msg = Encoding.UTF8.GetString(buffer, 0, received);
            Console.WriteLine("Received: " + msg);

            byte[] response = Encoding.UTF8.GetBytes("Echo: " + msg);
            client.Send(response);

            client.Close();
            listener.Close();
        }
    }
}


