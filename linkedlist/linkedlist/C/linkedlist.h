typedef struct NODE {
    int val;
    struct NODE *next;
} node;

typedef struct LINKEDLIST
{
    struct NODE *head;
} linkedlist;

void initialize(linkedlist*);
void append(linkedlist*, int);
void insert(linkedlist*, int, int);
void display(linkedlist*);
void remove_node(linkedlist*, int);
int check(linkedlist*);
void empty(linkedlist*);
void find_middle(linkedlist*);
void reverse(linkedlist*);
void free_list(linkedlist*);