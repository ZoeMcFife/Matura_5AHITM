using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace complex_numbers
{
    internal class Complex : IComplex, IEquatable<Complex>
    {
        public double Real { get; set; }
        public double Imaginary { get; set; }

        public static int CountComplex { get; private set; } = 0;

        public bool IsComplex
        {
            get
            {
                return Imaginary != 0;
            }
        }      

        static Complex()
        {
            Console.WriteLine("Class Complex successfully loaded");
        }

        public Complex() 
        { 
            Real = 0;
            Imaginary = 0;
            CountComplex++;
        }

        public Complex(double real) : this()
        {
            Real = real;
        }

        public Complex(double real, double imaginary) : this(real)
        {
            Imaginary = imaginary;
        }

        ~Complex()
        {
            CountComplex--;
        }

        public static Complex operator +(Complex a, Complex b) { return new Complex(a.Real + b.Real, a.Imaginary + b.Imaginary); }
        public static Complex operator -(Complex a, Complex b) { return new Complex(a.Real - b.Real, a.Imaginary - b.Imaginary); }
        public static Complex operator *(Complex a, Complex b) { return new Complex(a.Real * b.Real - a.Imaginary * b.Imaginary, a.Real * b.Imaginary + a.Imaginary * b.Real); }


        public static Complex Mul(Complex a, Complex b) => a * b;
        public static Complex Add(Complex a, Complex b) => a + b;
        public static Complex Sub(Complex a, Complex b) => a - b;

        public Complex Mul(Complex b) => this * b;
        public Complex Add(Complex b) => this + b;
        public Complex Sub(Complex b) => this - b;

        public void PrintOut()
        {
            Console.WriteLine(Real + (Imaginary >= 0 ? "+" : "") + Imaginary + "i");
        }

        public bool Equals(Complex? other)
        {
            if (other is null) return false;

            return Real == other.Real && Imaginary == other.Imaginary;
        }
    }
}
