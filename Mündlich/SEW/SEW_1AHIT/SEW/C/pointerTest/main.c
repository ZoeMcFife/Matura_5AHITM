#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addArray(int *p, int n);
void denksport(int *num);

int main(int argc, char* argv[])
{
    int array[] = {1, 5, 2, 6, 4, 3}, result = 0;
    int owo = 5;
    int multiplier = 1;
    char *ptr = NULL;



    /*
    if(strcmp(argv[1], "cum") == 0)
    {
        printf("owo uwu *blushes* \n");
    }

    multiplier = multiplier * (int)strtol(argv[2], *ptr, 10);

    /*else
    {
        result = addArray(array, sizeof(array)/sizeof(int));
        printf("Sum: %d\n", result);
        denksport(array);
    }*/

    printf("this is a super duper cool number: %d\n", multiplier);*/

    return EXIT_SUCCESS;
}

int addArray(int *p, int n)
{
    int i = 0, sum = 0;

    for(i = 0; i < n; i++)
    {
        sum += *p;
        p++;
    }

    return sum;
}


void denksport(int *num)
{

 int *ptr=NULL;
 ptr=num+3;
 printf("\n%d",*(ptr+1));
 printf("\n%d",ptr[-1]);
 printf("\n%d",num-ptr);
 printf("\n%d",num[*(ptr++)]);
 printf("\n%d",*(num+num[2]));
 printf("\n%d",*ptr);
 printf("\n");
}
