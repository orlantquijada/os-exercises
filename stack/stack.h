#ifndef STACK_H

#define STACK_H

typedef int stackItem;
typedef struct node *nodeptr;
typedef struct stack *Stack;

struct node
{
    stackItem item;
    nodeptr next;
};

struct stack
{
    nodeptr items;
    int count;
};

// push, pop, isEmpty, clear, top
Stack newStack();
void destroy(Stack *s);
void push(Stack s, stackItem item);
void pop(Stack s);
void clear(Stack s);
void display(const Stack s);
int isEmpty(const Stack s);
stackItem top(const Stack s);

#endif