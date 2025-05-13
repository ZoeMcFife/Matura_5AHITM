#include <stdio.h>
#include <stdlib.h>
#include "tree_and_list.h"

void push(int data, list_t **head)
{
    list_t *newNode;

    if ( (newNode = (list_t *)malloc(sizeof(list_t))) == NULL )
    {
        fprintf(stderr, "error\n");
        return;
    }

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void append(int data, list_t **head)
{
    if (*head == NULL)
    {
        push(data, head);
        return;
    }

    list_t *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    if ( (current->next = (list_t *)malloc(sizeof(list_t))) == NULL )
    {
        fprintf(stderr, "error\n");
        return;
    }

    current->next->data = data;
    current->next->next = NULL;
}

void deleteFirst(list_t **head)
{
    if (*head == NULL) return;

    list_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteElement(unsigned int index, list_t **head)
{
    if (*head == NULL) return;

    if (index == 1)
    {
        deleteFirst(head);
        return;
    }

    list_t *current = *head;
    int i = 0;

    while (current != NULL && i < (index - 1))
    {
        current = current->next;
        i++;
    }

    list_t *temp = current->next;
    current->next = (current->next)->next;
    free(temp);
}

void printList(list_t *head)
{
    if (head == NULL) return;

    list_t *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void appendTree(int data, tree_t **root)
{
    tree_t *newNode;

    if (*root == NULL)
    {
        if ( (newNode = (tree_t *)malloc(sizeof(tree_t))) == NULL )
        {
            fprintf(stderr, "error\n");
            return;
        }

        newNode->data  = data;
        newNode->left  = NULL;
        newNode->right = NULL;

        *root = newNode;

        return;
    }

    data > (*root)->data ? appendTree(data, &((*root)->right)) : appendTree(data, &((*root)->left));
}

void printTree(tree_t *root)
{
    if (root == NULL) return;

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int treeNodes(tree_t *root)
{
    if (root == NULL) return 0;

    return 1 + treeNodes(root->left) + treeNodes(root->right);
}
