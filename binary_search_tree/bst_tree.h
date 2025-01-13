#ifndef _BST_TREE_H_

typedef struct node_st {
    const void *element;
    struct node_st *left, *right;
} Node;

typedef int (*compare_fn_t)(const void *, const void *);

typedef struct binary_search_tree_st
{
    Node *root;
    compare_fn_t cmp;
} BST;

BST *BST_new(compare_fn_t cmp);
int BST_insert(BST *bst, const void *element);
int BST_delete(BST *bst, const void *element);

#endif /* _BST_TREE_H_ */