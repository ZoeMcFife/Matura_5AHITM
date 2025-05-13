using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    internal class Program
    {
        public static void Main()
        {
            FinnAndJake();

            Console.ReadKey();
        }

        public static void FinnAndJake()
        {
            List<Thread> threads = new List<Thread>();

            BankAccount finn = new BankAccount(200, "Finn");
            BankAccount jake = new BankAccount(200, "Jake");

            for (int i = 0; i < 20; i++)
            {
                threads.Add(new Thread(() => finn.Transfer(10, jake)));
            }

            for (int i = 0; i < 20; i++)
            {
                threads.Add(new Thread(() => jake.Transfer(10, finn)));
            }


            foreach (Thread t in threads)
            {
                t.Start();
            }

            foreach (Thread t in threads)
            {
                t.Join();
            }

            Console.WriteLine("Finn should have 200 Credits. He has {0}.", finn.Balance);
            Console.WriteLine("Jake should have 200 Credits. He has {0}.", jake.Balance);
        }

        public static void John()
        {
            List<Thread> threads = new List<Thread>();

            BankAccount john = new BankAccount(200, "John");

            for (int i = 0; i < 20; i++)
            {
                threads.Add(new Thread(() => john.Withdraw(10)));
            }

            for (int i = 0; i < 20; i++)
            {
                threads.Add(new Thread(() => john.Deposit(10)));
            }

            foreach (Thread t in threads)
            {
                t.Start();
            }

            foreach (Thread t in threads)
            {
                t.Join();
            }

            Console.WriteLine("John should have 200 Credits. He has {0}.", john.Balance);

        }
    }
}
