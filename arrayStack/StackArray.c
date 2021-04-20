#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

void ensureSize(Stack s)
{
    if (sizeof(stackItem) * s->count >= s->size)
    {
        s->size *= 2;
        stackItem *t = (stackItem *)malloc(s->size);
        for (int i = 0; i < s->count; i++)
            t[i] = s->items[i];

        free(s->items);
        s->items = t;
    }
}

Stack newStack()
{
    Stack s = (Stack)malloc(sizeof(struct stack));
    s->size = sizeof(stackItem);
    s->items = (stackItem *)malloc(s->size);
    s->count = 0;
    return s;
}
void destroy(Stack *s)
{
    free((*s)->items);
    free(*s);
    *s = NULL;
}
void push(Stack s, stackItem item)
{
    ensureSize(s);
    s->items[s->count] = item;
    s->count++;
}
void pop(Stack s)
{
    if (s->count)
    {
        s->items[s->count - 1] = 0;
        s->count--;
    }
}
void clear(Stack s)
{
    free(s->items);
    s->items = (stackItem *)malloc(s->size);
    s->count = 0;
}
void display(const Stack s)
{
    printf("{ ");
    for (int i = s->count - 1; i >= 0; i--)
        printf("%d ", s->items[i]);
    printf("}\n");
}
int isEmpty(const Stack s) { return !s->count; }
stackItem top(const Stack s) { return s->items[s->count - 1]; }
