using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeometryApp
{
    internal class Line : ILine
    {
        private Point[] pointArr = new Point[5];

        public Line() 
        {
            this[0] = new Point(0, 0);
        }

        public Line(Point a, Point b)
        {
            this[0] = a;
            this[1] = b;
        }

        public Point this[int index] 
        { 
            get { return pointArr[index]; }
            set { pointArr[index] = value;}
        }

        public override string ToString() 
        {
            string points = string.Empty;

            foreach (Point p in pointArr) 
            {
                points += "[" + p.ToString() + "] ";
            }

            return "Points: " + points;
        }

    }
}
