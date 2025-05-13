#include <stdio.h>
#include <stdlib.h>

typedef struct TREEELEMENT
{
    int data;
    struct TREEELEMENT* left;
    struct TREEELEMENT* right;
} treeElement_t;

void insertTreeElement(int data, treeElement_t** ptr)
{
    treeElement_t *element;

    if (*ptr == NULL)
    {
        element = (treeElement_t*)malloc(sizeof(treeElement_t));

        if (element == NULL)
        {
            printf("Not enough memory.\n");
            return;
        }

        element->data = data;
        element->left = NULL;
        element->right = NULL;

        *ptr = element;

        return;
    }

    /// links einfügen
    if (data < (*ptr)->data)
        insertTreeElement(data, &((*ptr)->left));
    else
        insertTreeElement(data, &((*ptr)->right));
}

void output(treeElement_t* ptr)
{
    if (ptr == NULL)
        return;

    output(ptr->left);
    printf("- %d ", ptr->data);
    output(ptr->right);
}

int countElements(treeElement_t *ptr)
{
    if (ptr == NULL) return 0;

    return countElements(ptr->left) + 1 + countElements(ptr->right);
}

int countLayers(treeElement_t *ptr)
{
    if (ptr == NULL) return 0;

    int l = countLayers(ptr->left);
    int r = countLayers(ptr->right);

    if (l < r)
        return r + 1;
    else
        return l + 1;
}

int main()
{
    treeElement_t* root = NULL;

    insertTreeElement(34, &root);
    insertTreeElement(41, &root);
    insertTreeElement(45, &root);
    insertTreeElement(42, &root);
    insertTreeElement(27, &root);
    insertTreeElement(24, &root);
    insertTreeElement(33, &root);

    output(root);

    return EXIT_SUCCESS;
}
