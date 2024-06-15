#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

#define PUSH    1
#define POP     2
#define DISPLAY 3
#define CHECK   4
#define EMPTY   5
#define FULL    6
#define UNKNOWN -1

typedef struct {
    char *key;
    int val;
} selections;

static selections register_selections[] = {
    {"PUSH"    , PUSH},
    {"POP"     , POP},
    {"DISPLAY" , DISPLAY},
    {"CHECK"   , CHECK},
    {"IS_EMPTY", EMPTY},
    {"IS_FULL" , FULL}
};

#define NUM_KEY (sizeof(register_selections)/sizeof(selections))

int keyfromstring(char *key)
{
    for(int i = 0; i < 6; ++i)
    {
        selections select = register_selections[i];
        if(!strcmp(select.key, key))
            return select.val;
    }

    return UNKNOWN;
}

int main(void)
{
    int num_cmd;
    scanf("%d", &num_cmd);

    int stack_maxsize;
    scanf("%d", &stack_maxsize);

    stack *s = (stack*)malloc(1 * sizeof(stack));
    initialize(s, stack_maxsize);

    char cmd[10];
    char temp;
    int n;
    for(int i = 0; i < num_cmd; ++i)
    {
        scanf("%s", cmd);
        switch(keyfromstring(cmd))
        {
            case PUSH:
                scanf("%d", &n);
                push(s, n);
                break;
            case POP:
                pop(s);
                break;
            case DISPLAY:
                display(s);
                break;
            case CHECK:
                check(s);
                break;
            case EMPTY:
                empty(s);
                break;
            case FULL:
                full(s);
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }

    free_stack(s);

    return 0;
}