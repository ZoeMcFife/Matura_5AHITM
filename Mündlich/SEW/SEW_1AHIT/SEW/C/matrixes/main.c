#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int matrix[3][3] = {{1, 2, 3},{6, 7, 8}, {9, 12, 32}};

    int i, j, k =33, l;



    while (matrix[1][1] < 32)
    {
    printf("tesz");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%10d  ", matrix[i][j]);
        }
        printf("\n \n \n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matrix[i][j] += 1;
        }
    }
    }

    return 0;
}
