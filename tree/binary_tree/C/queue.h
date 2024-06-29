#ifndef _QUEUE_H
#define _QUEUE_H

#include "binarytree.h"

typedef struct QUEUENODE {
    struct TREENODE *cur;
    struct QUEUENODE *next;
} QueueNode;

typedef struct QUEUE {
    int front;
    QueueNode* queue_front;
} Queue;

void initialize_queue(Queue*);
void queue_push(Queue*, TreeNode*);
void queue_pop(Queue*);
TreeNode* queue_get_front(Queue*);
int queue_empty(Queue*);
void free_queue(Queue*);

#endif