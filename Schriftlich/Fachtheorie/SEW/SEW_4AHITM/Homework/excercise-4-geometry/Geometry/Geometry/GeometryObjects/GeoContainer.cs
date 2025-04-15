using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeometryApp
{
    internal class GeoContainer
    {
        public List<Geometry> Shapes { get; private set; } = new List<Geometry>();

        public void AddGeometry(Geometry geometry)
        {
            Shapes.Add(geometry);
        }

        public void PrintOutAllColors()
        {
            string colors = String.Empty;

            foreach (Geometry geometry in Shapes) 
            {
                colors += geometry.Color + " ";
            }

            Console.WriteLine("Container: " + colors);

        }
    }
}
