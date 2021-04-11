#include <stdio.h>
#include "queue.h"

int main()
{
    Queue queue = newQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    display(queue);

    enqueue(queue, 3);
    display(queue);

    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    display(queue);

    printf("head: %d\n", head(queue));
    printf("tail: %d\n", tail(queue));

    dequeue(queue);
    display(queue);
    printf("head: %d\n", head(queue));
    printf("tail: %d\n", tail(queue));

    printf("is queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");
    printf("is queue full? %s\n", isFull(queue) ? "Yes" : "No");

    clear(queue);
    printf("after clear\n");
    printf("is queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    display(queue);

    destroy(&queue);

    return 0;
}
