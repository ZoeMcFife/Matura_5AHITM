using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace GeometryApp
{
    internal class Circle : Geometry
    {
        private double _radius;
        public double Radius
        {
            get { return _radius; }
            set
            {
                if (value < 0 || value > 100) return;
                _radius = value;

                _radiusText = value.ToString();
            }
        }

        private string _radiusText = "0.0";
        public string RadiusText
        {
            get { return _radiusText; }

            set
            {
                double radius = -1;

                double.TryParse(value.Replace('.', ','), out radius);

                if (radius < 0 || radius > 100) return;

                Radius = radius;
                _radiusText = value;
            }
        }

        public Circle(Point position, double radius) : base(position)
        {
            Radius = radius;
        }

        public Circle(int x, int y, double radius) : base(x, y)
        {
            Radius = radius;
        }

        public Circle(Point point, Color color, double radius) : base(point, color)
        {
            Radius = radius;
        }

        public Circle(int x, int y, Color color, double radius) : base(x, y, color)
        {
            Radius = radius;
        }

        public static Circle operator +(Circle c, double radius) { return new Circle(c.Position, c.Color, c.Radius + radius); }

        public override double CalculateArea()
        {
            return Radius * Radius * Math.PI;
        }
    
        public override double CalculateCircumference()
        {
            return Radius * 2 * Math.PI;
        }

        public override String ToString()
        {
            return GetType().Name + " " + base.ToString() + " Radius: " + RadiusText;
        }
    }
}
