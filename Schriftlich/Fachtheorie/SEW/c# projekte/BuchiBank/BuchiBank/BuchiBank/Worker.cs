using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BuchiBank
{
    abstract class Worker
    {
        public BankAccount Account { get; set; }
        public int WaitTime { get; set; } = 1;

        private Random Rng { get; set; } = new Random();

        public Worker(BankAccount account, int waitTime)
        {
            Account = account;
            WaitTime = waitTime;
        }

        /*
         * Um Threads für X Sekunden laufen zu lassen
         * verwende Stopwatch klasse
         * 
         */

        public async Task RunForDurationAsync(int seconds)
        {
            Console.WriteLine();
            Console.WriteLine($"{GetType().Name} will run for {seconds} seconds.");
            Console.WriteLine();

            var stopwatch = Stopwatch.StartNew();

            while (stopwatch.Elapsed.TotalSeconds < seconds)
            {
                await Start();
            }

            Console.WriteLine();
            Console.WriteLine($"{GetType().Name} finished running for {seconds} seconds.");
            Console.WriteLine();
        }

        public async Task Start()
        {
            await Action();
            await Task.Delay(WaitTime * 1000);
        }

        public double GetRandomNumber()
        {
            return Rng.NextDouble() * 100;
        }

        public abstract Task Action();
    }
}
