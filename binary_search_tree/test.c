#include "bst_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_inorder(Node *root)
{
    if (root != NULL)
    {
        print_inorder(root->left);
        printf("%d ", *(int *)root->element);
        print_inorder(root->right);
    }
}

int cmp_fn(const void *a, const void *b)
{
    if (a == NULL)
        return -1;
    if (b == NULL)
        return 1;
    return *(int *)a - *(int *)b;
}

int main()
{
    BST *bst = BST_new(cmp_fn);

    #define LEN 100
    int data_arr[LEN];

    srand(time(NULL));
    for (int i=0; i<LEN; ++i)
    {
        data_arr[i] = rand() % 1000;
        BST_insert(bst, data_arr + i);
    }

    print_inorder(bst->root); putchar('\n');

    for (int i=0; i<LEN; i+=3)
    {
        BST_delete(bst, data_arr + i);
    }

    print_inorder(bst->root);

    return 0;
}