#include <stdio.h>
#include <stdlib.h>
#include "minstack.h"

void initialize(minstack *min_s, int maxsize)
{
    min_s->data_s = (stack*)malloc(sizeof(stack));
    min_s->mindata_s = (stack*)malloc(sizeof(stack));
    min_s->data_s->top = -1;
    min_s->mindata_s->top = -1;
    min_s->data_s->maxsize = maxsize;
    min_s->mindata_s->maxsize = maxsize;
    min_s->data_s->data = (int*)malloc(maxsize * sizeof(int));
    min_s->mindata_s->data = (int*)malloc(maxsize * sizeof(int));
    for(int i = 0; i < maxsize; ++i)
    {
        min_s->data_s->data[i] = 0;
        min_s->mindata_s->data[i] = 0;
    }
}

void push(minstack *min_s, int n)
{
    if(min_s->data_s->top + 1 < min_s->data_s->maxsize)
    {
        min_s->data_s->top += 1;
        min_s->data_s->data[min_s->data_s->top] = n;

        min_s->mindata_s->top += 1;
        if(min_s->mindata_s->top == 0 || n < min_s->mindata_s->data[min_s->mindata_s->top - 1])
            min_s->mindata_s->data[min_s->mindata_s->top] = n;
        else
            min_s->mindata_s->data[min_s->mindata_s->top] = min_s->mindata_s->data[min_s->mindata_s->top - 1];
    }
    else
        printf("Full\n");
}

void pop(minstack *min_s)
{
    if(min_s->data_s->top != -1)
    {
        min_s->data_s->data[min_s->data_s->top] = 0;
        min_s->data_s->top -= 1;
        min_s->mindata_s->data[min_s->mindata_s->top] = 0;
        min_s->mindata_s->top -= 1;
    }
    else
        printf("Empty\n");
}

void top(minstack *min_s)
{
    if(min_s->data_s->top != -1)
        printf("%d", min_s->data_s->data[min_s->data_s->top]);
    printf("\n");
}

void display(minstack *min_s)
{
    if(min_s->data_s->top != -1)
        for(int i = 0; i <= min_s->data_s->top; ++i)
            printf("%d ", min_s->data_s->data[i]);
    printf("\n");
}

void check(minstack *min_s)
{
    printf("%d\n", min_s->data_s->top + 1);
}

void empty(minstack *min_s)
{
    if(min_s->data_s->top == -1)
        printf("True\n");
    else
        printf("False\n");
}

void full(minstack *min_s)
{
    if(min_s->data_s->top + 1 >= min_s->data_s->maxsize)
        printf("True\n");
    else
        printf("False\n");
}

void get_min(minstack *min_s)
{
    if(min_s->mindata_s->top != -1)
        printf("%d\n", min_s->mindata_s->data[min_s->mindata_s->top]);
    else
        printf("Empty\n");
}

void free_stack(minstack *min_s)
{
    free(min_s->data_s->data);
    free(min_s->data_s);
    free(min_s->mindata_s->data);
    free(min_s->mindata_s);
    free(min_s);
}