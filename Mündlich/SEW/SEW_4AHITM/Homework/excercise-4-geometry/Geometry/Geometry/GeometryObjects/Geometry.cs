using System;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeometryApp
{
    internal abstract class Geometry : IGeometricFunctions
    {
        public Point Position { get; set; }
        public Color Color { get; set; } = Color.Red;

        public Geometry(int x, int y)
        {
            Position = new Point(x, y);
        }

        public Geometry(Point position)
        {
            Position = position;
        }

        public Geometry(Point point, Color color) : this(point)
        {
            Color = color;
        }

        public Geometry(int x, int y, Color color) : this(x, y)
        {
            Color = color;
        }

        public abstract double CalculateArea();
        public abstract double CalculateCircumference();

        public override string ToString()
        {
            return $"{Position} {Color}";
        }
    }
}
