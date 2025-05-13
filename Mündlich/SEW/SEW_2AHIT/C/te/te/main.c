#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void pushElement(int data, node **head);
void appendElement(int data, node **head);
void deleteFirstElement(node **head);
void out(node *head);
void deleteElement(unsigned int index, node **head);
void insertElement(unsigned int index, node **head);

void out2(node *head)
{
    printf("a");
    if (head != NULL)
    {
        printf("%d ", head->data);

        if (head->next != NULL)
        {
            head = head->next;
        }

        out2(head);
    }

    printf("b");
}


int main()
{
    node *head = NULL;

    pushElement(3, &head);
    pushElement(5, &head);
    pushElement(4, &head);
    pushElement(2, &head);
    //out(head);
    out2(head);
    //out(head);

    return 0;
}

void pushElement(int data, node **head)
{
    node *newNode;

    if ((newNode = (node *)malloc(sizeof(node))) == NULL)
    {
        fprintf(stderr, "Error\n");
        return;
    }

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;

}

void appendElement(int data, node **head)
{
    node *current = *head;

    if (current == NULL)
    {
        pushElement(data, head);
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    if ((current->next = (node *)malloc(sizeof(node))) == NULL)
    {
        fprintf(stderr, "Error\n");
        return;
    }

    current->next->data = data;
    current->next->next = NULL;
}

void deleteFirstElement(node **head)
{
    if (*head == NULL) return;

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteElement(unsigned int index, node **head)
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
/*
void insertElement(unsigned int index, node **head)
{
    node *current = *head;
    node *temp;
    int i = 0;

    if (current == NULL)
    {
        pushElement(1, head);
        return;
    }

    while (current->next != NULL || (i == index - 1))
    {
        if (i == index - 1) break;

        current = current->next;
        i++;
    }

    temp = current->next;

    if ((current->next = (node *)malloc(sizeof(node))) == NULL)
    {
        fprintf(stderr, "Error\n");
        return;
    }

    current->next->data = data;
    current->next->next = temp;

}*/

void out(node *head)
{
    node *current = head;

    if (current == NULL) return;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

