using System.Net;
using System.Net.Http.Headers;
using System.Net.Http.Json;

namespace AspScout
{

    public class Program
    {

        static void Main(string[] args)
        {
            UserInterface userInterface = new UserInterface();
            userInterface.Start();
        }

    }
}
