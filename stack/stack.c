#include "linkedlist.h"
#include <stddef.h>

typedef LinkedList Stack;

Stack *
stack_new(void)
{
    return linkedlist_new();
}

void
stack_free(Stack *stack)
{
    linkedlist_free(stack);
}

size_t
getStackSize(Stack *stack)
{
    return getLinkedlistSize(stack);
}

int
push(Stack *stack, void *element)
{
    return addHead(stack, element);
}

void *
pop(Stack *stack)
{
    Node* head = getHead(stack);
    void *ret = getNodeData(head);
    deleteNode(stack, head);
    return ret;
}

