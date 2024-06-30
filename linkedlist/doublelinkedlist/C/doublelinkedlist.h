#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

typedef struct NODE {
    int val;
    struct NODE *next;
    struct NODE *prev;
} node;

typedef struct DOUBLELINKEDLIST
{
    int length;
    struct NODE *head;
    struct NODE *tail;
} doublelinkedlist;

void initialize(doublelinkedlist*);
void append(doublelinkedlist*, int);
void insert(doublelinkedlist*, int, int);
void insert_head(doublelinkedlist*, int);
void insert_tail(doublelinkedlist*, int);
void pop(doublelinkedlist*);
node* get_node(doublelinkedlist*, int);
void display(doublelinkedlist*);
void remove_node(doublelinkedlist*, int);
int check(doublelinkedlist*);
int empty(doublelinkedlist*);
int find_middle(doublelinkedlist*);
void reverse(doublelinkedlist*);
void free_list(doublelinkedlist*);

#endif