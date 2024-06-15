typedef struct QUEUE{
    int front;
    int maxsize;
    int *data;
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