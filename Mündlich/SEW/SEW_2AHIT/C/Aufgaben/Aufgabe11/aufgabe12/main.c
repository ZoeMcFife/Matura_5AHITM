#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

void pushElement(int number, node **head);
void pushToLast(int number, node **head); /// I'm still figuring out the correct the terminology, so function names are still a bit rough
void printNodes(node **head);

void userLoop(bool pushFirst);
int getInput(int *returnVal);

int main()
{
    userLoop(true);
    return EXIT_SUCCESS;
}

void userLoop(bool pushFirst)
{
    int value;
    node *head = NULL;
    head = (node *)malloc(sizeof(node));

    if (head == NULL)
        return;

    head->next = NULL;
    head->number = 0;

    while (getInput(&value) != -2)
    {
        if (pushFirst)
            pushElement(value, head);
        else
            pushToLast(value, head);
    }

    printNodes(head);
}

int getInput(int *returnVal)
{
    char value[100];
    char *eptr;

    fflush(stdin);

    printf("Enter Value: ");
    fgets(value, sizeof(value), stdin);
    value[strcspn(value, "\n")] = 0;

    if (strcmp(value, "end") == 0)
        return -2;
    else
    {
        int valueInt = strtol(value, &eptr, 10);
        if (*eptr != 0)
            return EXIT_FAILURE;
        else
            *returnVal = valueInt;
    }
    return EXIT_SUCCESS;
}

void pushElement(int number, node **head)
{
    node *newNode;

    newNode = (node *)malloc(sizeof(node));

    newNode->number = number;
    newNode->next = *head;
    *head = newNode;
}

void pushToLast(int number, node **head)
{
    node *current = *head;

    ///Loops over each Node until it reaches the last one
    while (current->next != NULL)
        current = current->next;

    ///Creates new List Node
    current->next = (node *)malloc(sizeof(node));
    current->next->number = number;
    current->next->next = NULL;
}

void printNodes(node **head)
{
    node *current = *head;

    while (current->next != NULL)
    {
        printf("Value of current node: %d\n", current->number);
        current = current->next;
    }
}
