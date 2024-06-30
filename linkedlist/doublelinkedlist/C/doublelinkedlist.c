#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

void initialize(doublelinkedlist *dll)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = 0;
    new_node->next = NULL;
    new_node->prev = NULL;

    dll->head = new_node;
    dll->tail = new_node;
    dll->length = -1;
}

void append(doublelinkedlist *dll, int n)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = n;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(dll->length == -1)
    {
        dll->head = new_node;
        dll->tail = new_node;
    }
    else
        insert_tail(dll, n);

    dll->length += 1;
}

void insert(doublelinkedlist *dll, int index, int n)
{
    if(index > dll->length + 1 || index < 0)
    {
        printf("Error\n");
        return;
    }

    if(dll->length == -1)
    {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->next = NULL;
        new_node->prev = NULL;
        new_node->val = n;

        dll->head = new_node;
        dll->tail = new_node;
    }
    else if(index == 0)
        insert_head(dll, n);
    else if(index == dll->length + 1)
        insert_tail(dll, n);
    else
    {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->val = n;
        node *before_node = get_node(dll, index - 1);
        node *after_node = before_node->next;

        before_node->next = new_node;
        new_node->prev = before_node;
        new_node->next = after_node;
        after_node->prev = new_node;
    }

    dll->length += 1;
}

void insert_head(doublelinkedlist *dll, int n)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = n;
    new_node->prev = NULL;
    new_node->next = dll->head;

    dll->head->prev = new_node;
    dll->head = new_node;
}

void insert_tail(doublelinkedlist *dll, int n)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = n;
    new_node->next = NULL;
    new_node->prev = dll->tail;

    dll->tail->next = new_node;
    dll->tail = new_node;
}

void pop(doublelinkedlist *dll)
{
    if(dll->length == -1)
    {
        printf("Empty\n");
        return;
    }

    if(dll->length == 0)
    {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->val = 0;
        new_node->next = NULL;
        new_node->prev = NULL;

        dll->head = new_node;
        dll->tail = new_node;
    }
    else
    {
        node *pop_node = dll->tail;
        dll->tail = pop_node->prev;
        dll->tail->next = NULL;
        pop_node->prev = NULL;
    }

    dll->length -= 1;
}

node* get_node(doublelinkedlist *dll, int index)
{
    if(index > dll->length || index < 0)
    {
        printf("Error\n");
        return NULL;
    }

    int count;
    node *cur = (node*)malloc(sizeof(node));
    if(index <= (dll->length + 1) / 2)
    {
        count = 0;
        cur = dll->head;
        while(count != index)
        {
            cur = cur->next;
            ++count;
        }
    }
    else
    {
        count = dll->length;
        cur = dll->tail;
        while(count != index)
        {
            cur = cur->prev;
            --count;
        }
    }

    return cur;
}

void display(doublelinkedlist *dll)
{
    node *cur = (dll->length == -1) ? dll->head->next : dll->head;
    while(cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
}

void remove_node(doublelinkedlist *dll, int index)
{
    if(index >= dll->length + 1 || index < 0 || dll->length == -1)
    {
        printf("Error\n");
        return;
    }

    if(dll->length == 0 || index == dll->length)
    {
        pop(dll);
        return;
    }
    else if(index == 0)
    {
        node *remove_n = dll->head;
        dll->head = dll->head->next;
        remove_n->next = NULL;
        dll->head->prev = NULL;
    }
    else
    {
        node *remove_node = get_node(dll, index);

        remove_node->prev->next = remove_node->next;
        remove_node->next->prev = remove_node->prev;
        remove_node->next = NULL;
        remove_node->prev = NULL;
    }

    dll->length -= 1;
}

int check(doublelinkedlist *dll)
{
    return dll->length + 1;
}

int empty(doublelinkedlist *dll)
{
    return (dll->length == -1) ? 1 : 0;
}

int find_middle(doublelinkedlist *dll)
{
    if(dll->length == -1)
        return -1;

    node *slow = dll->head;
    node *fast = dll->head;

    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->val;
}

void reverse(doublelinkedlist *dll)
{
    if(dll->length == -1)
        return;
    
    dll->tail = dll->head;
    node *cur = dll->head;
    node *temp = (node*)malloc(sizeof(node));
    while(cur)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    if(temp)
        dll->head = temp->prev;
}

void free_list(doublelinkedlist *dll)
{
    node *temp;
    while(dll->head)
    {
        temp = dll->head;
        dll->head = dll->head->next;
        free(temp);
    }

    free(dll);
}