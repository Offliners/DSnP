typedef struct NODE{
    int val;
    struct NODE *next;
} node;

typedef struct QUEUE{
    int front;
    int maxsize;
    struct NODE* queue_front;
} queue;

void initialize(queue*, int);
void push(queue*, int);
void pop(queue*);
void front(queue*);
void display(queue*);
void check(queue*);
void empty(queue*);
void full(queue*);
void free_queue(queue*);