#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool checkPassword(char password[]);
int verdoppleFeld(int felf[], int size)
{
    int i;

    for(i = 0; i<size; i++)
    {
        felf[i]*=2;
    }
}

int main()
{

    char p[] = "123456789Aa";
    printf("%d", checkPassword(p));
    int f[10] = {1, 2, 3, 4, 5};
    verdoppleFeld(f, 5);

    return EXIT_SUCCESS;
}

bool checkPassword(char password[])
{
    long len = 0;
    short upper = 0, lower = 0, digit = 0;
    int i;
    len = strlen(password);

    if(len < 10)
    {
        return false;
    }

    for(i = 0; i < len - 1; i++)
    {
       if(isupper(password[i]))
       {
           upper++;
       }
       else if(islower(password[i]))
        {
            lower++;

        }
        else if(isdigit(password[i]))
        {
            digit++;
        }
    }

    if(upper > 0 && lower > 0 && digit > 0)
    {
        return true;
    }
}
