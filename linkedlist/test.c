#include <stdio.h>
#include "linkedlist.h"

int cmp_fn(const void *a, const void *b)
{
    if (a == NULL)
        return -1;
    if (b == NULL)
        return 1;
    return (*(int *)a - *(int *)b);
}

void print_list(LinkedList *list)
{
    Node *p = getHead(list);
    while(p)
    {
        printf("%d ", *(int *)p->element);
        p = p->next;
    }
    putchar('\n');
}

int main()
{
    LinkedList *list = linkedlist_new();

    #define LEN 100
    int data_arr[LEN];
    for (int i=0; i<LEN; ++i)
    {
        data_arr[i] = i;
        addHead(list, data_arr + i);
    }

    print_list(list);

    for (int i=0; i<LEN; i+=2)
        deleteNode(list, getNode(list, data_arr+i, cmp_fn));

    print_list(list);

    linkedlist_free(list);

    return 0;
}