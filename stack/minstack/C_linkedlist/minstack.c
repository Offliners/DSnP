#include <stdio.h>
#include <stdlib.h>
#include "minstack.h"

void initialize(minstack *min_s, int maxsize)
{
    min_s->data_s = (stack*)malloc(sizeof(stack));
    min_s->mindata_s = (stack*)malloc(sizeof(stack));

    min_s->data_s->top = -1;
    min_s->data_s->maxsize = maxsize;
    min_s->mindata_s->top = -1;
    min_s->mindata_s->maxsize = maxsize;

    min_s->data_s->stack_top = (node*)malloc(sizeof(node));
    min_s->data_s->stack_top->next = NULL;
    min_s->mindata_s->stack_top = (node*)malloc(sizeof(node));
    min_s->mindata_s->stack_top->next = NULL;
}

void push(minstack *min_s, int n)
{
    if(min_s->data_s->top + 1 < min_s->data_s->maxsize)
    {
        min_s->data_s->top += 1;
        node *head = (node*)malloc(sizeof(node));
        head->val = n;
        head->next = min_s->data_s->stack_top;
        min_s->data_s->stack_top = head;

        min_s->mindata_s->top += 1;
        node *head_min = (node*)malloc(sizeof(node));
        if(min_s->mindata_s->top == 0 || n < min_s->mindata_s->stack_top->val) 
            head_min->val = n;
        else
            head_min->val = min_s->mindata_s->stack_top->val;

        head_min->next = min_s->mindata_s->stack_top;
        min_s->mindata_s->stack_top = head_min;
    }
    else
        printf("Full\n");
}

void pop(minstack *min_s)
{
    if(min_s->data_s->top != -1)
    {
        min_s->data_s->stack_top = min_s->data_s->stack_top->next;
        min_s->data_s->top -= 1;
        min_s->mindata_s->stack_top = min_s->mindata_s->stack_top->next;
        min_s->mindata_s->top -= 1;
    }
    else
        printf("Empty\n");
}

void top(minstack *min_s)
{
    if(min_s->data_s->top != -1)
        printf("%d", min_s->data_s->stack_top->val);
    printf("\n");
}

void display(minstack *min_s)
{
    if(min_s->data_s->top != -1)
    {
        int *data = (int*)malloc((min_s->data_s->top + 1) * sizeof(int));
        for(int i = 0; i <= min_s->data_s->top; ++i)
            data[i] = 0;
        
        int index = min_s->data_s->top;
        node *cur = min_s->data_s->stack_top;
        while(cur->next)
        {
            data[index] = cur->val;
            cur = cur->next;
            --index;
        }

        for(int i = 0; i <= min_s->data_s->top; ++i)
            printf("%d ", data[i]);
        
        free(data);
    }
    
    printf("\n");
}

void check(minstack *min_s)
{
    int len = 0;
    node *cur = min_s->data_s->stack_top;
    while(cur->next)
    {
        ++len;
        cur = cur->next;
    }
    printf("%d\n", len);
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
        printf("%d\n", min_s->mindata_s->stack_top->val);
    else
        printf("Empty\n");
}

void free_stack(minstack *min_s)
{
    node *temp;
    while(min_s->data_s->stack_top)
    {
        temp = min_s->data_s->stack_top;
        min_s->data_s->stack_top = min_s->data_s->stack_top->next;
        free(temp);
    }

    while(min_s->mindata_s->stack_top)
    {
        temp = min_s->mindata_s->stack_top;
        min_s->mindata_s->stack_top = min_s->mindata_s->stack_top->next;
        free(temp);
    }

    free(min_s->data_s);
    free(min_s->mindata_s);
    free(min_s);
}