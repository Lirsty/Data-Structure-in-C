#ifndef _LINKEDLIST_H

#include <stddef.h>
#define _LINKEDLIST_H

#define SUCCESS 0
#define ERROR (-1)

typedef struct node_st {
    void *element;
    struct node_st *next;
} Node;

typedef struct _linkedlist LinkedList;
typedef int (*compare_fn_t)(const void *a, const void *b) ;

LinkedList *linkedlist_new(void);
void linkedlist_free(LinkedList *list);
size_t getLinkedlistSize(LinkedList *list);
int addHead(LinkedList *list, void *element);
int addTail(LinkedList *list, void *element);
Node *getHead(LinkedList *list);
Node *getTail(LinkedList *list);
void deleteNode(LinkedList *list, Node *target);
Node *getNode(LinkedList *list, void *element, compare_fn_t compare);
void *getNodeelement(Node *node);

#endif /* _LINKEDLIST_H */
