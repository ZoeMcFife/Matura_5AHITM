#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define OUTPUTFILE "time.txt"
#define RANDOMNUMBERS 10

typedef struct node
{
    int data;
    struct node *next;
} node;

void printNodes(node **head);

void pushElement(int data, node **head);
void appendElement(int data, node **head);
void insertElement(unsigned int index, int data, node **head);
void insertSortedElement(int data, node **head);
int deleteElement(unsigned int index, node **head);
void deleteFirstElement(node **head);

int getListLength(node **head);
void cleanList(node **head);                    /// since everything breaks down if I don't initialize a list with a value, i'm setting the first Element as -1.
                                                /// these values are useless so i'm creating a function to delete them
void saveListToFile(node **head);               /// is there a way to initialize an empty list without breaking everything? ///edit I'm dumb
node* importListFromFile(char filename[20]);
bool doesImportFileExist();
int getLineCount(char filename[]);

int getInput(int *returnVal);
int getLongs(char string[], long output[]);

void testTimeRandom(node **timeList);
int* getRandomIntArray(unsigned int size, unsigned upperBound, int lowerBound);

int main()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    head->data = -1;

    if (doesImportFileExist() == true)
        head = importListFromFile(OUTPUTFILE);

    testTimeRandom(&head);

    cleanList(&head);

    saveListToFile(&head);

    printf("Your stats: \n");
    printNodes(&head);

    return EXIT_SUCCESS;
}

void saveListToFile(node **head)
{
    node *current = *head;
    FILE *fp;

    fp = fopen(OUTPUTFILE, "w");

    while (current != NULL)
    {
        fprintf(fp, "%d", current->data);
        if (current->next != NULL) fprintf(fp, "\n");
        current = current->next;
    }

    fclose(fp);
}

bool doesImportFileExist()
{
    if (access(OUTPUTFILE, F_OK) == 0)
        return true;

    return false;
}

node* importListFromFile(char filename[20])
{
    if (doesImportFileExist() == false)
        exit(EXIT_FAILURE);

    node *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    head->data = -1;

    char lineString[100];
    char arrayString[1000] = "";

    int arraySize = getLineCount(filename);
    long* array = (long *)malloc(sizeof(int) * arraySize);

    FILE *fp;

    int i;

    fp = fopen(filename, "r");

    for (i = 0; i < arraySize; i++)
    {
        fgets(lineString, 100, fp);
        strcat(arrayString, lineString);
        strcat(arrayString, " ");
    }

    int success = getLongs(arrayString, array);

    success == arraySize ? printf("Successfully read %d from %d values from file.\n", success, arraySize) : printf("ERROR: Read %d from %d values from file.\n", success, arraySize);

    for (i = 0; i < arraySize; i++)
    {
        insertElement(i, (int)array[i],  &head);
    }

    fclose(fp);

    return head;
}

