using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car
{
    internal class Car
    {
        public string Type {  get; set; }
        
        private int _yearOfManufacturing = 2000;
        public int YearOfManufacturing
        {
            get { return _yearOfManufacturing; }
            set
            {
                if (value < 1980) return;

                _yearOfManufacturing = value;
            }
        }

        public bool EngineRunning { get; set; }

        public float Price { get; set; }

        public Color Color { get; set; } = Color.Black;

        public int Age
        {
            get
            {
                return DateTime.Now.Year - YearOfManufacturing;
            }
        }

        public Car(string type)
        {
            Type = type;
        }

        public Car(string type, int yearOfManufacturing, bool engineRunning)
        {
            Type = type;
            YearOfManufacturing = yearOfManufacturing;
            EngineRunning = engineRunning;
        }

        public Car(string type, int yearOfManufacturing, bool engineRunning, Color color, float price)
        {
            Type = type;
            YearOfManufacturing = yearOfManufacturing;
            EngineRunning = engineRunning;
            Price = price;
            Color = color;
        }

        public void KillEngine()
        {
            EngineRunning = false;
        }

        public void StartEngine()
        {
            EngineRunning = true;
        }

        public override string ToString()
        {
            return String.Format("{0}, YoM: {1}, engine: {2}, color: {3}, price: {4}", Type, YearOfManufacturing, EngineRunning == true ? "on" : "off", Color, Price);
        }
    }
}
