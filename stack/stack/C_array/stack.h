typedef struct  STACK{
    int top;
    int maxsize;
    int *data;
} stack;

void initialize(stack*, int);
void push(stack*, int);
void pop(stack*);
void display(stack*);
void check(stack*);
void empty(stack*);
void full(stack*);
void free_stack(stack*);