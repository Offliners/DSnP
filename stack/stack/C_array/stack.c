#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void initialize(stack *s, int maxsize)
{
    s->top = -1;
    s->maxsize = maxsize;
    s->data = (int*)malloc(maxsize * sizeof(int));
    for(int i = 0; i < maxsize; ++i)
        s->data[i] = 0;
}

void push(stack *s, int n)
{
    if(s->top + 1 < s->maxsize)
    {
        s->top += 1;
        s->data[s->top] = n;
    }
    else
        printf("Full\n");
}

void pop(stack *s)
{
    if(s->top != -1)
    {
        s->data[s->top] = 0;
        s->top -= 1; 
    }
    else
        printf("Empty\n");
}

void top(stack *s)
{
    if(s->top != -1)
        printf("%d", s->data[s->top]);
    printf("\n");
}

void display(stack *s)
{
    if(s->top != -1)
        for(int i = 0; i <= s->top; ++i)
            printf("%d ", s->data[i]);
    printf("\n");
}

void check(stack *s)
{
    printf("%d\n", s->top + 1);
}

void empty(stack *s)
{
    if(s->top == -1)
        printf("True\n");
    else
        printf("False\n");
}

void full(stack *s)
{
    if(s->top + 1 >= s->maxsize)
        printf("True\n");
    else
        printf("False\n");
}

void free_stack(stack *s)
{
    free(s->data);
    free(s);
}