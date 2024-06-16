#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initialize(queue *q, int maxsize)
{
    q->front = -1;
    q->maxsize = maxsize;
    q->data = (int*)malloc(maxsize * sizeof(int));
    for(int i = 0; i < maxsize; ++i)
        q->data[i] = 0;
}

void push(queue *q, int n)
{
    if(q->front + 1 < q->maxsize)
    {
        q->front += 1;
        for(int i = q->front; i > 0; --i)
            q->data[i] = q->data[i - 1];

        q->data[0] = n;
    }
    else
        printf("Full\n");
}

void pop(queue *q)
{
    if(q->front != -1)
    {
        q->data[q->front] = 0;
        q->front -= 1; 
    }
    else
        printf("Empty\n");
}

void front(queue *q)
{
    if(q->front != -1)
        printf("%d", q->data[q->front]);
    printf("\n");
}

void display(queue *q)
{
    if(q->front != -1)
        for(int i = 0; i <= q->front; ++i)
            printf("%d ", q->data[i]);
    printf("\n");
}

void check(queue *q)
{
    printf("%d\n", q->front + 1);
}

void empty(queue *q)
{
    if(q->front == -1)
        printf("True\n");
    else
        printf("False\n");
}

void full(queue *q)
{
    if(q->front + 1 >= q->maxsize)
        printf("True\n");
    else
        printf("False\n");
}

void free_queue(queue *q)
{
    free(q->data);
    free(q);
}