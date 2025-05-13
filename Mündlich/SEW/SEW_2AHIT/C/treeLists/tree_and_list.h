#ifndef TREE_AND_LIST_H_INCLUDED
#define TREE_AND_LIST_H_INCLUDED

typedef struct list_t
{
    int data;

    struct list_t *next;
} list_t;

typedef struct tree_t
{
    int data;

    struct tree_t *left;
    struct tree_t *right;
} tree_t;

void push(int data, list_t **head);
void append(int data, list_t **head);
void deleteFirst(list_t **head);
void deleteElement(unsigned int index, list_t **head);
void printList(list_t *head);
void appendTree(int data, tree_t **root);
void printTree(tree_t *root);
int treeNodes(tree_t *root);

#endif // TREE_AND_LIST_H_INCLUDED
