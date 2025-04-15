using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeometryApp
{
    internal struct Point : IPoint
    {
        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public int x {  get; set; } 
        public int y { get; set; }

        public static bool operator ==(Point a, Point b)
        {
            if (a.y == b.y && a.x == b.x) return true;
            
            return false;
        }

        public static bool operator !=(Point a, Point b)
        {
            if (a.y == b.y && a.x == b.x) return false;

            return true;
        }

        public override string ToString()
        {
            return $"X: {x} Y: {y}";
        }
    }
}
