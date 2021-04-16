#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#define MAX 10

typedef int queueItem;
typedef struct priorityQueue *PriorityQueue;

struct priorityQueue
{
    queueItem *items;
    int count;
};

PriorityQueue newPriorityQueue();
void destroy(PriorityQueue *q);
void display(const PriorityQueue q);

void enqueue(PriorityQueue q, const queueItem item);
void dequeue(PriorityQueue q);
void clear(PriorityQueue q);

int isEmpty(const PriorityQueue q);
int isFull(const PriorityQueue q);

queueItem head(const PriorityQueue q);
queueItem tail(const PriorityQueue q);

#endif