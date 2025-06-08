using System.Net.Sockets;
using System.Net;
using System.Text;

namespace SockClient
{
    class SocketClient
    {
        static void Main()
        {
            IPAddress ip = IPAddress.Loopback;
            int port = 5000;

            Socket client = new Socket(
                AddressFamily.InterNetwork,
                SocketType.Stream,
                ProtocolType.Tcp
            );
            client.Connect(new IPEndPoint(ip, port));

            byte[] data = Encoding.UTF8.GetBytes("Hello from raw socket client!");
            client.Send(data);

            byte[] buffer = new byte[1024];
            int received = client.Receive(buffer);
            Console.WriteLine("Server replied: " + Encoding.UTF8.GetString(buffer, 0, received));

            client.Close();
        }
    }
}
