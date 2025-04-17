package Fraction;

import java.util.Objects;

public class Fraction
{
    int n;	// numerator
    int d; 	// denominator
    static int fractionCounter = 0;

    // constructor
    Fraction (int n, int d)
    {
        this.n = n;
        this.d = d;
        fractionCounter++; // new object created -> increase counter
    }

    // default constructor
    Fraction ()
    {
        this.n=0;
        this.d=1;
        fractionCounter++; // new object created -> increase counter
    }

    Fraction(Fraction f)
    {
        this.n = f.n;
        this.d = f.d;
        fractionCounter++;
    }

    void add (Fraction f)
    {
        this.n = this.n * f.d + f.n * this.d;
        this.d = this.d * f.d;
    }

    void subtract (Fraction f)
    {
        this.n = this.n * f.d - f.n * this.d;
        this.d = this.d * f.d;
    }

    void multiply (Fraction f)
    {
        this.n = this.n * f.n;
        this.d = this.d * f.d;
    }

    void divide (Fraction f)
    {
        Fraction f2 = new Fraction(f);

        this.n = (this.n * f2.d);
        this.d = (this.d * f2.n);
    }

    public String toString()
    {
        String str = super.toString();
        str += "\n" + this.n + " / " + this.d;
        return str;
    }

    public void negate()
    {
        if (this.n < 0)
            this.n = this.n * -1;
        else if (this.d < 0)
            this.d = this.d * -1;
        else
            this.n = this.n * -1;
    }

    public void invert()
    {
        int temp = this.n;
        this.n = this.d;
        this.d = temp;
    }

    public double toDouble()
    {
        return (double) this.n / this.d;
    }

    public Fraction reduce()
    {
        if (this.d == this.n)
            return new Fraction(1, 1);

        int newD = this.d;
        int newN = this.n;

        for (int i = 1; i <= this.n; i++)
        {
            if (newD % i == 0 && newN % i == 0)
            {
                newD = newD / i;
                newN = newN / i;
            }
        }

        return new Fraction(newN, newD);
    }


    static void resetFractionCounter()
    {
        fractionCounter = 0;
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Fraction fraction = ((Fraction) o).reduce();
        Fraction fraction2 = this.reduce();

        return fraction.n == fraction2.n && fraction2.d == fraction.d;
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(this.n, this.d);
    }

    public static void main(String[] args)
    {
        Fraction a = new Fraction();
        a.n=1;
        a.d=2;
        System.out.println(a.toString());

        Fraction b = new Fraction(3,5);
        System.out.println(b.toString());

        System.out.println("Multiply obj a with obj b: ");
        a.multiply(b);
        System.out.println(a.toString());

        /* Attention*/
        System.out.println("Divide obj a by obj a: ");
        a.divide(a);
        System.out.println(a.toString());

        System.out.println("Number of created Objects: " + Fraction.fractionCounter);
        Fraction.resetFractionCounter();

        System.out.println("Negate obj a");
        a.negate();
        System.out.println(a);

        System.out.println("Invert obj a");
        a.invert();
        System.out.println(a);

        System.out.println("Obj a to double");
        System.out.println(a.toDouble());

        System.out.println("Reduce obj a");
        System.out.println(a.reduce());
    }
}
