#ifndef _STACK_H

#define _STACK_H
#include <stddef.h>

typedef struct _stack Stack;
Stack *stack_new(void);
void stack_free(Stack *stack);
size_t getStackSize(Stack *stack);
int push(Stack *stack, void *data);
void *pop(Stack *stack);

#endif /* _STACK_H */
