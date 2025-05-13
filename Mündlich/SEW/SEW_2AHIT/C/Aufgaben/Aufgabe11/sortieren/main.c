#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
	char name[12];
	char familyName[12];
	char telephone[24];
	Date birth;
} Person;


void output(Person p[], int gr);
int comparePerson(const void * ptrLeft, const void * ptrRight); /// also compares the moral values of a person                                                  my jokes are really unfunny ...

int compare(const void * ptrLeft, const void * ptrRight);
void printIntArray(int array[], int size);

int specialCompare(const void * ptrLeft, const void * ptrRight);


int main()
{
    int array[10] = {35, 23, 1, 15, 531, 35, 2, 5, 10, 69};
    Person personArray[10]  =  {{"Stein","Gerold","07412/123",{1,2,2013}},
                         {"Lee","Chi","01/999",{30,1,2014}},
                         {"Bino","Al","01/888",{4,6,2015}},
                         {"Stein","Frank N.","01/777",{13,12,2012}},
                         {"Wuchs","Bart","01/666",{24,12,2014}},
                         {"Rohsoft","Mike","0664/111",{23,12,2014}},
                         {"Isko","San Franz","0676/333",{25,12,2014}},
                         {"Zufall","Rainer","0680/444",{13,1,2015}},
                         {"Nette","Mario","0699/555",{30,12,2016}},
                         {"Lee","Nux","07412/321",{18,8,2013}}
                         };
    int anotherIntArray[10] = {3, 2, 6, 4, 1, 5, 7, 9, 8, 4};

    printIntArray(array, sizeof(array) / sizeof(int));
    qsort(array, sizeof(array) / sizeof(int), sizeof(int), compare);
    printIntArray(array, sizeof(array) / sizeof(int));

    output(personArray, 10);
    qsort(personArray, 10, sizeof(Person), comparePerson);
    output(personArray, 10);


    printIntArray(anotherIntArray, sizeof(anotherIntArray) / sizeof(int));
    qsort(anotherIntArray, sizeof(anotherIntArray) / sizeof(int), sizeof(int), specialCompare);
    printIntArray(anotherIntArray, sizeof(anotherIntArray) / sizeof(int));


    return EXIT_SUCCESS;
}

void printIntArray(int array[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int compare(const void * ptrLeft, const void * ptrRight)
{
    int left = *((int *)ptrLeft);
    int right = *((int *)ptrRight);

    return (left > right) - (left < right);
}


void output(Person p[], int gr)
{
    int i;
    printf("Family Name     Name      Birthday   Telephone\n");
    printf("------------------------------------------------------\n");
    for (i=0; i<gr; i++)
    {
        printf("%-12s %-12s %d-%02d-%02d     %s\n", p[i].familyName, p[i].name,
                           p[i].birth.year, p[i].birth.month, p[i].birth.day, p[i].telephone);
    }
    printf("\n");
}

int comparePerson(const void * ptrLeft, const void * ptrRight)
{
    Person left = *((Person *)ptrLeft);
    Person right = *((Person *)ptrRight);

    int compareValue = strcmp(left.name, right.name);

    switch (compareValue)
    {
        case 1:
            return 1;
        case -1:
            return -1;
        case 0:
            compareValue = strcmp(left.familyName, right.familyName);

            switch (compareValue)
            {
                case 1:
                    return 1;
                case -1:
                    return -1;
            }
    }

    return 0;
}

int specialCompare(const void * ptrLeft, const void * ptrRight)
{
    int left = *((int *)ptrLeft);
    int right = *((int *)ptrRight);

    if ((left & 1) != (right & 1)) /// one is odd, other is even --> using binary operator & to determine if a number is odd or even
    {
        if (left & 1) return 1;     /// if left is odd move it to the right
        return -1;                  /// else right must be odd --> move right to the left
    }

    if ((left & 1) == 1)   /// if both are odd
        return (left < right) - (left > right);    /// if left < right this returns -1 --> moves the right element to left and so on.... --> odd numbers are in descending order

    return (left > right) - (left < right);        /// if both are even  --> sorts in ascending order
}
