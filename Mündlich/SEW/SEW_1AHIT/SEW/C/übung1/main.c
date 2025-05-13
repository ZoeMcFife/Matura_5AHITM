#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputValues(int f[]);
void sortArray(int f[]);

int main()
{
    int array[10] = {0};
    int i;

    inputValues(array);
    for(i = 9; i>=0; i--)
    {
        printf("%d \n", array[i]);
    }

    printf("\n");

    sortArray(array);

    for(i = 0; i < 10; i++)
    {
        printf("%d \n", array[i]);
    }

    return EXIT_SUCCESS;
}

int inputValues(int f[])
{
    int i;

    printf("Enter 10 integers: \n");

    for(i = 0; i < 10; i++)
    {
        printf("%d: ", i);
        scanf("%d", &f[i]);
    }
}

void sortArray(int f[])
{
    int i = 0, j = 0, k = 0, size = 10;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size - 1-i; j++)
        {
            if(f[j] < f[j + 1])
            {
                k = f[j];
                f[j] = f[j + 1];
                f[j + 1] = k;
            }
        }
    }
}
