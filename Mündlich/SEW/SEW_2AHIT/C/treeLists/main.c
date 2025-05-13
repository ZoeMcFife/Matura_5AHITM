#include <stdio.h>
#include <stdlib.h>
#include "tree_and_list.h"

void searchTree(tree_t *root, int search)
{
    if (root == NULL) return;

    searchTree(root->left, search);

    if (root->data == search)
    {
        printf("%d found.\n", search);
    }

    searchTree(root->right, search);

}

int main()
{
    list_t *list = NULL;
    tree_t *tree = NULL;
/*
    append(1, &list);
    append(2, &list);
    append(3, &list);
    append(6, &list);
    append(23, &list);
    append(2, &list);

    deleteElement(3, &list);

    printf("List: ");
    printList(list);
*/
    appendTree(1, &tree);
    appendTree(24, &tree);
    appendTree(12, &tree);
    appendTree(24, &tree);


    printf("Tree: ");
    printTree(tree);
   // searchTree(tree, 12);

//    printf("owo %d", treeNodes(tree));


    return EXIT_SUCCESS;
}
