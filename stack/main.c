#include <stdio.h>
#include "stack.h"

int main()
{
    Stack stack = newStack();

    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printf("%d ", top(stack));
    display(stack);

    push(stack, 6);
    push(stack, 4);
    push(stack, 6);
    printf("%d ", top(stack));
    display(stack);
    printf("%s\n", isEmpty(stack) ? "empty" : "not empty");

    clear(stack);
    display(stack);
    printf("%s\n", isEmpty(stack) ? "empty" : "not empty");

    push(stack, 4);
    push(stack, 7);
    display(stack);

    pop(stack);
    display(stack);

    destroy(&stack);
    return 0;
}
