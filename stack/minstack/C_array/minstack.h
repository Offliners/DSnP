#ifndef _MINSTACK_H_
#define _MINSTACK_H_

typedef struct STACK {
    int top;
    int maxsize;
    int *data;
} stack;

typedef struct MINSTACK {
    stack *data_s;
    stack *mindata_s;
} minstack;

void initialize(minstack*, int);
void push(minstack*, int);
void pop(minstack*);
void top(minstack*);
void display(minstack*);
void check(minstack*);
void empty(minstack*);
void full(minstack*);
void get_min(minstack*);
void free_stack(minstack*);

#endif