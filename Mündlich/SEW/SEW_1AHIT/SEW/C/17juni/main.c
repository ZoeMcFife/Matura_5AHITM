#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct fraction
{
    int count;
    int denominator;

};

void printFraction(struct fraction f);
void reciprocal(struct fraction *f);
void addFraction(struct fraction f1, struct fraction f2, struct fraction *result, bool simplify);

int main()
{
    struct fraction f = {7, 14};
    struct fraction f2 = {1, 4};
    struct fraction f3;

    addFraction(f, f2, &f3, true);
    printFraction(f3);

    return EXIT_SUCCESS;
}

void printFraction(struct fraction f)
{
    printf("%d\n--\n%d\n", f.count, f.denominator);
}

void reciprocal(struct fraction *f)
{
    int temp = 0;

    temp = f->count;
    f->count = f->denominator;
    f->denominator = temp;
}

void addFraction(struct fraction f1, struct fraction f2, struct fraction *result, bool simplify)
{
    int commonDenominator;

    commonDenominator = f1.denominator * f2.denominator;
    result->denominator = commonDenominator;


    f1.count = f1.count * f2.denominator;
    f2.count = f2.count * f1.denominator;

    result->count = f1.count + f2.count;

    int i = result->count/2;

    if (simplify)
    {
        while (i > 0)
        {
            if (result->count % i == 0 && result->denominator % i == 0)
            {
                result->count = result->count / i;
                result->denominator = result->denominator / i;
            }
            i--;
        }
    }
}
