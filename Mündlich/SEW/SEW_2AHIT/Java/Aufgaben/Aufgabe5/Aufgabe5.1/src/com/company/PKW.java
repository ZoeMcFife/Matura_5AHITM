package com.company;

public class PKW
{
    private String brand;
    private int horsepower;

    // Constructors

    PKW()
    {
        this.brand = "unknown";
        this.horsepower = 0;
    }

    PKW(String brand, int horsepower)
    {
        this.brand = brand;
        setHorsepower(horsepower);
    }

    // Getters / Setters

    public String getBrand()
    {
        return brand;
    }

    public int getHorsepower()
    {
        return horsepower;
    }

    public void setHorsepower(int horsepower)
    {
        if (horsepower < 0)
        {
            this.horsepower = 0;
        }
        else
        {
            this.horsepower = horsepower;
        }
    }

    // to string


    @Override
    public String toString()
    {
        return "PKW{" +
                "brand='" + brand + '\'' +
                ", horsepower=" + horsepower +
                '}';
    }
}
