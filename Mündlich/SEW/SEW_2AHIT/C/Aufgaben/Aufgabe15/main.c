#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct node
{
    int value;

    struct node* left;
    struct node* right;
} TreeNode_t;

void insertTreeElement(int data, TreeNode_t** root);
void outputTreeAscending(TreeNode_t* root);
void outputTreeDescending(TreeNode_t* root);

TreeNode_t* createRandomTree(unsigned int totalNodes, int minNodeSize, int maxNodeSize);
unsigned int nodeCount(TreeNode_t* root);
unsigned int treeDepth(TreeNode_t* root);
unsigned int minTreeDepth(unsigned int nodeCount);

int main()
{
    srand(time(NULL));

    TreeNode_t* root = createRandomTree(rand() % 1000, 1, rand() % 1000);

    int nodes = nodeCount(root);
    int depth = treeDepth(root);
    int minDepth = minTreeDepth(nodes);

    printf("Nodes: %d\nDepth: %d\nMinimal Depth: %d\n", nodes, depth, minDepth);

    minDepth == depth ? printf("Tree has optimum depth.\n") : minDepth < depth ? printf("Tree has a larger than minimum depth.\n") : printf("Tree has a smaller than minimum depth? Yeah something went wrong.\n");

    printf("\n\t\t\t\t\t--------Ascending--------\n\n");
    outputTreeAscending(root);
    printf("\n\n\t\t\t\t\t--------Descending-------\n\n");
    outputTreeDescending(root);
    printf("\n");

    return EXIT_SUCCESS;
}

unsigned int minTreeDepth(unsigned int nodeCount)
{
    return log2(nodeCount) + 1;
}

unsigned int treeDepth(TreeNode_t* root)
{
    if (root == NULL) return 0;

    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    if (leftDepth > rightDepth) return leftDepth + 1;

    return rightDepth + 1;
}

unsigned int nodeCount(TreeNode_t* root)
{
    if (root == NULL) return 0;

    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

TreeNode_t* createRandomTree(unsigned int totalNodes, int minNodeSize, int maxNodeSize)
{
    TreeNode_t* tree = NULL;

    int i;

    for (i = 0; i < totalNodes; i++)
        insertTreeElement((rand() % (maxNodeSize - minNodeSize) + minNodeSize), &tree);

    printf("Created new tree with %d nodes with values between %d and %d.\n", totalNodes, minNodeSize, maxNodeSize);

    return tree;
}

void outputTreeAscending(TreeNode_t* root)
{
    if (root == NULL) return;

    outputTreeAscending(root->left);
    printf("%3d|", root->value);
    outputTreeAscending(root->right);
}

void outputTreeDescending(TreeNode_t* root)
{
    if (root == NULL) return;

    outputTreeDescending(root->right);
    printf("%3d|", root->value);
    outputTreeDescending(root->left);
}

void insertTreeElement(int data, TreeNode_t** root)
{
    TreeNode_t* newNode;

    if (*root == NULL)
    {
        newNode = (TreeNode_t *)malloc(sizeof(TreeNode_t));

        newNode->value = data;
        newNode->left = NULL;
        newNode->right = NULL;

        *root = newNode;

        return;
    }

    data < (*root)->value ? insertTreeElement(data, &((*root)->left)) : insertTreeElement(data, &((*root)->right));
}
