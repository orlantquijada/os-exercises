#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

int getParentIndex(const int childIndex) { return (childIndex - 1) / 2; }
int getLeftChildIndex(const int parentIndex) { return parentIndex * 2 + 1; }
int getRightChildIndex(const int parentIndex) { return parentIndex * 2 + 2; }

int hasLeftChild(const PriorityQueue q, const int parentIndex) { return getLeftChildIndex(parentIndex) < q->count; }
int hasRightChild(const PriorityQueue q, const int parentIndex) { return getRightChildIndex(parentIndex) < q->count; }
int hasParent(const PriorityQueue q, const int childIndex) { return getParentIndex(childIndex) >= 0; }

int getLeftChild(const PriorityQueue q, const int parentIndex) { return q->items[getLeftChildIndex(parentIndex)]; }
int getRightChild(const PriorityQueue q, const int parentIndex) { return q->items[getRightChildIndex(parentIndex)]; }
int getParent(const PriorityQueue q, const int childIndex) { return q->items[getParentIndex(childIndex)]; }

void swapElements(const PriorityQueue q, const int index1, const int index2)
{
    queueItem temp = q->items[index1];
    q->items[index1] = q->items[index2];
    q->items[index2] = temp;
}

PriorityQueue newPriorityQueue()
{
    PriorityQueue q = (PriorityQueue)malloc(sizeof(struct priorityQueue));
    q->items = (queueItem *)malloc(sizeof(queueItem) * MAX);
    q->count = 0;

    return q;
}
void destroy(PriorityQueue *q)
{
    clear(*q);
    free((*q)->items);
    (*q)->items = NULL;
    free(*q);
    *q = NULL;
}
void display(const PriorityQueue q)
{
    printf("[ ");
    for (int i = 0; i < q->count; i++)
        printf("%d ", q->items[i]);
    printf("]\n");
}

void enqueue(PriorityQueue q, const queueItem item)
{
    if (q->count == MAX)
        return;

    q->items[q->count] = item;
    q->count++;

    int index = q->count - 1;
    while (hasParent(q, index) && getParent(q, index) < q->items[index])
    {
        swapElements(q, getParentIndex(index), index);

        index = getParentIndex(index);
    }
}
void dequeue(PriorityQueue q)
{
    if (!q->count)
        return;

    q->items[0] = q->items[q->count - 1];
    q->count--;

    int index = 0;
    while (hasLeftChild(q, index))
    {
        int largerChildIndex = getLeftChildIndex(index);
        if (hasRightChild(q, index) && getRightChild(q, index) > getLeftChild(q, index))
            largerChildIndex = getRightChildIndex(index);

        if (q->items[index] > q->items[largerChildIndex])
            break;

        swapElements(q, index, largerChildIndex);
        index = largerChildIndex;
    }
}
void clear(PriorityQueue q)
{
    while (q->count)
        dequeue(q);
}

int isEmpty(const PriorityQueue q) { return q->count ? 0 : 1; }
int isFull(const PriorityQueue q) { return q->count == MAX; }

queueItem head(const PriorityQueue q) { return q->items[0]; }
queueItem tail(const PriorityQueue q) { return q->items[q->count - 1]; }