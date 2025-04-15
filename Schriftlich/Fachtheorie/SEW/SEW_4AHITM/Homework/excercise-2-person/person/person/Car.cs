using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Person
{
    internal class Car
    {
        public int YearOfManufacturing { get; set; } = 1980;
        public string Type { get; set; } = "N. N.";
        public bool EngineRunning { get; set; } = false;
        public Color Color { get; set; } = Color.Black;
        public float Price { get; set; } = 0.0f;

        public Car(string type)
        {
            Type = type;
        }

        public Car(string type, int yearOfManufacturing, bool engineRunning): this (type) 
        {
            YearOfManufacturing = yearOfManufacturing;
            EngineRunning = engineRunning;
        }

        public Car(string type, int yearOfManufacturing, bool engineRunning, Color color, float price) : this(type, yearOfManufacturing, engineRunning)
        {
            Color = color;
            Price = Price;
        }

        public static float operator +(Car a,  Car b) => a.Price + b.Price;
    }
}
