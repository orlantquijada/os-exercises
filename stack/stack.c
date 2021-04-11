#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

nodeptr createNode(stackItem item)
{
    nodeptr pointer = (nodeptr)malloc(sizeof(struct node));
    pointer->item = item;
    pointer->next = NULL;

    return pointer;
}

Stack newStack()
{
    Stack stack = (Stack)malloc(sizeof(struct stack));
    stack->items = NULL;
    stack->count = 0;

    return stack;
}
void destroy(Stack *s)
{
    clear(*s);
    free(*s);
    *s = NULL;
}
void push(Stack s, stackItem item)
{
    nodeptr newItem = createNode(item);

    newItem->next = s->items;
    s->items = newItem;

    s->count++;
}
void pop(Stack s)
{
    nodeptr firstNode = s->items;

    s->items = firstNode->next;
    firstNode->next = NULL;
    free(firstNode);
    firstNode = NULL;

    s->count--;
}
void clear(Stack s)
{
    while (s->count)
        pop(s);
}
int isEmpty(const Stack s) { return s->count ? 0 : 1; }
stackItem top(const Stack s) { return s->items->item; }
void display(const Stack s)
{
    nodeptr p = s->items;
    printf("[ ");
    int i = 0;
    while (i < s->count)
    {
        printf("%d ", p->item);

        p = p->next;
        i++;
    }
    printf("]\n");
}