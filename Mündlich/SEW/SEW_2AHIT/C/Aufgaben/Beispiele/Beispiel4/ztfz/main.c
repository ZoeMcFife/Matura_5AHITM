#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    fp = fopen("test.owo", "wb");

    int a[20] = {3};
    int c[21];
    int b = 1;

    fwrite(a, sizeof(int), 20, fp);
    fwrite(&b, sizeof(int), 1, fp);

    fclose(fp);

    fp = fopen("test.owo", "rb");

    fread(&c, sizeof(int), 21, fp);

    fclose(fp);

    for (b = 0; b < 21; b++)
    {
        printf("%d \n", c[b]);
    }

    return 0;
}
