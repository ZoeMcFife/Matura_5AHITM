using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace GeometryApp
{
    internal class Square : Geometry
    {
        private double _length;
        public double Length
        {
            get
            {
                return _length;
            }

            set
            {
                if (value < 0) return;
                _length = value;
            }
        }

        public Square(Point position, double length) : base(position)
        {
            Length = length;
        }

        public Square(int x, int y, double length) : base(x, y)
        {
            Length = length;
        }

        public Square(Point position, Color color, double length) : base(position, color)
        {
            Length = length;
        }

        public Square(int x, int y, Color color, double length) : base(x, y, color)
        {

            Length = length;
        }

        public override double CalculateArea()
        {
            return Length * Length;
        }

        public override double CalculateCircumference()
        {
            return  Length * 4;
        }

        public override String ToString()
        {
            return GetType().Name + " " + base.ToString() + " Lenght: " + Length; 
        }
    }
}
