using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeometryApp
{
    internal class Rectangle : Geometry
    {
        private double _width;
        public double Width 
        { 
            get
            {
                return _width;
            }

            set 
            {
                if (value < 0) return;
                _width = value;
            } 
        }

        private double _height;
        public double Height
        {
            get
            {
                return _height;
            }

            set
            {
                if (value < 0) return;
                _height = value;
            }
        }

        public Rectangle(Point position, double width, double height) : base(position)
        {
            Width = width;
            Height = height;
        }

        public Rectangle(int x, int y, double width, double height) : base(x, y)
        {
            Width = width;
            Height = height;
        }

        public Rectangle(Point position, Color color, double width, double height) : base(position, color)
        {
            Width = width;
            Height = height;
        }

        public Rectangle(int x, int y, Color color, double width, double height) : base(x, y, color)
        {
            
            Width = width;
            Height = height;
        }

        public override double CalculateArea()
        {
            return Width * Height;
        }

        public override double CalculateCircumference()
        {
            return 2 * (Height + Width);
        }

        public override String ToString()
        {
            return GetType().Name + " " + base.ToString() + " Width: " + Width + " Height: " + Height;
        }
    }
}