void testTimeRandom(node **timeList)
{
    int arraySize = RANDOMNUMBERS, upperBound = 100, lowerBound = 1;
    int* array = getRandomIntArray(arraySize, upperBound, lowerBound);
    int i, timeStart, timeEnd, userInput, timeDuration;

    ///Display the array
    for (i = 0; i < arraySize; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n\n");

    ///User Input
    for (i = 0; i < arraySize; i++)
    {
        timeStart = clock();
        getInput(&userInput);
        timeEnd = clock();

        timeDuration = timeEnd - timeStart;

        if (userInput != array[i])
        {
            printf("You failed.\n");
            return;
        }
        else
        {
            printf("_/\n");
        }

        insertSortedElement(timeDuration, timeList);
    }
}

int* getRandomIntArray(unsigned int size, unsigned upperBound, int lowerBound)
{
    if (upperBound < lowerBound)
        fprintf(stderr, "WARNING: upperBound must be larger than lowerBound. (getRandomIntArray)\n");

    int* array = (int *)malloc(sizeof(int) * size);

    srand(time(NULL));

    int i;

    for (i = 0; i < size; i++)
    {
        array[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
    }

    return array;
}

void insertSortedElement(int data, node **head)
{
    node *current = *head;
    int i = 0;

    /// List is empty
    if (current == NULL)
    {
        pushElement(data, head);
        return;
    }

    /// Node is the smallest
    if (data <= current->data)
    {
        pushElement(data, head);
        return;
    }

    if (current->next == NULL)
    {
        if (current->data <= data)
            appendElement(data, head);
        else
            pushElement(data, head);
        return;
    }

    while (current->next != NULL)
    {
        if (current->data <= data)
        {
            current = current->next;
            i++;
        }
        else
        {
            break;
        }

    }

    insertElement(i, data, head);
}

void pushElement(int data, node **head)
{
    node *newNode;

    if ((newNode = (node *)malloc(sizeof(node))) == NULL)
    {
        printf("ERROR: Not enough memory available!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void appendElement(int data, node **head)
{
    node *current = *head;

    ///if list is empty push new node to front
    if (current == NULL)
    {
        pushElement(data, head);
        return;
    }

    ///Loops over each Node until it reaches the last one
    while (current->next != NULL)
    {
        current = current->next;
    }

    ///Creates new List Node
    if ((current->next = (node *)malloc(sizeof(node))) == NULL)
    {
        printf("ERROR: Not enough memory available!\n");
        exit(EXIT_FAILURE);
    }

    current->next->data = data;
    current->next->next = NULL;
}

void insertElement(unsigned int index, int data, node **head)
{
    node *current = *head;
    node *temp;
    int i = 0;

    ///if list is empty push new node to front
    if (current == NULL || index == 0)
    {
        pushElement(data, head);
        return;
    }

    ///Loops over each Node until it reaches the last one
    while (current->next != NULL || i == index - 1)
    {
        if (i == index - 1)
            break;

        current = current->next;
        i++;
    }

    temp = current->next;

    ///Creates new List Node
    if ((current->next = (node *)malloc(sizeof(node))) == NULL)
    {
        printf("ERROR: Not enough memory available!\n");
        exit(EXIT_FAILURE);
    }

    current->next->data = data;
    current->next->next = temp;
}

void deleteFirstElement(node **head)
{
    if (head == NULL)
        return;

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int deleteElement(unsigned int index, node **head)
{
    if (index == 0)
    {
        deleteFirstElement(head);
        return;
    }

    int i = 0;

    node *current = *head;

    while (current != NULL && i < (index - 1))
    {
        current = current->next;
        i++;
    }

    node *temp = current->next;

    current->next = (current->next)->next;

    free(temp);
}

void cleanList(node **head)
{
    node *current = *head;


    int i = 0;

    while (current != NULL)
    {
        if (current->data == -1)
        {
            current = current->next;
            deleteElement(i, head);
        }
        else
        {
            current = current->next;
            i++;
        }

    }
}

void printNodes(node **head)
{
    node *current = *head;

    while (current != NULL)
    {
        printf("Time: %d \n", current->data);
        current = current->next;
    }
}

int getInput(int *returnVal)
{
    char value[100];
    char *eptr;

    fflush(stdin);

    fgets(value, sizeof(value), stdin);
    value[strcspn(value, "\n")] = 0;

    int valueInt = strtol(value, &eptr, 10);
    *returnVal = valueInt;

    return EXIT_SUCCESS;
}

int getListLength(node **head)
{
    node *current = *head;
    int i = 0;

    while (current != NULL)
    {
        i++;
        current = current->next;
    }

    return i;
}

int getLongs(char string[], long output[])
{
    char *eptr = string;
    int i = 0;

    while (*eptr)
    {
        if(isdigit(*eptr) || ((*eptr == '-') && isdigit(*(eptr+1))))
        {
           output[i] = strtol(eptr, &eptr, 10);
           i++;
        }
        else
        {
            eptr++;
        }
    }

    return i;
}

int getLineCount(char filename[])
{
    int count = 0;
    char line[10000];

    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        count++;
    }

    fclose(fp);

    return count;
}


