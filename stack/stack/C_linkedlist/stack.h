#ifndef _STACK_H_
#define _STACK_H_

typedef struct NODE{
    int val;
    struct NODE *next;
} node;

typedef struct STACK{
    int top;
    int maxsize;
    struct NODE* stack_top;
} stack;

void initialize(stack*, int);
void push(stack*, int);
void pop(stack*);
void top(stack*);
void display(stack*);
void check(stack*);
void empty(stack*);
void full(stack*);
void free_stack(stack*);

#endif