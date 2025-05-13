#include <stdio.h>
#include <stdlib.h>

void Usage ()
{
    printf("usage: console arguments idk ");
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
    printf("Hello world! %d\n", argc);
  printf("%s\n", argv[0]);
        printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    printf("%s\n", argv[3]);
    printf("%s\n", argv[4]);
    if (argc > 1)
        Usage();




    return 420;
}
