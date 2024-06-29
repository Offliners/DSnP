#include <stdlib.h>
#include "binarytree.h"
#include "queue.h"

void initialize_queue(Queue *q)
{
    q->front = -1;
    q->queue_front = (QueueNode*)malloc(sizeof(QueueNode));
    q->queue_front->cur = NULL;
    q->queue_front->next = NULL;
}

void queue_push(Queue *q, TreeNode *n)
{
    q->front += 1;
    QueueNode *head = (QueueNode*)malloc(sizeof(QueueNode));
    head->cur = n;
    head->next = NULL;
    
    if(q->front == 0)
        q->queue_front = head;
    else
    {
        QueueNode *cur = q->queue_front;
        while(cur->next)
            cur = cur->next;
        
        cur->next = head;
    }
}

void queue_pop(Queue *q)
{
    q->front -= 1;
    q->queue_front = q->queue_front->next;
}

TreeNode* queue_get_front(Queue *q)
{
    return q->queue_front->cur;
}

int queue_empty(Queue *q)
{
    return (q->front == -1) ? 1 : 0;
}

void free_queue(Queue *q)
{
    QueueNode *temp;
    while(q->queue_front)
    {
        temp = q->queue_front;
        q->queue_front = q->queue_front->next;
        free(temp);
    }

    free(q);
}