#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

int main()
{
    Stack s = newStack();

    push(s, 5);
    push(s, 4);
    push(s, 3);
    push(s, 2);
    push(s, 1);
    printf("Elements in stack: ");
    display(s);

    printf("top: %d\n", top(s));

    printf("Push (element): 6\n");
    push(s, 6);
    printf("Elements in stack: ");
    display(s);

    pop(s);
    printf("After pop():\n");
    printf("Elements in stack: ");
    display(s);

    pop(s);
    printf("After pop():\n");
    printf("Elements in stack: ");
    display(s);

    printf("isEmpty: %s\n", isEmpty(s) ? "Yes" : "No");

    clear(s);
    printf("After clear():\n");
    printf("isEmpty: %s\n", isEmpty(s) ? "Yes" : "No");
    printf("Elements in stack: ");
    display(s);

    destroy(&s);

    return 0;
}