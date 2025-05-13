#include <stdio.h>
#include <stdlib.h>

int binSearch2(int k, int a[], int l, int r)
{
int m;
if (l>r) return -1;
m=(l+r)/2;
if (k==a[m]) return m;
if (k<a[m]) return binSearch2(k, a, l , m);
if (k>a[m]) return binSearch2(k, a, m, r );
}

int main()
{
    int a[10] = {234, 32, 12, 15, 231, 11, 1, 15, 5,24};

    printf("Hello world!\n");

    printf("%d %d", 32, binSearch2(32, a,
                                   0, 9));

    return 0;
}
