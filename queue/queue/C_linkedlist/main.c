#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define PUSH    1
#define POP     2
#define FRONT   3
#define DISPLAY 4
#define CHECK   5
#define EMPTY   6
#define FULL    7
#define UNKNOWN -1

typedef struct SELECTIONS{
    char *key;
    int val;
} selections;

static selections register_selections[] = {
    {"PUSH"      , PUSH},
    {"POP"       , POP},
    {"GET_FRONT" , FRONT},
    {"DISPLAY"   , DISPLAY},
    {"CHECK"     , CHECK},
    {"IS_EMPTY"  , EMPTY},
    {"IS_FULL"   , FULL}
};

#define NUM_KEY (sizeof(register_selections)/sizeof(selections))

int keyfromstring(char *key)
{
    for(int i = 0; i < NUM_KEY; ++i)
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

    int queue_maxsize;
    scanf("%d", &queue_maxsize);

    queue *q = (queue*)malloc(1 * sizeof(queue));
    initialize(q, queue_maxsize);

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
                push(q, n);
                break;
            case POP:
                pop(q);
                break;
            case FRONT:
                front(q);
                break;
            case DISPLAY:
                display(q);
                break;
            case CHECK:
                check(q);
                break;
            case EMPTY:
                empty(q);
                break;
            case FULL:
                full(q);
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }

    free_queue(q);

    return 0;
}