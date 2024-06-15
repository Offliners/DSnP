#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void initialize(stack *s, int maxsize)
{
    s->top = -1;
    s->maxsize = maxsize;

    s->stack_top = (node*)malloc(sizeof(node));
    s->stack_top->next = NULL;
}

void push(stack *s, int n)
{
    if(s->top + 1 < s->maxsize)
    {
        s->top += 1;
        node *head = (node*)malloc(sizeof(node));
        head->val = n;
        head->next = s->stack_top;
        s->stack_top = head;
    }
    else
        printf("Full\n");
}

void pop(stack *s)
{
    if(s->top != -1)
    {
        s->stack_top = s->stack_top->next;
        s->top -= 1; 
    }
    else
        printf("Empty\n");
}

void display(stack *s)
{
    if(s->top != -1)
    {
        int *data = (int*)malloc((s->top + 1) * sizeof(int));
        for(int i = 0; i < s->top; ++i)
            data[i] = 0;
        
        int index = s->top;
        node *cur = s->stack_top;
        while(cur->next)
        {
            data[index] = cur->val;
            cur = cur->next;
            --index;
        }

        for(int i = 0; i < s->top + 1; ++i)
            printf("%d ", data[i]);
        
        free(data);
    }
    
    printf("\n");
}

void check(stack *s)
{
    int len = 0;
    node *cur = s->stack_top;
    while(cur->next)
    {
        ++len;
        cur = cur->next;
    }
    printf("%d\n", len);
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
    node *temp;
    while(s->stack_top)
    {
        temp = s->stack_top;
        s->stack_top = s->stack_top->next;
        free(temp);
    }
    free(s);
}