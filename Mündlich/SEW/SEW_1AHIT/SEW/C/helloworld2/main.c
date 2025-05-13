#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getche() getch() unterschied: Ohne Tastaturbuffer (ch) che wird ausgegeben

#define PI 3.141592

int main()
{
 /*
    double area = 0.0, radius = 0.0, circumference = 0.0;

    printf("Radius[cm]: ");
    scanf("%lf", &radius);

    circumference = 2 * radius * PI;
    area = pow(radius, 2) * PI;

    printf("Area[cm^2]: %lf  Circumference[cm]: %lf", area, circumference);
*/

    char plain = 0, cipher = 0;
    short key = 0;

    printf("Plain: ");
    scanf("%c", &plain);

    //plain = getchar(); just like scanf("%c", plain;  putch() char ausdrucken

    //delete Keyboard buffer
    fflush(stdin);

    printf("Key: ");
    scanf("%hd", &key);


    cipher = plain + key;

    if (cipher > 'Z')
    {
        cipher = cipher - 26;
    }

    //cipher = (plain - 65 + key) % 26 + 65;

    printf("%c", cipher);


    return EXIT_SUCCESS;
}
