#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void dataOutputRecursive(node *head )
{
    if (head != NULL)
    {
        printf("%d\n", head->data);
        dataOutputRecursive(head->next);
    }
}

void pushElement(int data, node **head);
void appendElement(int data, node **head);
void insertElement(unsigned int index, int data, node **head);
void insertSortedElement(int data, node **head);
int deleteElement(unsigned int index, node **head);
void deleteFirstElement(node **head);

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

int countRecursive(node *head)
{
    int counter;

    if (head == NULL)
    {
        return 0;
    }
    counter = countRecursive(head->next);
    counter++;

    return counter;
}


int main()
{
    node *head = NULL;
    /*head = (node *)malloc(sizeof(node));
    head->next = NULL;
    head->data = -1;*/

    pushElement(1, &head);
    pushElement(1, &head);

    dataOutputRecursive(head);


    //dataOutput(&listBegin);
    //int data;
    //deleteFirstElement(&data, &listBegin);
    //dataOutput(&listBegin);
    return 0;
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


