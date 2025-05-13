#include <stdio.h>
#include <stdlib.h>

//hilfstring anlegen                char hilf[GROESSE]
//in Hilfstring die "Zahl" einlesen gets(oder fgets)
//hilfstring in Zahl konvertieren   strtol oder strtod
//Fehlerbehandlung                  über eptr

long readLong(short *success);
//void selectionSort(int array[], int len);

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};

    selectionSort(arr, 5);
    printArray(arr, 5);

    return EXIT_SUCCESS;
}

/*void selectionSort(int array[], int len)
{
    int currentLargestNum = 0;
    int i, j;

    for (i = 0; i < len - 1; i++)
    {

        currentLargestNum = i;
        for (j = i+1; j < len; j++)
        {
            if(array[j] > array[currentLargestNum])
            {
                currentLargestNum = j;
            }
        }


        if(currentLargestNum < array[i])
            {
                currentLargestNum = array[i];
            }
        }

        swap(&array[currentLargestNum], array[i]);
    }
*/



long readLong(short *success)
{

    char string[21] = "";
    char *eptr = NULL;

    long num = 0;

    printf("Zahl:   ");
    gets(string);

    //3.
    num = strtol(string, &eptr, 10);
    if(*eptr != '\0' || string[0] == '\0' /*eptr == zahlAlsString*/)
    {
        *success = EXIT_FAILURE;
    }
    else
    {
        *success = EXIT_SUCCESS;
        return num;
    }

}



    /*
        //1.
    char zahlAlsString[21] = "";
    char *eptr = NULL;

    long zahl = 0;

    //2,
    printf("Zahl:   ");
    gets(zahlAlsString);

    //3.
    zahl = strtol(zahlAlsString, &eptr, 10);
    //if(*eptr != '\0' || zahlAlsString[0] == '\0' /*eptr == zahlAlsString*/
    /*
    {
        printf("FEHLER BEI DER ANGABE\n");
            printf("%ld \teptr: %s\n", zahl, eptr);
    }
    else
    {
        printf("CORREKT\n");
            printf("%ld \teptr: %s\n", zahl, eptr);

    }*/
