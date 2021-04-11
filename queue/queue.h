#ifndef QUEUE_H

#define QUEUE_H
#define MAX 10

typedef int queueItem;
typedef struct node *nodeptr;
typedef struct queue *Queue;

struct node
{
    queueItem item;
    nodeptr next;
};

struct queue
{
    int count;
    nodeptr head;
    nodeptr tail;
};

// enqueue, dequeue, isEmpty, clear, head, tail, isFull
Queue newQueue();
void destroy(Queue *q);
void enqueue(Queue q, queueItem item);
void dequeue(Queue q);
void clear(Queue q);
void display(const Queue q);
int isEmpty(const Queue q);
int isFull(const Queue q);
queueItem head(const Queue q);
queueItem tail(const Queue q);

#endif