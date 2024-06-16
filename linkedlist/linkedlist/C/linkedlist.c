#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void initialize(linkedlist *ll)
{
    ll->head = (node*)malloc(sizeof(node));
    ll->head->val = 0;
    ll->head->next = NULL;
}

void append(linkedlist *ll, int n)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = n;
    new_node->next = NULL;

    if(!ll->head->next)
        ll->head->next = new_node;
    else
    {
        node *cur = ll->head->next;
        while(cur->next)
            cur = cur->next;
        cur->next = new_node;
    }
}

void insert(linkedlist *ll, int index, int n)
{
    int len = check(ll);
    if(index > len || index < 0)
    {
        printf("Error\n");
        return;
    }

    if(index == 0)
    {
        node *origin_node = ll->head->next;
        node *insert_node = (node*)malloc(sizeof(node));
        insert_node->val = n;
        insert_node->next = origin_node;
        ll->head->next = insert_node;
        return;
    }

    int count = 0;
    node *cur = ll->head->next;
    while(cur)
    {
        if(count == index - 1)
        {
            node *origin_node = cur->next;
            node *insert_node = (node*)malloc(sizeof(node));
            insert_node->val = n;
            insert_node->next = origin_node;
            cur->next = insert_node;
            break;
        }

        ++count;
        cur = cur->next;
    }
}

void display(linkedlist *ll)
{
    node *cur = ll->head->next;
    while(cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
}

void remove_node(linkedlist *ll, int index)
{
    int len = check(ll);
    if(index >= len || index < 0)
    {
        printf("Error\n");
        return;
    }

    if(index == 0)
    {
        ll->head->next = ll->head->next->next;
        return;
    }

    int count = 0;
    node *cur = ll->head->next;
    while(cur)
    {
        if(count == index - 1)
        {
            cur->next = cur->next->next;
            break;
        }

        ++count;
        cur = cur->next;
    }
}

int check(linkedlist *ll)
{
    int len = 0;
    if(ll->head->next)
    {
        node *cur = ll->head->next;
        while(cur)
        {
            ++len;
            cur = cur->next;
        }
    }

    return len;
}

void empty(linkedlist *ll)
{
    if(!ll->head->next)
        printf("True\n");
    else
        printf("False\n");
}

void find_middle(linkedlist *ll)
{
    if(!ll->head->next)
    {
        printf("Empty\n");
        return;
    }

    node *slow = ll->head->next;
    node *fast = ll->head->next;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("%d\n", slow->val);
}

void reverse(linkedlist *ll)
{
    if(!ll->head->next || !ll->head->next->next)
        return;
    
    node *cur = ll->head->next;
    node *next = NULL;
    node *prev = NULL;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    node *dummy = (node*)malloc(sizeof(node));
    dummy->val = 0;
    dummy->next = prev;
    ll->head = dummy;
}

void free_list(linkedlist *ll)
{
    node *temp;
    while(ll->head)
    {
        temp = ll->head;
        ll->head = ll->head->next;
        free(temp);
    }

    free(ll);
}