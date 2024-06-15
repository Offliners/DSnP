#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void initialize(queue *q, int maxsize)
{
    q->front = -1;
    q->maxsize = maxsize;

    q->queue_front = (node*)malloc(sizeof(node));
    q->queue_front->next = NULL;
}

void push(queue *q, int n)
{
    if(q->front + 1 < q->maxsize)
    {
        q->front += 1;
        node *head = (node*)malloc(sizeof(node));
        head->val = n;
        head->next = NULL;
        
        node *cur = q->queue_front;
        while(cur->next)
        {
            cur = cur->next;
        }
        cur->next = head;
    }
    else
        printf("Full\n");
}

void pop(queue *q)
{
    if(q->front != -1)
    {
        q->queue_front = q->queue_front->next;
        q->front -= 1; 
    }
    else
        printf("Empty\n");
}

void front(queue *q)
{
    if(q->front != -1)
        printf("%d", q->queue_front->val);
    printf("\n");
}

void display(queue *q)
{
    if(q->front != -1)
    {
        int *data = (int*)malloc((q->front + 1) * sizeof(int));
        for(int i = 0; i <= q->front; ++i)
            data[i] = 0;
        
        int index = 0;
        node *cur = q->queue_front->next;
        while(cur)
        {
            data[index] = cur->val;
            cur = cur->next;
            ++index;
        }

        for(int i = 0; i <= q->front; ++i)
            printf("%d ", data[i]);
        
        free(data);
    }
    
    printf("\n");
}

void check(queue *q)
{
    int len = 0;
    node *cur = q->queue_front;
    while(cur->next)
    {
        ++len;
        cur = cur->next;
    }
    printf("%d\n", len);
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
    node *temp;
    while(q->queue_front)
    {
        temp = q->queue_front;
        q->queue_front = q->queue_front->next;
        free(temp);
    }
    free(q);
}