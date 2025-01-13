#include "bst_tree.h"
#include <stdlib.h>

BST *BST_new(compare_fn_t cmp)
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    bst->cmp = cmp;
    return bst;
}

Node *Node_new(const void *element)
{
    Node *node = malloc(sizeof(Node));
    node->element = element;
    node->left = node->right = NULL;
    return node;
}

static int __recursive_insert(Node **root, const void *element, compare_fn_t cmp)
{
    if (*root == NULL)
    {
        *root = Node_new(element);
        return 1;
    }
    int cmp_ret = cmp(element, (*root)->element);
    if (cmp_ret == 0)
        return -1;
    return (cmp_ret < 0) ?
        __recursive_insert(&(*root)->left,  element, cmp) :
        __recursive_insert(&(*root)->right, element, cmp) ;
}

static int __iterative_insert(Node **root, const void *element, compare_fn_t cmp)
{
    Node **current = root;

    while (*current != NULL)
    {
        int cmp_ret = cmp(element, (*current)->element);
        if (cmp_ret == 0)
            return -1;
        current = (cmp_ret < 0) ?
            &(*current)->left :
            &(*current)->right;
    }

    *current = Node_new(element);
    return 0;
}

int BST_insert(BST *bst, const void *element)
{
    if (bst == NULL)
        return -1;
  //return __recursive_insert(&bst->root, element, bst->cmp);
    return __iterative_insert(&bst->root, element, bst->cmp);
}

static Node *__find_min_ret_parent(Node *root, Node **parent)
{
    if (root == NULL || root->left == NULL)
        return root;
    *parent = root;
    return __find_min_ret_parent(root->left, parent);
}

static int __recursive_delete(Node **root, const void *element, compare_fn_t cmp)
{
    if (*root == NULL)
        return -1;

    int cmp_ret = cmp(element, (*root)->element);

    if (cmp_ret == 0)
    {
        Node *to_del = *root;
        if (to_del->left && to_del->right)
        {
            Node *r_min_parent = NULL;
            Node *r_min = __find_min_ret_parent(to_del->right, &r_min_parent);
  
            r_min->left = to_del->left;
            if (r_min_parent != NULL) // if (r_min != to_del->right)
            {
                r_min_parent->left = NULL;
                r_min->right = to_del->right;
            }

            (*root) = r_min;
        }
        else *root = (Node *)((uintptr_t)to_del->left | (uintptr_t)to_del->right);

        free(to_del);
        return 1;
    }
        
    return (cmp_ret < 0) ?
        __recursive_delete(&(*root)->left,  element, cmp) :
        __recursive_delete(&(*root)->right, element, cmp) ;
}

static int __iterative_delete(Node **root, const void *element, compare_fn_t cmp)
{
    while (*root != NULL)
    {
        int cmp_ret = cmp(element, (*root)->element);
        if (cmp_ret == 0)
            break;
        root = (cmp_ret < 0) ?
            &(*root)->left :
            &(*root)->right;
    }

    if (*root == NULL)
        return -1;

    Node *to_del = *root;
    if (to_del->left && to_del->right)
    {
        Node *r_min_parent = NULL;
        Node *r_min = __find_min_ret_parent(to_del->right, &r_min_parent);

        r_min->left = to_del->left;
        if (r_min_parent != NULL) // if (r_min != to_del->right)
        {
            r_min_parent->left = NULL;
            r_min->right = to_del->right;
        }

        (*root) = r_min;
    }
    else *root = (Node *)((uintptr_t)to_del->left | (uintptr_t)to_del->right);

    free(to_del);
    return 1;
}

int BST_delete(BST *bst, const void *element)
{
    if (bst == NULL)
        return -1;
  //return __recursive_delete(&bst->root, element, bst->cmp);
    return __iterative_delete(&bst->root, element, bst->cmp); 
}
