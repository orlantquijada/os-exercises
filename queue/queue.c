#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

nodeptr createNode(queueItem item)
{
    nodeptr pointer = (nodeptr)malloc(sizeof(struct node));
    pointer->item = item;
    pointer->next = NULL;

    return pointer;
}

Queue newQueue()
{
    Queue queue = (Queue)malloc(sizeof(struct queue));
    queue->head = queue->tail = NULL;
    queue->count = 0;

    return queue;
}
void destroy(Queue *q)
{
    clear(*q);
    free(*q);
    *q = NULL;
}

void enqueue(Queue q, queueItem item)
{
    if (q->count < MAX)
    {
        nodeptr newItem = createNode(item);

        if (q->head == NULL)
            q->head = q->tail = newItem;
        else
        {
            q->tail->next = newItem;
            q->tail = newItem;
        }
        q->count++;
    }
}
void dequeue(Queue q)
{
    nodeptr temp = q->head;

    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;

    free(temp);

    q->count--;
}
void clear(Queue q)
{
    while (q->count)
        dequeue(q);
}
int isEmpty(const Queue q) { return q->count ? 0 : 1; }
int isFull(const Queue q) { return q->count == MAX; }
queueItem head(const Queue q) { return q->head->item; }
queueItem tail(const Queue q) { return q->tail->item; }
void display(const Queue q)
{
    nodeptr p = q->head;
    printf("[ ");
    int i = 0;
    while (i < q->count)
    {
        printf("%d ", p->item);

        p = p->next;
        i++;
    }
    printf("]\n");
}