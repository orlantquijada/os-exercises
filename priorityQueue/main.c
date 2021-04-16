#include <stdio.h>
#include "PriorityQueue.h"

int main()
{

    PriorityQueue q = newPriorityQueue();
    printf("is full?: %s\n", isFull(q) ? "yes" : "no");
    printf("is empty?: %s\n", isEmpty(q) ? "yes" : "no");

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 8);
    enqueue(q, 7);
    enqueue(q, 9);
    enqueue(q, 10);
    display(q);

    dequeue(q);
    display(q);

    dequeue(q);
    display(q);

    dequeue(q);
    display(q);

    dequeue(q);
    display(q);

    dequeue(q);
    display(q);

    dequeue(q);
    display(q);

    printf("is full?: %s\n", isFull(q) ? "yes" : "no");
    printf("is empty?: %s\n", isEmpty(q) ? "yes" : "no");
    clear(q);
    printf("after calling clear()\n");
    printf("is full?: %s\n", isFull(q) ? "yes" : "no");
    printf("is empty?: %s\n", isEmpty(q) ? "yes" : "no");

    destroy(&q);

    return 0;
}