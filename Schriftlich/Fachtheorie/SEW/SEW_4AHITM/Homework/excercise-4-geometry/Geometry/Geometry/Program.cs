using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace GeometryApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Geometry f1 = new Rectangle(50, 60, Color.Green, 30, 20); //x-Pos, y-Pos, Color, Length, Width
            Geometry f2 = new Circle(new Point(100, 120), Color.Blue, 30); //Position Point(x,y), Color, Radius
            Geometry f3 = new Square(new Point(200, 300), 20); //Position Point(x,y), Length=20
            Circle f4 = new Circle(new Point(10, 20), Color.Red, 50); //Position Point(x,y), Color, Radius
            Console.WriteLine("Rectangle f1:" + f1);
            Console.WriteLine("Circle f2:" + f2);
            Console.WriteLine("Square f3:" + f3);
            f4.RadiusText = "5.1"; // Radius will be set to 5.1
            f4.Radius = 101; // Not in range!
            Console.WriteLine();
            Console.WriteLine("Circle f4:" + (f4 + 0.5)); //adds 0.5 to the circles radius
            Console.WriteLine("Circle f4: Circ:{0,5:f1} – Area:{1,5:f1}", f4.CalculateCircumference(), f4.CalculateArea());
            Console.WriteLine("Square f3: Circ:{0,5:f1} – Área:{1,5:f1}", f3.CalculateCircumference(), f3.CalculateArea());
            Line s1 = new Line();
            Line s2 = new Line(new Point(6, 7), new Point(8, 9));
            s1[0] = new Point(1, 2);
            s1[1] = new Point(8, 9);
            s1[2] = new Point(5, 6);
            Console.WriteLine();
            Console.WriteLine(s1);
            Console.WriteLine(s2);
            Console.WriteLine("Comparison of two points:" + (s1[0] == s2[0]));
            Console.WriteLine("Comparison of two points:" + (s1[1] == s2[1]));
            Console.WriteLine();
            GeoContainer g = new GeoContainer();
            g.AddGeometry(f1);
            g.AddGeometry(f2);
            g.AddGeometry(f3);
            g.PrintOutAllColors();
            Console.ReadLine();
        }

    }
}
