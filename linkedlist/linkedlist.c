#include "linkedlist.h"
#include <stddef.h>
#include <stdlib.h>
typedef struct _linkedlist {
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

LinkedList *
linkedlist_new(void)
{
    LinkedList *ret = malloc(sizeof(LinkedList));
    if (ret == NULL)
        return NULL;
    ret->head = NULL;
    ret->tail = NULL;
    ret->size = 0;
    return ret;
}

void
linkedlist_free(LinkedList *list)
{
    Node *p = list->head;
    Node *tmp;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    free(list);
}

size_t
getLinkedlistSize(LinkedList *list)
{
    return list->size;
}

int
addHead(LinkedList *list, void *element)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
        return ERROR;

    node->element = element;
    if (list->head == NULL)
        list->tail = node;
    else
        node->next = list->head;
    list->head = node;    

    list->size += 1;
    return SUCCESS;
}

int
addTail(LinkedList *list, void *element)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
        return ERROR;

    node->element = element;
    if (list->tail == NULL)
        list->head = node;
    else
        list->tail->next = node;
    list->tail = node; 

    list->size += 1;
    return SUCCESS;
}

Node *
getHead(LinkedList *list)
{
    return list->head;
}

Node *
getTail(LinkedList *list)
{
    return list->tail;
}

void
deleteNode(LinkedList *list, Node *target)
{
    if (target == list->head)
    {
        if (list->head->next == NULL)
            list->head = list->tail = NULL;
        else
            list->head = list->head->next;
    } 
    else 
    {
        Node *tmp = list->head;
        while(tmp != NULL && tmp->next != target)
            tmp = tmp->next;
        if (tmp == NULL)
    return;
        tmp->next = target->next;
        if (target == list->tail)
            list->tail = tmp;
    }  
    free(target);
    list->size -= 1;
} 

Node *
getNode(LinkedList *list, void *element, compare_fn_t compare)
{
    Node *p = list->head;
    while (p != NULL)
    {
        if (compare(p->element, element) == 0)
    return p;
        p = p->next;
    }
    return NULL;
}

void *
getNodeData(Node *node)
{
    if (node == NULL)
        return NULL;
    return node->element;
}


